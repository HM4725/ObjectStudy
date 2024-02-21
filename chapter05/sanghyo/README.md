# Chapter05: 책임 할당하기

## 1. 책 내용 및 인사이트
> - 01 책임 주도 설계를 향해 (p.134~136)
> - 02 책임 할당을 위한 GRASP 패턴 (p.137~145)
> - 03 구현을 통한 검증 (p.146~165)
> - 04 책임 주도 설계의 대안 (p.166~174)

### 인사이트
- 객체는 메세지 수신자에게 메시지 송신만 할 뿐 수신자에 대한 세부 정보를 알지못해도 된다. (**캡슐화**)
- **도메인 구조**에 따라 구현이 변하기도 하고, 그 반대이기도 하다. 코드를 작성하기 전에 도메인 구조를 작성해보고 그에 따라 객체들을 설계해보자.
- 객체는 자신이 소유하고 있는 정보와 관련된 작업을 수행해야한다. **정보**란 저장하고 있는 데이터 뿐만 아니라 해당 정보를 제공할 수 있는 다른 객체를 포함한다.
- 동일한 기능을 구현하는 무수히 많은 설계중에서 트레이드 오프를 따져보며 **높은 응집도와 낮은 결합도**를 유지할 수 있는 설계를 채택하자.
- 객체가 변경될 여지가 있는 이유들을 생각해보고 이에 따라 분리하여 변경에 취약하지 않은 객체를 만들자. (변경의 이유에 따라 클래스 분리)
  > 1. 인스턴스 변수가 초기화 되는 시점을 살펴보라 (가능한 인스턴스 변수가 동시에 초기화 되는 단위를 찾아 분리하자)
  > 2. 메서드들이 인스턴스 변수를 사용하는 방식을 살펴보라 (메서드들이 사용하는 속성에 따라 그룹이 나뉜다면 클래스의 응집도가 낮으니 분리하자)

### 책임 주도 설계의 과정
1. 메세지를 전송할 객체의 의도 파악 ("메세지를 전송할 객체는 무엇을 원하는가?")
2. 메세지를 수신할 적합한 객체 파악 (메세지를 수행하는데 필요한 정보를 가장 많이 알고 있는 객체)
3. 메세지를 수신한 객체가 외부 인터페이스가 아니라 내부로 들어가 메세지를 처리하기 위해 필요한 절차를 고민 (스스로 처리할 수 있는 작업과 다른 객체의 도움이 필요한 작업을 구분)

<img width="736" alt="image" src="https://github.com/HM4725/ObjectStudy/assets/26588989/9ed2e2d9-85ae-4617-93f4-94173cde6fd7">


## 2. 코드 구현으로 비교해보기
### 설계가 아래처럼 바뀌는 경우 문제점 (가능한 설계는 많기에 응집도와 결합도를 기준으로 trade-off를 따져보자)
<img width="646" alt="image" src="https://github.com/HM4725/ObjectStudy/assets/26588989/2ae0c9a5-db8a-4205-9b01-fbc745d2feaa"><br/>
**높은 응집도를 유지하지 못함**
변경된 설계에 따라 아래와 같이 코드가 바뀐다.
```swift
// 가격을 계산하라 메시지에 응답
struct Movie {
    // property 생략
    
    // 계산하라 메시지
    func calculateMovieFee(isDiscountable: Bool) -> Double {
        if isDiscountable {
            return fee - calculateDiscountAmount()
        }
        return fee
    }
}

// 예매하라 메시지에 응답
struct Screening {
    // 나머지 property 생략
    private var discountConditions: [DiscountCondition]

    // 나머지 메소드 생략
    private func calculateFee(audienceCount: Int) -> Double {
        // movie 객체에게 "계산하라" 메시지 전달
        return movie.calculateMovieFee(isDiscountable: isDiscountable(screening: self)) * Double(audienceCount)
    }
    
    // Movie의 "계산하라" 책임에 영향을 주는 코드
    private func isDiscountable(screening: Screening) -> Bool {
        for condition in discountConditions {
            if condition.isSatisfiedBy(screening: self) {
                return true
            }
        }
        return false
    }
}
```
이 때 예매 요금을 계산하는 방식이 변경되는 경우를 가정해보자.
discount condition이 period type에 일치하는 경우 50%, 아닌 경우 10%, sequence type에 일치하는 경우 70%, 아닌 경우 10% 추가 할인하는 정책으로 바뀌었다고 가정하자. (코드 작성을 위한 어거지 상황 ...)<br/>
코드상에서 변경되는 지점을 확인해보면 아래와 같다
```swift
// 가격을 계산하라 메시지에 응답
struct Movie {
    
    // 계산하라 메시지
    func calculateMovieFee(discountType: DiscountType) -> Double {
        var fee = fee - calculateDiscountAmount()
        return fee * Double(discountType.percent())
    }
}

struct Screening {
  private func calculateFee(audienceCount: Int) -> Double {
        // movie 객체에게 "계산하라" 메시지 전달
        return movie.calculateMovieFee(discountType: getDiscountType(screening: self)) * Double(audienceCount)
    }
    
    // Movie의 "계산하라" 책임에 영향을 주는 코드
    private func getDiscountType(screening: Screening) -> DiscountType {
        var discountType: DiscountType = .ten
        for condition in discountConditions {
            discountType = getBetterDiscountType(discountType, condition.getDiscountPercent(screening: self))
        }
        return discountType
    }
    
    private func getBetterDiscountType(_ type1: DiscountType, _ type2: DiscountType) -> DiscountType {
        return type1.rawValue > type2.rawValue ? type1 : type2
    }
}
```
기존의 설계대로 했다면 DiscountCondition, Movie 객체에서 변경만 발생하고 Screening에서의 변경은 발생하지 않았겠지만 새로운 설계에서는 예매 요금 계산 방식에서의 변화로 인해 세개의 객체 모든 코드에서 변경이 발생하였다.
즉, Screening이 서로 다른 이유로 변경되는 책임을 짊어지게 되고 이는 높은 응집도를 유지하지 못한다는 뜻이다.

### 그럼에도 높은 결합도를 다형성을 이용하여 낮춰보자

## 3. 한 줄 느낀점
객체 지향을 가장한 절차 지향에서 탈피하기 위한 노력. <br/>
<**책임 주도 설계**>와 <**변경의 이유에 따른 클래스 분리**> 각각에 대한 많은 시도와 실패가 필요로하다.

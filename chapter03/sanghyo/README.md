# Chapter03: 역할, 책임, 협력

## 1. 책 내용 분석 및 인사이트
> - 01 협력 (p.74~77)
> - 02 책임 (p.78~85)
> - 03 역할 (p.86~96)

- 협력: 객체들이 어플리케이션 기능을 구현하기 위해 수행하는 상호작용
- 책임: 객체가 협력에 참여하기 위해 수행하는 로직
- 역할: 객체들이 협력 안에서 수행하는 책임들이 모여 구성하는 것

### 협력
> 1. 메시지 전송을 통해 객체 사이의 협력을 위한 커뮤니케이션을 할 수 있다.<br/>
> 2. 메시지 전송은 로직을 수행할 때 적절한 객체에게 이를 위임하여 결합도를 낮추고, 자율성을 보장할 수 있다.<br/>
> 3. 메시지를 수신한 객체들은 메서드로 응답하며 세부 구현은 객체 스스로가 결정하고 담당한다.

<img width="500" alt="image" src="https://github.com/HM4725/ObjectStudy/assets/26588989/b815d811-8d4e-4e31-b6dc-1e52bc7ada02">

### 책임
> 책임은 '**하는것(doing)**'과 '**아는것(knowing)**'으로 나뉜다.<br/>
> 이를 통해 외부 인터페이스와 내부 속성(도와줄 객체와 필요 정보)를 결정한다.<br/>
> Screening: 하는 것(영화 예매) / 아는 것(상영하는 영화)
> Movie: 하는 것(예매 가격 계산) / 아는 것(가격과 할인 정책 종류)

> 책임 할당할 때 고려사항
> - 메시지가 객체를 결정한다
> - 행동이 상태를 결정한다

**메시지가 객체를 결정한다는 것이 중요한 이유<br/>**
1. 메시지를 포함하는 최소한의 인터페이스를 가지는 객체를 가질 수 있게된다.
2. how가 아닌 what만을 포함하는 추상적인 인터페이스를 가질 수 있게된다.

**행동이 상태를 결정한다는 것<br/>**
1. 객체를 객체답게 만드는 것은 상태가 아니라 객체가 다른 객체에게 제공하는 **행동**이다.<br/>
2. 협력 관계 속에서 다른 객체에게 무엇을 제공해야하고, 무엇을 얻어야 하는지 고민하는 과정을 통해 **행동**에 대해서만 퍼블릭 인터페이스로 구현가능하고 이는 **캡슐화**를 이끌어낸다

### 역할
**역할은 무대 위의 배역과도 같아 여러명의 배우(객체)들이 하나의 역할을 수행할 수 있다.**
> 역할에 책임을 할당하는 과정
> 1. 적절한 역할 찾기
> 2. 역할을 수행할 객체로 인스턴스 정하기

> 역할(객체의 추상화)의 장점
> 1. 세부사항을 신경쓰지 않고 상위의 정책을 쉽고 간단히 표현할 수 있다.
> 2. 기존의 코드를 수정하지 않고 적절한 행동을 가져올 수 있기에 설계에 유연하다

## 2. 객체보다는 역할에 먼저 초점을 맞춰라 with Swift
### Movie 객체가 할인 정책 역할이 아닌 개별 객체에 초점을 맞춘 경우
```swift
struct Movie {
  private let fee: Int = 5000

  func calculateFee() {
    // 변경 예정 지점
    self.fee -= AmountDiscountPolicy().getDiscountAmount()
  }
}
```
**정책에 변경이 생긴 경우 아래와 같이 상위 로직 코드 변경이 불가피**
```swift
struct Movie {
  private let fee: Int = 5000

  func calculateFee() {
    // 변경 지점
    self.fee = self.fee - self.fee * PercentDiscountPolicy().getDiscountPercent()
  }
}
```
### Movie 객체가 할인 정책 역할에 초점을 맞춘 경우

```swift
struct Movie {
  private let fee: Int = 5000
  // 변경 예정 지점
  private let discountPolicy: DiscountPolicy = AmountDiscountPolicy

  func calculateFee() {
    // 변경 예정 지점
    self.fee -= discountPolicy.getDiscountAmount()
  }
}

protocol DiscountPoclity {
  func getDiscountAmount()
}
```
**정책에 변경이 생긴 경우 아래와 같이 역할을 수행하는 객체만 변경해주면 됨**
```swift
struct Movie {
  private let fee: Int = 5000
  // 변경 지점
  private let discountPolicy: DiscountPolicy = PercentDiscountPolicy

  func calculateFee() {
    // 변경 지점
    self.fee -= discountPolicy.getDiscountAmount()
  }
}
```

## 3. 한 줄 느낀점
시스템을 설계할 때 **메시지**를 결정하고, 메시지를 처리할 **책임**을 지닌 **역할**을 선택하고, 그 역할을 수행할 적절한 **객체**를 할당하자

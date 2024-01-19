# Chapter02: 객체지향 프로그래밍

## 1. 책 내용 분석 및 인사이트
> - 01 영화 예매 시스템 (p.37~40)
> - 02 객체지향 프로그래밍을 향해 (p.40~49)
> - 03 할인 요금 구하기 (p.49~56)
> - 04 상속과 다형성 (p.57~65)
> - 05 추상화와 유연성 (p.65~72)

도메인 개념 기반의 클래스 구조<br/>
<img width="712" alt="image" src="https://github.com/HM4725/ObjectStudy/assets/26588989/3dcfa385-29d2-43f0-a354-7eba14fd97d0">

**객체 지향 생각해볼 것**
- 객체는 데이터와 기능을 함께 묶어 캡슐화 하는 존재다
- 인터페이스와 구현부(implement)를 구분하기 위해 접근 수정자(access modifier)를 제공하라.
- 구체 클래스에 의존하는 것이 아닌, 추상 클래스에 의존하여 의존성을 낮춰라.
  - 코드를 이해하기는 어려워질 수 있지만 유연해지고 확장가능한 코드를 관리할 수 있다.
  - 유연성과 가독성 사이의 trade-off
- 다형성을 이용하여 컴파일 시간 의존성과 실행 시간 의존성이 다른 기능을 구현할 수 있다.
  - 동일한 인터페이스를 사용하는 객체들이 동일한 메시지를 수신하여 각자의 타입에 따라 다르게 응답할 수 있도록 구현
- 상속과 합성 사이의 trade-off를 생각해보고 선택하라
  - 상속은 부모 클래스와 자식 클래스의 결합도를 높여 캡슐화가 약화된다. 

## 2. 코드 작성 with Swift

### 문제점
- Java로 쓰여진 코드를 Swift로 바꾸는 과정에서 언어들이 저마다 일대일 매칭되는 것이 아니므로 똑같이 할 수 없는 것이 있었다.
- Java의 추상클래스(abstact class)에 해당하는 것을 Swift에서 찾을 수 없었고 나만의 방식으로 추상화된 객체를 만들 수 밖에 없었다.
- 이와 같은 코드 디자인패턴을 템플릿 메소드 패턴이라고 한다.
- 템플릿 메소드 패턴: 부모 클래스에 기본적인 알고리즘의 흐름을 구현하고 중간에 필요한 처리를 자식 클래스에게 위임

```java
public abstract class DiscountPolicy {
  // 생략

  // 재정의 불가능한 template method 부분
  public Money calculateDiscountAmount(Screening screening) {
    // 생략
  }

  // 문제가 되는 abstract method
  // 재정의 해야하는 method
  abstract protected Money getDiscountAmount(Screening Screening);
}
```

### 해결 방법

**유사한 추상화 계층 만들기**
  - 자바의 추상메서드 abstract protected와 같은 역할을 만들기 위해 protocol을 만들어 채택
  - 추상 메서드는 또한 외부에서는 접근이 불가능한 상태여야 하기 때문에 protocol을 private으로 선언
  - calculateDiscountAmount 함수에 대해서는 외부에서 접근 가능해야하기에 DiscountPolicy에서 구현한 뒤 implement class들에서 DiscountPolicy를 상속하도록 구현
  - DiscountPolicy를 이용하여 직접 객체를 생성하지 못하도록, 하지만 DiscountPolicy Implement에서는 사용할 수 있도록 fileprivate 선언

```swift
private protocol AbstractDiscountPolicy {
    func getDiscountAmount(screening: Screening) -> Money
}

class DiscountPolicy: AbstractDiscountPolicy {
    private let conditions: [DiscountCondition]
    
    fileprivate init(conditions: [DiscountCondition]) {
        self.conditions = conditions
    }

    // final 키워드를 이용하여 메서드가 더이상 상속이 되지 않음을 명시하고, Static Dispatch를 통해 런타임 시간을 향상시킬 수 있음
    // reference: WWDC16 Understanding Swift Performance
    final func calculateDiscountAmount(screening: Screening) -> Money {
        for condition in conditions {
            if(condition.isSatisfiedBy(screening: screening)) {
                return getDiscountAmount(screening: screening)
            }
        }
        return Money.ZERO
    }
    
    fileprivate func getDiscountAmount(screening: Screening) -> Money { return Money.ZERO }
}

class AmountDiscountPolicy: DiscountPolicy {
    private let discountAmount: Money
    
    init(discountAmount: Money, discountCondition: [DiscountCondition]) {
        self.discountAmount = discountAmount
        super.init(conditions: discountCondition)
    }
    
    fileprivate override func getDiscountAmount(screening: Screening) -> Money {
        return discountAmount
    }
}
```

나는 템플릿 메소드 패턴을 위와같이 구현했지만 [링크](https://icksw.tistory.com/260) 에서처럼 구현하는 방법도 괜찮다고 생각한다.

## 3. 한 줄 느낀점
추상화를 이용하여 객체들의 결합도를 낮추는것은 미래에 유지보수를 하는 나를 위한 대비책으로 훌륭하다 !

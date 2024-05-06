객체 지향 설계에서, 객체간 협력은 필수적이나 과도하게 많은 협력은 추후 변경을 어렵게 한다. 

객체간의 협력은 객체간 정보를 가지고 있어야 하며, 이는 의존성이라고 부른다. 

잘못된 의존성은 유연한 설계를 방해하는 요소이다.

## 1. 의존성의 이해

- 의존성 전이
    - 캡슐화 여부에 따라 의존성이 전이된다.
        - ex. PeriodCondition → Screening → Movie으로 의존성 구조
        - 이때, Screening이 캡슐화를 올바르게 처리하지 않으면 PeriodCondition은 Move에 의존하는 구조를 가질 가능성이 매우 높음
- 의존성 해결 방법
    1. 객체 생성 시점에 생성자에 의존성 주입
    2. 객체 생성후 의존성 주입
    
    → 생성 시점 주입과 생성 후 주입의 차이는 생성자에 주입하느냐,  `setter` 함수를 통해 주입하느냐의 차이 
    
    생성자 시점 주입의 단점은 실행 시점에 의존성 대상을 변경할 수 없으며, 생성후 주입의 단점은 주입전까지 시스템 상태가 불완전하다는 것이다.
    
    이 둘의 단점을 해결하는 방식이 바로 생성자에 Empty객체를 주입하고, `setter` 를 통해 수정하는 방식
    
    ```swift
    public class Movie {
       
       public init(moviePolicy: MoivePolicy) {
           self.moviePolicy = moviePolicy
       }
       
       public setPolicy(movePolicy: MoviePolicy) {
           self.movePolicy = movePolicy 
       }
       
       private var movePolicy: MoviePolicy
    
    }
    
    let avatar = Movie(moviePolicy: EmptyPolicy)
    avatar.setPolicy(moviePolicy: PercentDiscountPolicy)
    ```
    
    1. 메서드 실행시, 인자를 통해 의존성 해결
        - 메서드에서만 해당 의존성을 일회성으로 사용하는 케이스에서 사용
        
        ```swift
        public protocol DiscountPolicy {
           func discount(fee: Int)
        }
        
        func calculate(fee: Int, discountPolicy: DiscountPolicy) -> Int {
            return fee - discountPolicy.discount(fee: fee)
        }
        ```
        

## 2. 유연한 설계

객체 지향 설계의 핵심은 협력이므로, 의존성은 피할수 없는 사항이다. 의존성이 바람직한 경우 약한 결합도(Coupling), 바람직하지 않은 경우 강한 결합도라고 말한다. 

결합도가 강하다는 것은, 의존하는 요소에 대해 얼마나 많이 아느냐로 결정된다. 한 객체가 다른 객체의 정보를 많이 알면 알수록 결합도가 강하다는 것을 의미하며, 이는 추후에 변경이 어려워진다.

문제점을 해결하기 위해 필요한 정보외엔 최대한 감추는 방법인 **추상화를 통해 해결한다.** 

## 3. 추상화에 의존하기

### 명시적인 의존성 사용

- 생성자에서 구체 클래스의 인스턴스를 생성하는 경우, 의존성이 숨겨져있어 내부 구현을 통해 의존성을 알아내야 한다.
- 생성자의 인자로 전달받거나, setter를 사용하는 경우 의존성을 퍼블릭 인터페이스로 드러내기에 명시적으로 노출된다.

### 컨텍스트 확장

- 의존성을 주입받는 경우의 문제점은, 해당 객체 사용시 `Null`(Swift에선 `Opitonal` ) 체크가 필요

```swift
public class Movie {

    private var discountPolicy: DiscountPolicy? 
    
    func reserve() -> Bool {
        guard let discountPolicy = discountPolicy else {
            return false 
        }
    }

}
```

- 이를 해결 하기 위해 `Empty` 객체를 사용

```swift
let movie = Movie(discountPolicy: EmptyPolicy())

public class Movie {

    private var discountPolicy: DiscountPolicy
    
    public init(discountPolicy: DiscountPolicy) {
        self.discountPolicy = discountPolicy 
    }

}
```

### 조합 가능한 행동

- `Movie` 객체가 `Policy` 에 의존하게 되면, 우리는 어떤 객체와의 협력에 따라 유연하게 대응 가능(ex. 할인 정책이 2000원 할인이라면 `AmountDiscountPolicy` 를, 정책이 10% 할인이라면 `PercentDiscountPolicy` 를 사용하면 된다)
- 결국, 객체가 어떻게 동작하는지(How)에 집중하지 않고 무엇을 하는지(What)를 표현하는 객체들로만 구성된다.

## 결론

- 객체 지향에서 의존성은 강한 결합도와 약한 결합도로 나뉨
- 약한 결합도로 바꿀수 있는 요소인 추상화를 사용
- 추상화를 통해서, 다양한 객체간의 협력을 통해 보다 유연하게 대응 가능(객체의 변경대신 실행 시점에 다른 객체로 변경한다)
- 의존성 주입시에, null 체크를 하지 않기 위해 Empty 객체를 사용할 수 있음

밑의 내용은 “오브젝트” 도서를 읽고 **본인이 이해한 내용을 정리**한 글입니다. 실제 내용과 다를 수 있습니다. 

- 책임 주도 설계만으로, 객체의 퍼블릭 인터페이스의 퀄리티를 얻기에는 부족
- 도움되는 설계 원칙들을 익히기 위한 챕터, 하지만 원칙이라는 것은 예외가 존재하기에 때에 따라서는 버릴줄도 알아야 한다.

## 1. 협력과 메세지

### 메세지

- 객체간 협력을 담당(ex. A객체가, B객체에게 ~ 행동을 요청)
- 이상적인 객체의 경우, 한가지 책임을 갖고 있기에 **더 큰 책임을 위해선 반드시 협력이 필요**

## 2. 인터페이스와 설계 품질

### 좋은 인터페이스란?

- 추상적 인터페이스와, 최소한의 인터페이스를 만족
- 추상적 인터페이스는 “**무엇을**” 하는지에 **초점을** 맞춰야 함, “**어떻게”가 아닌**
    - ex. 어떤 동작에 대한 판단을 담당하는 객체 `Condition`
        
        ```swift
        public protocol Condition {
             public func isSatisfied(value: Value) -> Bool // OK
             public func isSatisfiedByDate(value: Value) -> Bool // No, 인터페이스에 "어떻게"가 들어간 케이스 
        }
        ```
        
        - 위와 같이, 만족 여부만을 담당하는 객체에서 만족의 조건이 들어갈 이유가 없음

### 인터페이스에 의도

- 인터페이스에는 클라이언트의 의도가 담겨야 함
- ex. 고객이 마트에 물건을 사는 프로그램

```swift
public class Person {
    public func setGroceries(_ groceries: Groceries) // 의도가 X
    public func buy(groceries: Groceries) // 물건을 산다는 의도가 담겨있는 인터페이스
}

```

- `setGroceries` 의 경우, 함수에 어떤 의도가 담긴지 알수 없음
- 코드 작성자 외에는, 해당 함수의 의도를 이해할 수 없기에 인터페이스에는 의도가 담겨있어야 함

## 3. 원칙의 함정

### 캡슐화, 응집도, 결합도

- 캡슐화는 굉장히 중요한 요소, 하지만 무조건적으로 해당 원칙을 지키려다 응집도가 떨어지고 결합도가 증가하는 부작용이 발생하는 경우또한 존재

```swift
public class PeriodCondition: Condition {
    public func isSatisfied(screening: Screening) {
        screen.day
        screen.startTime
        screen.year 
        // ... 위와 같은 변수를 사용해서 처리
    }
}
```

- `Screening`에 변수들이 캡슐화 되지 못해, 외부에 드러나는 형태
- 하지만, 이들을 캡슐화했을경우, `Screening`이 `PeriodCondition` 이 가진 책임을 떠안게 됨
- 결과적으로, 응집도가 떨어지고 `Screening` 과 `PeriodCondition` 사이에 강한 결합도가 발생함

→ 모두를 만족시키지 못하는 상황에선, 응집도 및 결합도가 우선이 되는게 나음

why? 객체는 본질적으로 하나의 책임을 갖고, 하나의 이유만으로 변경되어야 하기 때문이다. 

위 상황에서 기간에 대한 조건이 달라질경우, `Screening` 과 `PeriodCondition` 두곳이 변경되는 부작용이 발생한다.

## 4. 명령, 쿼리 분리 원칙

### 명령

- 상태를 변경시키며, 객체 정보 반환을 하지 않음(객체 상태 변경)

### 쿼리(= 함수)

- 상태 변경을 시키지 않고, 객체 정보를 반환(조회 용도)

### 분리하는 이유는?

- query에 수정(명령)이 포함되면, 디버깅하기가 굉장히 어려워 짐
- 정보 조회 함수에서, 내부에 객체 상태 변경여 포함된다면 결과 예측또한 굉장히 어려워 짐

### 예시)

```swift
public class PeriodCondition {
    public func isSatisfied(screening: Screening) {
         if screening.startDay > currentDate {
            screening.changeStartDay() 
            return false 
         }
         return true 
    }
}
```

- 위와같이 영화표 만료 여부를 체크할때, 만료여부 체크 및 해당 영화표의 기한을 바꾸는 함수가 존재
- 해당 객체를 사용하는 개발자 입장에선, 해당 로직 내부에 `screening` 객체를 변경시키는 코드를 호출할거라고 생각하지 못함
- 이로인한 버그 발생 가능성 증가

## 결론

- 인터페이스에는 “무엇을”이 담겨야 함(Not 어떻게)
- “캡슐화” 원칙을 준수하기 위한 행동이 응집도를 떨어트릴수 있다
    - 따라서 각 원칙을 반드시 지킨다는 생각보단 어떤 원칙을 중점적으로 보호할지 결정해야 한다.
- 쿼리(정보 조회)에 객체의 상태를 변경시키는 코드가 존재할 시, 사이드 이펙트가 굉장히 커진다
    - 따라서, 쿼리 및 명령을 분리하는게 좋음

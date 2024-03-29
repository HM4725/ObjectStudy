
# 4장 - 설계품질 및 트레이드 오프

## 서론

- 객체 지향 설계 핵심은 ****역할, 책임, 협력이며**,** 그중 **가장 중요한 것은 책임**
- 객체지향 설계란, 올바른 책임을 할당하고 낮은 결합도와 높은 응집도를 가진 구조를 창조
    - 결국 객체지향의 핵심은 책임
    - 책임 할당은 응집도와 결합도와 같은 설계 품질에 깊이 연관
- 객체의 상태가 아닌, 객체에 행동에 초점을 맞춤으로써 응집도와 결합도를 합리적인 수준으로 유지 가능
- 객체를 데이터 집합으로 바라본다면 내부 구현이 퍼블릭으로 드러나고, 변경에 취약한 설계를 만듦

## 데이터 중심의 설계(안좋은 사례의 예시)

- 훌륭한 객체지향 설계는 데이터가 아닌 책임에 초점
- 객체의 상태는 구현에 속하고, 해당 상태에 초점을 맞춘다면 구현 세부 사항이 객체 인터페이스에 나타나 캡슐화 원칙이 무너짐
    - 외부 객체가 객체 상태에 의존하게 되고, 이는 외부 객체가 해당 객체의 **구현에 의존**하는 것
    - **구현은 변화 가능성이 가장 높기**에, 구현이 변할때 그것에 의존하는 모든 객체에서 변경이 발생함
    - 이는 **응집도가 낮은 설계**

## 설계 트레이드 오프

### 캡슐화

- 객체 지향의 장점중 하나는, 한곳에서의 변경이 전체 시스템에 영향을 끼치지 않도록 하는 장치가 존재
- 이때, 객체를 사용하여 변경 가능성 높은 부분을 숨기고 외부에 안정적인 부분만 공개 가능
- 추상화의 한 종류

### 응집도, 결합도

1. 응집도
- 모듈 내부 요소들의 연관 정도
- 변경 발생시 모듈 내부에서 발생하는 변경정도
1. 결합도
- 의존성 정도를 의미, 다른 모듈에 얼마나 많은 지식을 갖고 있는지 나타냄
- 한 모듈 변경되기 위해 다른 모듈이 변경되는 정도

높은 응집도와, 낮은 결합도를 가진 설계를 추구한다면, 한 모듈의 변경이 다른 모듈 전체에 영향을 미치지 않게 된다. 

## 자율적인 객체

### 1. 캡슐화

- 데이터 중심의 설계가 낮은 응집도, 높은 결합도를 갖게된 이유는 **캡슐화를 위반**했기 때문
- 어떤 데이터를 갖고 있는지 내부 캡슐화, 외부에 공개해선 안됨
- 스스로 상태에 책임을 지며, 외부에선 정의된 메서드를 통해 상태에 접근할 수 있어야 함.
- private 접근자라도, 함수를 통해 외부로 제공시 캡술화를 위반하는 것
- 캡슐화 위반시 Side Effect
    - 코드 중복 발생(필요한 로직을 관련 객체에서 처리하지 않고, 해당 객체를 사용하는 다양한 곳에서 처리하기 때문)
    - 변경 취약

### 2. 변경에 취약한 예시

- 캡슐화 위반시, 내부에서만 사용되는 데이터 변수를 변경했을때, 다양한 곳에서 변경 발생(응집도가 낮음)

```swift
class Rectangle {
	
	public func getLeft() -> CGFloat 
	public func getRight() -> CGFloat
	// ...
	
	public func setLeft() -> CGFloat 
	// ...

	private let left: CGFloat
	private let right: CGFloat
	private let top: CGFloat
	private let bottom: CGFloat
	
}
```

- 변수들은 private이지만, getter, setter로 외부로 노출된 형태
- 이때, 해당 객체에 넓이가 필요한 경우, 외부에선 넓이를 이와같이 처리

```swift
let rectangle = Rectangle(left, right, top, bottom)
let area = rectangle.left * rectangle * right
```

이때, 변수를 `width`, `height` 로 변경할경우 `Rectangle` 객체를 사용하는 많은 곳에서 diff가 발생함 

### 3. 캡슐화를 통해 해결한 사례

```swift
class Rectangle {
	
	public func area() -> CGFloat {
	   return self.left * self.top
	}
	
	private let left: CGFloat
	private let right: CGFloat
	private let top: CGFloat
	private let bottom: CGFloat
	
}
```

- `func area() → CGFloat` 함수를 통해 넓이를 전달
- 이때, 내부 데이터 변수를 `width` , `height` 로 수정한다면?

```swift
class Rectangle {
	
	public func area() -> CGFloat {
	   return self.width * self.height
	}
	
	private let width: CGFloat
	private let height: CGFloat
	
}
```

- 위와 같이 변경되어도, 다른 곳에서 변경사항이 발생하지 않음

### 4. 데이터에 책임지는 객체

- 객체는 스스로 자신의 상태를 처리해야 함
- 협력에 참여하면서 수행할 책임을 정의하는 오퍼레이션이 중요
- 객체 설계시, 데이터 포함시엔 두가지 질문에 대답할 수 있어야 함
    - 객체가 어떤 데이터를 관리할 것인가?
    - 데이터를 통해 수행하는 오퍼레이션은 무엇인가?

## 결론

- 객체 지향 설계의 핵심은 올바른 책임을 할당하여 높은 응집도와 낮은 결합도를 가진 객체를 생성
- 이를 위해서 사용될 수 있는 건 추상화의 한 종류인 **캡슐화**
- 변경에 취약한 구현을 외부로 드러내지 않고, 인터페이스만을 public으로 드러냄(구현엔, 객체의 상태까지 포함됨)

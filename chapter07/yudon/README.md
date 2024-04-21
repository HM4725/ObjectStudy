# 7장 - 객체 분해 
밑의 내용은 “오브젝트” 도서를 읽고 **본인이 이해한 내용을 정리**한 글입니다. 실제 내용과 다를 수 있습니다.

### 추상화

- 문제 해결의 핵심만 남기는 작업
- 핵심을 남기기 어렵다면, 문제의 크기를 더욱 작은 문제의 단위로 나누는 작업인 **분해**를 실행

## 목차

1. Procedure 추상화, Data 추상화
2. Procedure 추상화의 문제점
3. ADT(Abstract Data Type)
4. 결론 

## 1. Procedure 추상화, Data 추상화

- 추상화의 두가지 종류
- 프로시저 추상화는 **무엇을 해야 하는지**에 대한 추상화
    - 이전에 배웠던 대로 메서드를 통해서 추상화 하는 방식(ex. 가격을 계산하라)
- 데이터 추상화는 **무엇을 알아야 하는지**에 대한 추상화
    - 이전과 달리, 메서드가 아닌 struct등이 추상화 됨
    - 이전 추상화는 대부분 메서드의 추상화를 의미했다면, 이제는 데이터 관리의 추상화가 등장
    - ex. Int, Double등의 `+` 함수를 사용하기 위해 내부 구현을 알 필요 없이, 단순하게 `사칙연산을 지원하는 데이터 타입` 이라는 사실만 알면 됨

### Procedure 추상화

- 기능 분해

### 데이터 추상화

- 타입 추상화(Abstract Data Type)
- 프로시저 추상화(Object-Oriented)

## 2. Procedure 추상화의 문제점

- 기능 분해의 문제점은 전통적인 방식인 `Top-Down Approach` 와 연관

### Top-Down-Approach

- 시스템 구성에 해당하는 최상위 기능을 정의하고, 세부적인 하위 단계로 분해
- 세분화 단계는, 하향식으로 갈수록 세분화된 구조(하향식으로 갈수록 덜 추상적)

### 장점

- 논리적이고 체계적인 시스템 개발절차로서, 서비스가 실제로 구성되어 있다면 굉장히 좋은 방법
- 단점이 많음에도, 많이 활용되는 이유는 빠른 개발 속도인 것 같음. 따라서 추후에 변경이 많이 발생할 때, 리팩토링을 통해 문제점을 해결하는 것도 좋은것 같음

### 단점

- 실제 서비스들은 최상위 기능 정의가 모호하고 확정되지 않았으며, 논리적이고 체계적이지 못한 경우가 많음
    - 최상위 기능임에도, 하위 기능에서 최상위로 jump 하는등 App내에서는 무조건적인 tree구조가 적용되지 못하는 케이스가 많은데, 그걸 의미하는 것으로 보임
- 객체 지향의 목적은 변경에 대응하기 위함이지만, **top-down은 시간에 의존한 구현**이기 때문에 재사용성 및 유연성이 떨어짐
    - 특정 Depth에 종속되어, 추후에 추가적인 기능에 사용될 때 재사용되기 어려움**(순서라는 구체적인 구현에 의존적이기 때문이다)**
    - 실행 순서는 가장 변경되기 쉬운 요소이기에, 이에 의존한다면 전체적인 사이드 이펙트 발생등이 큼

→ 결국 이 모든것을 관통하는 말인 **결합도**가 `Top-Down-Approach`의 단점

## 3. ADT

- 데이터 추상화는 결국 특정 데이터를 감추기 위해 데이터 추상화를 하는 작업
- 이전엔, 메시지 즉 함수를 추상화 시켰다면, 이젠 데이터를 추상화 시키기 위해 오퍼레이션을 사용
    - 이것만 보았을 때, 무엇이 달라진걸까?
    - 말로는 분명히 다르지만, 실제 추상화 하는 방식은 두가지를 섞어두어 구분하기 힘든것 같다. (~~지금은 그냥 넘어가보자, 뒤에서 혹은 다시 볼때 깨달음이 있을것이다.)~~

## 결론

- Procedure 추상화 중 하나인 `Top-Down-Approach` 의 최대 단점은 `시간에 따른 결합도` 가 큼
- 특정 순서에 의존하기 때문에, 재사용성이 떨어짐
- ADT의 경우 데이터를 감추기 위한 데이터 추상화 작업
    - 이때, OOP의 경우 다형성을 이용하고 ADT는 조건문을 통해서 분기 처리됨(올바르게 이해한 게 맞는지 잘 모르겠음.)
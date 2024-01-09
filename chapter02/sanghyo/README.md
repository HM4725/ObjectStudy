# Chapter02: 객체지향 프로그래밍
작성중 ...

## 1. 책 내용 분석 및 인사이트
> - 01 영화 예매 시스템 (p.37~40)
> - 02 객체지향 프로그래밍을 향해 (p.40~49)
> - 03 할인 요금 구하기 (p.49~56)
> - 04 상속과 다형성 (p.57~65)
> - 05 추상화와 유연성 (p.65~72)

## 2. 코드 작성 with Swift

### 문제점
Java로 쓰여진 코드를 Swift로 바꾸는 과정에서 언어들이 저마다 일대일 매칭되는 것이 아니므로 똑같이 할 수 없는 것이 있었다.
Java의 추상클래스(abstact class)에 해당하는 것을 Swift에서 찾을 수 없었고 나만의 방식으로 추상화된 객체를 만들 수 밖에 없었다.

```java
public abstract class DiscountPolicy {
  // 생략

  public Money calculateDiscountAmount(Screening screening) {
    // 생략
  }

  // 문제가 되는 abstract method
  abstract protected Money getDiscountAmount(Screening Screening);
}
```

### 해결 방법
언어의 차이로 발생하는 문제를 해결하는 방법으로는 두가지를 생각해볼 수 있다.
1. 위의 코드와 똑같은 구조로 유사한 추상화 계층을 만들어보는 것
2. 위와는 다른 구조를 지녔지만 똑같은 원리로 작동하는 나만의 추상화 계층을 만들어보는 것

1. 유사한 추상화 계층 만들기
```swift
```

2. 나만의 추상화 계층 만들기
```swift
```
## 3. 한 줄 느낀점

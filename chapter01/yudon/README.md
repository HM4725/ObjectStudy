## 티켓 판매 프로그램


### 재설계 구조
<img width="1080" alt="image" src="https://github.com/yudonlee/ObjectStudy/assets/39371835/1b01ec2f-ffc7-434b-a7ec-c0aaf761dffe">

### 기존 설계에서 변경한 이유 
1. TicketSeller 삭제 
- 예제 코드이기에, 몇개의 클래스로 나누어서 설명하고 있지만, 그럼에도 불구하고 TicketSeller의 역할 자체가 너무 작음
- TicketSeller의 역할은, TicketOffice에서 결국 모두 처리하고 있기에, `TicketSeller`까지의 분리는 과도함
-> TicketSeller 삭제

### 코드 구현 이유 
1. 과도한 클래스 감소
- class 사용목적은 결국, 내부 값이 변화되고 어떠한 행위를 처리하기 위함
- `Ticket`, `Fee` class의 경우 class로 아직까지 처리할 이유를 찾지 못함

2. getter, setter등 패턴 삭제
- 변수를 private으로 정의하는 이유는, 외부 사용자가 해당 변수에 의존하지 않았으면 하기 때문
- private으로 선언하더라도, getter, setter로 처리해버리면 해당 변수는 외부에 노출되는것과 동일한 효과
- 따라서, 그걸 막고자 getter등을 없앰

3. 테스트 코드 작성을 위해 `Bag`의 `ticket`변수 외부에 노출
- 테스트 코드에서, 티켓 구매 성공시, Bag에 해당 ticket이 존재하는지를 체크해야함
- 이를 위해, 해당 변수를 외부에 노출하되, `private(set)`처리
- 하지만, 테스트를 위해서 변수를 해당 방식으로 노출하는것은 옳지 않음(https://stackoverflow.com/questions/18435092/how-to-unit-test-a-private-variable)
- 그렇다면, 우리는 어떻게 처리해야할지?.. 고민이 됨(결국 티켓 판매에 성공했다는 사실을, `Bag`와 `TicketOffice` 두곳에서 체크해야하는건 아닐까?)

















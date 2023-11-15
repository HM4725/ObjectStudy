# ObjectStudy

# 1. 객체, 설계 <br/>

## 목차
- 기존 책 코드
- <a href="#refacotr">책 내용과 다르게 리팩토링</a>

## 기존 책 코드 
```swift
class Teater {
// ... 

func enter(audience: Audience) {
        if audience.getBag().hasInvitation() {
            guard let ticket = ticketSeller.getTicketOffice().getTicket() else { return }
            audience.getBag().setTicket(ticket: ticket)
        } else {
            guard let ticket = ticketSeller.getTicketOffice().getTicket() else { return }
            var ticketFee = ticket.getFee()
            audience.getBag().minusAmount(amount: ticketFee)
            ticketSeller.getTicketOffice().plusAmount(amount: ticketFee)
            audience.getBag().setTicket(ticket: ticket)
        }
    }
}
```

## 모듈의 세가지 목적
1. 실행 중에 제대로 동작될 것
2. 변경을 위해 존재하는 것 - 간단한 작업만으로 변경이 가능해야한다
3. 코드를 읽는 사람과 의사소통 하는 것 

제공된 코도는 위의 목적들 중 아래의 목적에서 어긋나는 코드이다
### 예상을 빗나가는 코드
하나의 클래스나 메서드에서 너무 많은 세부 사항을 다루기 때문에 읽는 사람, 코드를 작성하는 사람 모두에게 부담을 준다.

### 변경에 취약한 코드
Audience와 TicketSeller를 변경할 경우 이들에게 의존하는 Theater도 함께 변경해야한다.
-> 즉, 다른 클래스가 Audience의 내부에 대해 많이 알면 알수록 Audience를 변경하기 어려워진다 (의존성, Dependency 문제)
-> 의존성이 높은 경우를 결합도(coupling)이 높다고 한다
-> 의존성이 무조건 없애는 것이 정답은 아니기에 최소한의 의존성만 유지하자


## Audience와 TicketSeller를 Theater로부터 결합도를 낮춤

객체간의 결합도를 낮추고 객체 내부의 응집도를 높인다
응집도 - 객체 스스로가 자신의 데이터를 책임질수록 응집도가 높아짐

```swift
class Theater {
    func enter(audience: Audience) {
             ticketSeller.sellTo(audience: audience)
     }
}

class TicketSeller {
    func sellTo(audience: Audience) {
         guard let ticket = ticketOffice.getTicket() else { return }
         ticketOffice.plusAmount(amount: audience.buy(ticket: ticket))
     }
}

class Audience {
    func buy(ticket: Ticket) -> Int {
         if bag.hasInvitation() {
             bag.setTicket(ticket: ticket)
             return 0
         } else {
             var ticketFee = ticket.getFee()
             bag.minusAmount(amount: ticketFee)
             bag.setTicket(ticket: ticket)
             return ticketFee
         }
     }
}
```

이와 같이 Theater에게 책임이 집중되어 있던 상황


하나의 기능을 완성하는데 필요한 책임을 여러 객체에 걸쳐 분산 -> 책임의 이동


```swift
Class Audience {
  func buy(ticket: Ticket) -> Int {
         return bag.hold(ticket: ticket)
}

Class Bag {
  func hold(ticket: Ticket) -> Int {
         if hasInvitation() {
             setTicket(ticket: ticket)
             return 0
         } else {
             var ticketFee = ticket.getFee()
             minusAmount(amount: ticketFee)
             setTicket(ticket: ticket)
             return ticketFee
         }
     }
}

Class TicketOffice {
  func sellTicketTo(audience: Audience) {
         guard let ticket = getTicket() else { return }
         plusAmount(amount: audience.buy(ticket: ticket))
     }
}

Class TicketSeller {
  func sellTo(audience: Audience) {
         ticketOffice.sellTicketTo(audience: audience)
     }
}
```
<br/>
기존에 없던 TicketOffice와 Audience 사이의 의존성이 추가되었다.
이렇게 설계는 트레이드오프의 산물이라고 볼 수 있는데 계속해서 개발해보면서 트레이드오프에 대해 생각해보고 좋은 설계를 하는데 있어서 합당한 판단을 내릴 수 있도록 해보자<br/>

<a name="refacotr"></a>
## 책 내용과 다르게 리팩토링

기존의 책 내용에서 TicketSeller가 TicketOffice를 참조하는 관계가 이상하게 느껴져 이를 바꿔보는 간단한 작업을 하고 다이어그램으로 나타냈습니다.<br/><br/>
![제목 없는 다이어그램 drawio](https://github.com/HM4725/ObjectStudy/assets/26588989/4bd35f26-3639-4763-9b1e-fc7cbff4f50f)


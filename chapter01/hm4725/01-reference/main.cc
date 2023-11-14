/**
 * 객체 할당 해제의 어려움 때문에,
 * 복사 생성자와 레퍼런스를 활용.
 * @note 메모리 문제 해결됨
 * @warning 하나의 객체가 아닌 여러 객체가 생성됨
 * @warning 데코레이터 패턴이 강제됨
 * @warning getAmount의 의존성이 높아짐 (high coupling)
 */

#include <cassert>
#include <vector>
#include "Audience.hh"
#include "Bag.hh"
#include "Invitation.hh"
#include "Theater.hh"
#include "Ticket.hh"
#include "TicketSeller.hh"

/**
 * Literal[0|1]
 * - 0: Allocate ticketSeller and theater at main
 * - 1: Allocate only theater at main
 */
#define DECORATOR_PATTERN 1

int main() {
  /* Object */
  /* - Audiences */
  Audience audience1(Bag(3000, Invitation()));
  Audience audience2(Bag(3000));
  Audience audience3(Bag(4000));
  /* - Theater */
#if DECORATOR_PATTERN == 1
  Theater theater(TicketSeller(TicketOffice(
      0, std::vector<Ticket>{Ticket(1000), Ticket(1000), Ticket(1000)})));
#else
  TicketSeller ticketSeller(TicketOffice(
      0, std::vector<Ticket>{Ticket(1000), Ticket(1000), Ticket(1000)}));
  Theater theater(ticketSeller);
#endif

  /* Logic */
  theater.enter(audience1);
  theater.enter(audience2);
  theater.enter(audience3);

  /* Test */
  assert(audience1.getAmount() == 3000);
  assert(audience2.getAmount() == 2000);
  assert(audience3.getAmount() == 3000);
  assert(theater.getAmount() == 2000);
#if DECORATOR_PATTERN != 1
  /**
   * ticketSeller와 theater.ticketSeller는 다른 객체여서
   * 예상했던 대로 코드가 실행되지 않음.
   */
  assert(ticketSeller.getAmount() == 2000 &&
         "ticketSeller isn't same with ticketSeller of theater");
#endif
  return 0;
}
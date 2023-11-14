/**
 * CH01. 객체, 설계
 * - 01 티켓 판매 애플리케이션 구현하기
 * - 02 무엇이 문제인가
 * @warning 예상을 빗나가는 코드: Theater::enter 함수
 * @warning 변경에 취약한 코드: 관람객이 가방이 없다면?
 */

#include <cassert>
#include <vector>
#include "Audience.hh"
#include "Bag.hh"
#include "Invitation.hh"
#include "Theater.hh"
#include "Ticket.hh"
#include "TicketSeller.hh"

int main() {
  /* Object */
  /* - TicketSeller */
  TicketOffice ticketOffice(
      0, std::vector<Ticket *>{new Ticket(1000), new Ticket(1000),
                               new Ticket(1000)});
  TicketSeller ticketSeller(&ticketOffice);
  /* - Audiences */
  Audience audience1(new Bag(3000, new Invitation()));
  Audience audience2(new Bag(3000));
  Audience audience3(new Bag(4000));
  /* - Theater */
  Theater theater(&ticketSeller);

  /* Logic */
  theater.enter(&audience1);
  theater.enter(&audience2);
  theater.enter(&audience3);

  /* Test */
  assert(audience1.getAmount() == 3000);
  assert(audience1.getBag()->hasInvitation());
  assert(audience2.getAmount() == 2000);
  assert(!audience2.getBag()->hasInvitation());
  assert(audience3.getAmount() == 3000);
  assert(!audience3.getBag()->hasInvitation());
  assert(ticketOffice.getAmount() == 2000);

  return 0;
}
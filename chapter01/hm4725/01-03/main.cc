/**
 * CH01. 객체, 설계
 * - 03 설계 개선하기
 * - 04 객체 지향 설계
 * @warning (in c++) 객체 할당해제 어려움
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
  assert(audience2.getAmount() == 2000);
  assert(audience3.getAmount() == 3000);
  assert(ticketOffice.getAmount() == 2000);
  return 0;
}
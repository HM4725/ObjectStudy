/**
 * 객체 할당 해제의 어려움 때문에,
 * 스마트 포인터를 활용.
 * @note 메모리 문제 해결됨
 * @note 객체가 하나씩만 생성됨
 * @warning 객체가 한 곳에서만 의존하는지, 여러곳에서 의존하는지 알아야함
 *          -> 클래스 다이어그램이 우선되면, 큰 문제는 없을 것 같음
 * @warning 개발 속도가 현저히 느려짐
 */

#include <cassert>
#include <memory>
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
  /**
   * @note unique_ptr의 컨테이너는 initializer list를 사용할 수 없음.
   * vector = {std::make_unique<>()}; 에서 항상 copy가 발생하기 때문.
   */
  std::vector<std::unique_ptr<Ticket>> _tickets;
  _tickets.emplace_back(std::make_unique<Ticket>(1000));
  _tickets.emplace_back(std::make_unique<Ticket>(1000));
  _tickets.emplace_back(std::make_unique<Ticket>(1000));
  std::unique_ptr<TicketOffice> _ticketOffice =
      std::make_unique<TicketOffice>(0L, _tickets);
  std::shared_ptr<TicketSeller> ticketSeller =
      std::make_shared<TicketSeller>(std::move(_ticketOffice));
  /* - Audiences */
  std::shared_ptr<Audience> audience1 = std::make_shared<Audience>(
      std::make_unique<Bag>(3000, std::make_unique<Invitation>()));
  std::shared_ptr<Audience> audience2 =
      std::make_shared<Audience>(std::make_unique<Bag>(3000));
  std::shared_ptr<Audience> audience3 =
      std::make_shared<Audience>(std::make_unique<Bag>(4000));
  /* - Theater */
  std::unique_ptr<Theater> theater = std::make_unique<Theater>(ticketSeller);

  /* Logic */
  theater->enter(audience1);
  theater->enter(audience2);
  theater->enter(audience3);

  /* Test */
  assert(audience1->getAmount() == 3000);
  assert(audience2->getAmount() == 2000);
  assert(audience3->getAmount() == 3000);
  assert(ticketSeller->getAmount() == 2000);
  return 0;
}
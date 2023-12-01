#include "Money.hh"
#include <memory>

/* public */
const std::shared_ptr<Money> Money::ZERO = Money::wons(0);

/* protected */
Money::Money(long amount) : amount(amount) {}

/* public */
std::shared_ptr<Money> Money::wons(long amount) {
  struct MakeSharedEnabler : public Money {
    MakeSharedEnabler(long amount) : Money(amount) {}
  };
  return std::make_shared<MakeSharedEnabler>(amount);
}

std::shared_ptr<Money> Money::getptr() { return shared_from_this(); }

std::shared_ptr<Money> Money::plus(std::shared_ptr<Money> money) {
  return wons(amount + money->amount);
}

std::shared_ptr<Money> Money::minus(std::shared_ptr<Money> money) {
  return wons(this->amount - money->amount);
}

std::shared_ptr<Money> Money::times(double percent) {
  return wons(this->amount * percent);
}

bool Money::isLessThan(std::shared_ptr<Money> money) {
  return this->amount < money->amount;
}

bool Money::isGreaterThanOrEqual(std::shared_ptr<Money> money) {
  return this->amount >= money->amount;
}

long Money::getAmount() {
  return amount;
}
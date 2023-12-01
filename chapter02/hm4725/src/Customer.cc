#include "Customer.hh"

/* public */
Customer::Customer(std::string name, int age, std::shared_ptr<Money> balance)
    : name(name), age(age), balance(balance) {}

std::shared_ptr<Money> Customer::getBalance() { return balance; }

void Customer::deductBalance(std::shared_ptr<Money> money) {
  if (balance->isLessThan(money)) throw std::exception();
  balance = balance->minus(money);
}
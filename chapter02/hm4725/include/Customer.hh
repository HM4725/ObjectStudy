#pragma once

#include <memory>
#include <string>
#include "Money.hh"

class Customer {
 private:
  std::string name;
  int age;
  std::shared_ptr<Money> balance;

 public:
  Customer(std::string name, int age, std::shared_ptr<Money> balance);
  std::shared_ptr<Money> getBalance();
  void deductBalance(std::shared_ptr<Money> money);
};
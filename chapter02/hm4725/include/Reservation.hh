#pragma once

#include <memory>
#include "Customer.hh"
#include "Money.hh"
#include "Screening.fwd.hh"

class Reservation {
 private:
  std::shared_ptr<Customer> customer;
  std::shared_ptr<Screening> screening;
  std::shared_ptr<Money> fee;
  int audienceCount;

 public:
  Reservation(std::shared_ptr<Customer> customer,
              std::shared_ptr<Screening> screening, std::shared_ptr<Money> fee,
              int audienceCount);
};
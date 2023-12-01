#pragma once

#include <memory>
#include "Screening.fwd.hh"

class DiscountCondition {
 public:
  virtual ~DiscountCondition(){};
  virtual bool isSatisfiedBy(std::shared_ptr<Screening> screening) = 0;
};
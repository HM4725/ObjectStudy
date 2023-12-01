#pragma once

#include <memory>
#include <vector>
#include "DiscountCondition.hh"
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.fwd.hh"

class NoneDiscountPolicy : public DiscountPolicy {
 public:
  NoneDiscountPolicy();

 protected:
  virtual std::shared_ptr<Money> getDiscountAmount(
      std::shared_ptr<Screening> screening) override;
};
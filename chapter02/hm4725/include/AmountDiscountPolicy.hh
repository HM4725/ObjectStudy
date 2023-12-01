#pragma once

#include <memory>
#include <vector>
#include "DiscountCondition.hh"
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.fwd.hh"

class AmountDiscountPolicy : public DiscountPolicy {
 private:
  std::shared_ptr<Money> discountAmount;

 public:
  AmountDiscountPolicy(
      std::shared_ptr<Money> discountAmount,
      std::vector<std::unique_ptr<DiscountCondition>> &&conditions);

 protected:
  virtual std::shared_ptr<Money> getDiscountAmount(
      std::shared_ptr<Screening> screening) override;
};
#pragma once

#include <memory>
#include <vector>
#include "DiscountPolicy.hh"
#include "Money.hh"

class PercentDiscountPolicy : public DiscountPolicy {
 private:
  double percent;

 protected:
  virtual std::shared_ptr<Money> getDiscountAmount(
      std::shared_ptr<Screening> screening) override;

 public:
  PercentDiscountPolicy(
      double percent,
      std::vector<std::unique_ptr<DiscountCondition>> &&conditions);
};
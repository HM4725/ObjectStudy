#pragma once

#include <memory>
#include <vector>
#include "DiscountCondition.hh"
#include "Money.hh"
#include "Screening.fwd.hh"

class DiscountPolicy {
 private:
  std::vector<std::unique_ptr<DiscountCondition>> conditions;

 protected:
  virtual std::shared_ptr<Money> getDiscountAmount(
      std::shared_ptr<Screening> screening) = 0;

 public:
  DiscountPolicy() = default;
  DiscountPolicy(std::vector<std::unique_ptr<DiscountCondition>> &&conditions);
  virtual ~DiscountPolicy();
  std::shared_ptr<Money> calculateDiscountAmount(
      std::shared_ptr<Screening> screening);
};
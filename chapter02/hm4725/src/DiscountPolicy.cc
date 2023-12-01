#include "DiscountPolicy.hh"
#include "Money.hh"

DiscountPolicy::DiscountPolicy(
    std::vector<std::unique_ptr<DiscountCondition>> &&conditions)
    : conditions(std::move(conditions)) {}

DiscountPolicy::~DiscountPolicy() {}

std::shared_ptr<Money> DiscountPolicy::calculateDiscountAmount(
    std::shared_ptr<Screening> screening) {
  for (const auto &each : conditions) {
    if (each->isSatisfiedBy(screening)) {
      return getDiscountAmount(screening);
    }
  }
  return Money::ZERO;
}
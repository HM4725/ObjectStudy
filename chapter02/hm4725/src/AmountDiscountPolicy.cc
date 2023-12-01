#include "AmountDiscountPolicy.hh"
#include <memory>
#include <vector>
#include "DiscountCondition.hh"
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.hh"

std::shared_ptr<Money> AmountDiscountPolicy::getDiscountAmount(
    std::shared_ptr<Screening> screening) {
  return discountAmount;
}

AmountDiscountPolicy::AmountDiscountPolicy(
    std::shared_ptr<Money> discountAmount,
    std::vector<std::unique_ptr<DiscountCondition>> &&conditions)
    : DiscountPolicy(std::move(conditions)), discountAmount(discountAmount) {}
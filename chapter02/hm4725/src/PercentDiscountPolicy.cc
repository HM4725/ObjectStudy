#include "PercentDiscountPolicy.hh"
#include <memory>
#include <vector>
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.hh"

std::shared_ptr<Money> PercentDiscountPolicy::getDiscountAmount(
    std::shared_ptr<Screening> screening) {
  return screening->getMovieFee()->times(percent);
}

PercentDiscountPolicy::PercentDiscountPolicy(
    double percent,
    std::vector<std::unique_ptr<DiscountCondition>> &&conditions)
    : DiscountPolicy(std::move(conditions)), percent(percent) {}
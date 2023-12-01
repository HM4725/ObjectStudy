#include "NoneDiscountPolicy.hh"
#include <memory>
#include <vector>
#include "DiscountCondition.hh"
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.hh"

std::shared_ptr<Money> NoneDiscountPolicy::getDiscountAmount(
    std::shared_ptr<Screening> screening) {
  return Money::ZERO;
}

NoneDiscountPolicy::NoneDiscountPolicy() {}
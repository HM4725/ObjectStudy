#include "Movie.hh"
#include <string>

/* public */
std::shared_ptr<Movie> Movie::create(
    std::string title, const std::chrono::duration<long> &runningTime,
    std::shared_ptr<Money> fee,
    std::unique_ptr<DiscountPolicy> discountPolicy) {
  struct MakeSharedEnabler : public Movie {
    MakeSharedEnabler(std::string title,
                      const std::chrono::duration<long> &runningTime,
                      std::shared_ptr<Money> fee,
                      std::unique_ptr<DiscountPolicy> discountPolicy)
        : Movie(title, runningTime, fee, std::move(discountPolicy)) {}
  };
  return std::make_shared<MakeSharedEnabler>(title, runningTime, fee,
                                             std::move(discountPolicy));
}
std::shared_ptr<Movie> Movie::getPtr() { return shared_from_this(); }

std::shared_ptr<Money> Movie::getFee() { return fee; }

std::shared_ptr<Money> Movie::calculateMovieFee(
    std::shared_ptr<Screening> screening) {
  return fee->minus(discountPolicy->calculateDiscountAmount(screening));
}

/* protected */
Movie::Movie(std::string title, const std::chrono::duration<long> &runningTime,
             std::shared_ptr<Money> fee,
             std::unique_ptr<DiscountPolicy> discountPolicy)
    : title(title),
      runningTime(runningTime),
      fee(fee),
      discountPolicy(std::move(discountPolicy)) {}
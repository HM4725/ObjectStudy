#pragma once

#include <chrono>
#include <memory>
#include <string>
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Screening.fwd.hh"

class Movie : public std::enable_shared_from_this<Movie> {
 private:
  std::string title;
  std::chrono::duration<long> runningTime;
  std::shared_ptr<Money> fee;
  std::unique_ptr<DiscountPolicy> discountPolicy;

 public:
  static std::shared_ptr<Movie> create(
      std::string title, const std::chrono::duration<long> &runningTime,
      std::shared_ptr<Money> fee,
      std::unique_ptr<DiscountPolicy> discountPolicy);
  std::shared_ptr<Movie> getPtr();
  std::shared_ptr<Money> getFee();
  std::shared_ptr<Money> calculateMovieFee(
      std::shared_ptr<Screening> screening);

 protected:
  Movie(std::string title, const std::chrono::duration<long> &runningTime,
        std::shared_ptr<Money> fee,
        std::unique_ptr<DiscountPolicy> discountPolicy);
};
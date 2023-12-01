#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
#include "AmountDiscountPolicy.hh"
#include "Customer.hh"
#include "DiscountCondition.hh"
#include "DiscountPolicy.hh"
#include "Money.hh"
#include "Movie.hh"
#include "NoneDiscountPolicy.hh"
#include "PercentDiscountPolicy.hh"
#include "PeriodCondition.hh"
#include "Screening.hh"
#include "SequenceCondition.hh"

std::vector<std::unique_ptr<DiscountPolicy>> generateDiscountPolicies() {
  std::vector<std::unique_ptr<DiscountCondition>> conditions2;
  std::vector<std::unique_ptr<DiscountCondition>> conditions1;
  std::vector<std::unique_ptr<DiscountPolicy>> discountPolicies;

  discountPolicies.emplace_back(std::make_unique<NoneDiscountPolicy>());

  conditions1.emplace_back(std::make_unique<PeriodCondition>(
      MONDAY, tm{.tm_hour = 14, .tm_min = 0, .tm_sec = 0},
      tm{.tm_hour = 16, .tm_min = 59, .tm_sec = 0}));
  conditions1.emplace_back(std::make_unique<SequenceCondition>(2));
  conditions1.emplace_back(std::make_unique<PeriodCondition>(
      THURSDAY, tm{.tm_hour = 10, .tm_min = 0, .tm_sec = 0},
      tm{.tm_hour = 13, .tm_min = 59, .tm_sec = 0}));
  discountPolicies.emplace_back(
      std::make_unique<PercentDiscountPolicy>(0.1, std::move(conditions1)));

  conditions2.emplace_back(std::make_unique<SequenceCondition>(1));
  conditions2.emplace_back(std::make_unique<SequenceCondition>(10));
  conditions2.emplace_back(std::make_unique<PeriodCondition>(
      MONDAY, tm{.tm_hour = 10, .tm_min = 0, .tm_sec = 0},
      tm{.tm_hour = 11, .tm_min = 59, .tm_sec = 0}));
  conditions2.emplace_back(std::make_unique<PeriodCondition>(
      THURSDAY, tm{.tm_hour = 10, .tm_min = 0, .tm_sec = 0},
      tm{.tm_hour = 20, .tm_min = 59, .tm_sec = 0}));
  discountPolicies.emplace_back(std::make_unique<AmountDiscountPolicy>(
      Money::wons(800), std::move(conditions2)));

  return discountPolicies;
}

std::vector<std::shared_ptr<Movie>> generateMovies() {
  std::vector<std::unique_ptr<DiscountPolicy>> discountPolicies =
      generateDiscountPolicies();

  std::shared_ptr<Movie> avartar =
      Movie::create("아바타", std::chrono::minutes(120), Money::wons(10000),
                    std::move(discountPolicies.back()));
  discountPolicies.pop_back();
  std::shared_ptr<Movie> titanic =
      Movie::create("타이타닉", std::chrono::minutes(180), Money::wons(10000),
                    std::move(discountPolicies.back()));
  discountPolicies.pop_back();
  std::shared_ptr<Movie> kingsman =
      Movie::create("킹스맨1", std::chrono::minutes(130), Money::wons(10000),
                    std::move(discountPolicies.back()));
  discountPolicies.pop_back();

  return std::vector<std::shared_ptr<Movie>>{avartar, titanic, kingsman};
}

std::vector<std::shared_ptr<Screening>> generateScreenings(
    std::shared_ptr<Movie> movie) {
  std::vector<std::shared_ptr<Screening>> screenings;
  tm timeinfo;
  const char* timeformat = "%Y-%m-%d %H:%M:%S";
  strptime("2023-03-01 14:30:00", timeformat, &timeinfo);
  const int numScreenings = 100;

  for (int seq = 1; seq <= numScreenings; seq++) {
    timeinfo.tm_mday += 1;
    mktime(&timeinfo);
    screenings.emplace_back(Screening::create(movie, seq, timeinfo));
  }
  return screenings;
}

int main() {
  long amount = 10000 * 300 * 2;
  std::vector<std::shared_ptr<Movie>> movies = generateMovies();
  std::vector<std::shared_ptr<Screening>> screenings;
  std::shared_ptr<Customer> customer =
      std::make_shared<Customer>("이현민", 27, Money::wons(amount));
  std::vector<std::unique_ptr<Reservation>> reservations;

  for (auto movie : movies) {
    auto tmp = generateScreenings(movie);
    screenings.insert(screenings.end(), tmp.begin(), tmp.end());
  }
  try {
    for (auto screening : screenings) {
      reservations.emplace_back(screening->reserve(customer, 2));
    }
  } catch (std::exception& e) {
    std::cout << "[오류] 잔액 부족" << std::endl;
  }
  std::cout << "구매한 티켓 수: " << reservations.size() << " 개\n"
            << "잔액: " << customer->getBalance()->getAmount() << " 원"
            << std::endl;
  return 0;
}
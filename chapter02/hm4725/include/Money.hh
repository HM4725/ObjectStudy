#pragma once

#include <memory>

class Money : public std::enable_shared_from_this<Money> {
 public:
  static const std::shared_ptr<Money> ZERO;

 private:
  long amount;

 public:
  static std::shared_ptr<Money> wons(long amount);
  std::shared_ptr<Money> getptr();
  std::shared_ptr<Money> plus(std::shared_ptr<Money> money);
  std::shared_ptr<Money> minus(std::shared_ptr<Money> money);
  std::shared_ptr<Money> times(double percent);
  bool isLessThan(std::shared_ptr<Money> money);
  bool isGreaterThanOrEqual(std::shared_ptr<Money> money);
  long getAmount();

 protected:
  Money() = delete;
  Money(const Money &) = delete;
  Money(long amount);
  const Money &operator=(const Money &) = delete;
};

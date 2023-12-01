#pragma once

#include "DiscountCondition.hh"

enum DayOfWeek {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};

class PeriodCondition : public DiscountCondition {
 private:
  DayOfWeek dayOfWeek;
  tm startTime;
  tm endTime;

 public:
  PeriodCondition() = delete;
  PeriodCondition(DayOfWeek dayOfWeek, const tm& startTime, const tm& endTime);
  virtual bool isSatisfiedBy(std::shared_ptr<Screening> screening) override;

 private:
  int compareTime(const tm& time1, const tm& time2);
};
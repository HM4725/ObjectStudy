#include "PeriodCondition.hh"
#include "Screening.hh"

/* public */
PeriodCondition::PeriodCondition(DayOfWeek dayOfWeek, const tm& startTime,
                                 const tm& endTime)
    : dayOfWeek(dayOfWeek), startTime(startTime), endTime(endTime) {}

bool PeriodCondition::isSatisfiedBy(std::shared_ptr<Screening> screening) {
  tm whenScreened = screening->getStartTime();
  return whenScreened.tm_wday == dayOfWeek &&
         compareTime(whenScreened, startTime) >= 0 &&
         compareTime(endTime, whenScreened) >= 0;
}

/* private */
int PeriodCondition::compareTime(const tm& time1, const tm& time2) {
  int result = time1.tm_hour - time2.tm_hour;
  if (result != 0) return result;
  result = time1.tm_min - time2.tm_min;
  if (result != 0) return result;
  return time1.tm_sec - time2.tm_sec;
}

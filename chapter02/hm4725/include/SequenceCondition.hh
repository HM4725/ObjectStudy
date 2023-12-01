#pragma once

#include "DiscountCondition.hh"

class SequenceCondition : public DiscountCondition {
 private:
  int sequence;

 public:
  SequenceCondition() = delete;
  SequenceCondition(int sequence);
  virtual bool isSatisfiedBy(
      std::shared_ptr<Screening> screening) override;
};
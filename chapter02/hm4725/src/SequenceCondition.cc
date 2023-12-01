#include "SequenceCondition.hh"
#include "Screening.hh"

SequenceCondition::SequenceCondition(int sequence) : sequence(sequence) {}
bool SequenceCondition::isSatisfiedBy(std::shared_ptr<Screening> screening) {
  return screening->isSequence(sequence);
}
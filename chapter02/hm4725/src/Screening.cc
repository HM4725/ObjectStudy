#include "Screening.hh"

/* public */
std::shared_ptr<Screening> Screening::create(std::shared_ptr<Movie> movie,
                                             int sequence,
                                             const tm &whenScreened) {
  struct MakeSharedEnabler : public Screening {
    MakeSharedEnabler(std::shared_ptr<Movie> movie, int sequence,
                      const tm &whenScreened)
        : Screening(movie, sequence, whenScreened) {}
  };
  return std::make_shared<MakeSharedEnabler>(movie, sequence, whenScreened);
}

std::shared_ptr<Screening> Screening::getPtr() { return shared_from_this(); }

tm Screening::getStartTime() { return whenScreened; }

bool Screening::isSequence(int sequence) { return sequence == this->sequence; }

std::shared_ptr<Money> Screening::getMovieFee() { return movie->getFee(); }

std::shared_ptr<Money> Screening::calculateFee(int audienceCount) {
  return movie->calculateMovieFee(getPtr())->times(audienceCount);
}

std::unique_ptr<Reservation> Screening::reserve(
    std::shared_ptr<Customer> customer, int audienceCount) {
  std::shared_ptr<Money> fee = calculateFee(audienceCount);
  customer->deductBalance(fee);
  return std::make_unique<Reservation>(customer, getPtr(), fee, audienceCount);
}

/* protected */
Screening::Screening(std::shared_ptr<Movie> movie, int sequence,
                     const tm &whenScreened)
    : movie(movie), sequence(sequence), whenScreened(whenScreened) {}
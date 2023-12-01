#pragma once

#include <ctime>
#include <memory>
#include "Customer.hh"
#include "Money.hh"
#include "Movie.hh"
#include "Reservation.hh"

class Screening : public std::enable_shared_from_this<Screening> {
 private:
  std::shared_ptr<Movie> movie;
  int sequence;
  tm whenScreened;

 public:
  static std::shared_ptr<Screening> create(std::shared_ptr<Movie> movie,
                                           int sequence,
                                           const tm &whenScreened);
  std::shared_ptr<Screening> getPtr();

  tm getStartTime();
  bool isSequence(int sequence);
  std::shared_ptr<Money> getMovieFee();
  std::shared_ptr<Money> calculateFee(int audienceCount);
  std::unique_ptr<Reservation> reserve(std::shared_ptr<Customer> customer,
                                       int audienceCount);

 protected:
  Screening(std::shared_ptr<Movie> movie, int sequence, const tm &whenScreened);
};
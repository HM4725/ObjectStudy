#include "Reservation.hh"

Reservation::Reservation(std::shared_ptr<Customer> customer,
                         std::shared_ptr<Screening> screening,
                         std::shared_ptr<Money> fee, int audienceCount)
    : customer(customer),
      screening(screening),
      fee(fee),
      audienceCount(audienceCount) {}
#pragma once

#include <memory>
#include "Audience.hh"
#include "Ticket.hh"
#include "TicketSeller.hh"

class Theater {
 private:
  std::shared_ptr<TicketSeller> ticketSeller;

 public:
  Theater() = delete;
  Theater(const Theater &theater) = delete;
  Theater(std::shared_ptr<TicketSeller> ticketSeller)
      : ticketSeller(ticketSeller) {}

  void enter(std::shared_ptr<Audience> audience) {
    ticketSeller->sellTo(audience);
  }
};
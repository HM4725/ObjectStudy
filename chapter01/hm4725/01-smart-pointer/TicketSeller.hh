#pragma once

#include <memory>
#include "Audience.hh"
#include "Ticket.hh"
#include "TicketOffice.hh"

class TicketSeller {
 private:
  std::unique_ptr<TicketOffice> ticketOffice;

 public:
  TicketSeller() = delete;
  TicketSeller(const TicketSeller &ticketSeller) = delete;
  TicketSeller(std::unique_ptr<TicketOffice> ticketOffice)
      : ticketOffice(std::move(ticketOffice)) {}

  void sellTo(std::shared_ptr<Audience> audience) {
    ticketOffice->sellTicketTo(audience);
  }
  /* for debug */
  long getAmount() const { return ticketOffice->getAmount(); }
};
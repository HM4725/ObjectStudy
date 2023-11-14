#pragma once

#include "Audience.hh"
#include "Ticket.hh"
#include "TicketOffice.hh"

class TicketSeller {
 private:
  TicketOffice ticketOffice;

 public:
  TicketSeller() = delete;
  TicketSeller(const TicketSeller &) = default;
  TicketSeller(const TicketOffice &ticketOffice) : ticketOffice(ticketOffice) {}

  void sellTo(Audience &audience) { ticketOffice.sellTicketTo(audience); }
  /* for debug */
  long getAmount() const { return ticketOffice.getAmount(); }
};
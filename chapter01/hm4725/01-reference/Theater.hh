#pragma once

#include "Audience.hh"
#include "Ticket.hh"
#include "TicketSeller.hh"

class Theater {
 private:
  TicketSeller ticketSeller;

 public:
  Theater() = delete;
  Theater(const Theater &) = delete;
  Theater(const TicketSeller &ticketSeller) : ticketSeller(ticketSeller) {}
  void enter(Audience &audience) { ticketSeller.sellTo(audience); }
  /* for debug */
  long getAmount() const { return ticketSeller.getAmount(); }
};
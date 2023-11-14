#pragma once

#include "Audience.hh"
#include "Ticket.hh"
#include "TicketOffice.hh"

class TicketSeller {
 private:
  TicketOffice *ticketOffice;

 public:
  TicketSeller() = delete;
  TicketSeller(const TicketSeller &ticketSeller) = delete;
  TicketSeller(TicketOffice *ticketOffice) : ticketOffice(ticketOffice) {}

  void sellTo(Audience *audience) { ticketOffice->sellTicketTo(audience); }
};
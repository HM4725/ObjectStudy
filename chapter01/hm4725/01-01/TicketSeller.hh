#pragma once

#include "TicketOffice.hh"

class TicketSeller {
 private:
  TicketOffice *ticketOffice;

 public:
  TicketSeller() = delete;
  TicketSeller(const TicketSeller &ticketSeller) = delete;
  TicketSeller(TicketOffice *ticketOffice) : ticketOffice(ticketOffice) {}

  TicketOffice *getTicketOffice() const { return ticketOffice; }
};
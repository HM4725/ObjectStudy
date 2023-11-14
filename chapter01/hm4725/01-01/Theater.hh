#pragma once

#include "Audience.hh"
#include "Ticket.hh"
#include "TicketSeller.hh"

class Theater {
 private:
  TicketSeller *ticketSeller;

 public:
  Theater() = delete;
  Theater(const Theater &theater) = delete;
  Theater(TicketSeller *ticketSeller) : ticketSeller(ticketSeller) {}

  void enter(Audience *audience) {
    if (audience->getBag()->hasInvitation()) {
      Ticket *ticket = ticketSeller->getTicketOffice()->getTicket();
      audience->getBag()->setTicket(ticket);
    } else {
      Ticket *ticket = ticketSeller->getTicketOffice()->getTicket();
      audience->getBag()->minusAmount(ticket->getFee());
      ticketSeller->getTicketOffice()->plusAmount(ticket->getFee());
      audience->getBag()->setTicket(ticket);
    }
  }
};
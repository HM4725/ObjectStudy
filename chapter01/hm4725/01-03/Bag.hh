#pragma once

#include "Invitation.hh"
#include "Ticket.hh"

class Bag {
 private:
  long amount;
  Invitation *invitation;
  Ticket *ticket;

  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }
  bool hasInvitation() const { return invitation != nullptr; }
  bool hasTicket() const { return ticket != nullptr; }
  void setTicket(Ticket *ticket) { this->ticket = ticket; }

 public:
  Bag() = delete;
  Bag(const Bag &) = delete;
  Bag(long amount, Invitation *invitation = nullptr)
      : amount(amount), invitation(invitation), ticket(nullptr) {}

  long hold(Ticket *ticket) {
    if (hasInvitation()) {
      setTicket(ticket);
      return 0;
    } else {
      setTicket(ticket);
      minusAmount(ticket->getFee());
      return ticket->getFee();
    }
  }
  /* for debug */
  long getAmount() const { return amount; }
};
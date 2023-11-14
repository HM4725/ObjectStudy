#pragma once

#include "Invitation.hh"
#include "Ticket.hh"

class Bag {
 private:
  Invitation *invitation;
  long amount;
  Ticket *ticket;

 public:
  Bag() = delete;
  Bag(const Bag &) = delete;
  Bag(long amount, Invitation *invitation = nullptr)
      : invitation(invitation), amount(amount), ticket(nullptr) {}

  bool hasInvitation() const { return invitation != nullptr; }
  bool hasTicket() const { return ticket != nullptr; }
  void setTicket(Ticket *ticket) { this->ticket = ticket; }
  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }
  /* for debug */
  long getAmount() const { return amount; }
};
#pragma once

#include <memory>
#include "Invitation.hh"
#include "Ticket.hh"

class Bag {
 private:
  long amount;
  std::unique_ptr<Invitation> invitation;
  std::unique_ptr<Ticket> ticket;

  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }
  bool hasInvitation() const { return invitation != nullptr; }
  bool hasTicket() const { return ticket != nullptr; }
  void setTicket(std::unique_ptr<Ticket> ticket) {
    this->ticket = std::move(ticket);
  }

 public:
  Bag() = delete;
  Bag(const Bag &) = delete;
  Bag(long amount, std::unique_ptr<Invitation> invitation = nullptr)
      : amount(amount), invitation(std::move(invitation)), ticket(nullptr) {}

  long hold(std::unique_ptr<Ticket> ticket) {
    if (hasInvitation()) {
      setTicket(std::move(ticket));
      return 0;
    } else {
      long fee = ticket->getFee();
      setTicket(std::move(ticket));
      minusAmount(fee);
      return fee;
    }
  }
  /* for debug */
  long getAmount() const { return amount; }
};
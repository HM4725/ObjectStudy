#pragma once

#include <optional>
#include "Invitation.hh"
#include "Ticket.hh"

class Bag {
 private:
  long amount;
  std::optional<Invitation> invitation;
  std::optional<Ticket> ticket;

  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }
  bool hasInvitation() const { return invitation.has_value(); }
  bool hasTicket() const { return ticket.has_value(); }
  void setTicket(const Ticket &ticket) { this->ticket = ticket; }

 public:
  Bag() = delete;
  Bag(const Bag &obj)
      : amount(obj.amount), invitation(obj.invitation), ticket(obj.ticket) {}
  Bag(long amount, const std::optional<Invitation> &invitation = std::nullopt)
      : amount(amount), invitation(invitation), ticket(std::nullopt) {}

  long hold(const Ticket &ticket) {
    if (hasInvitation()) {
      setTicket(ticket);
      return 0;
    } else {
      long fee = ticket.getFee();
      setTicket(ticket);
      minusAmount(fee);
      return fee;
    }
  }
  /* for debug */
  long getAmount() const { return amount; }
};
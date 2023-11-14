#pragma once

#include <memory>
#include <vector>
#include "Audience.hh"
#include "Ticket.hh"

class TicketOffice {
 private:
  long amount;
  std::vector<std::unique_ptr<Ticket>> tickets;

  std::unique_ptr<Ticket> getTicket() {
    if (tickets.size() == 0) return nullptr;
    std::unique_ptr<Ticket> ticket = std::move(tickets[0]);
    tickets.erase(tickets.begin());
    return ticket;
  }
  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }

 public:
  TicketOffice() = delete;
  TicketOffice(const TicketOffice &) = delete;
  TicketOffice(long amount, std::vector<std::unique_ptr<Ticket>> &tickets)
      : amount(amount), tickets(std::move(tickets)) {}

  void sellTicketTo(std::shared_ptr<Audience> audience) {
    std::unique_ptr<Ticket> ticket = getTicket();
    long amount = audience->buy(std::move(ticket));
    plusAmount(amount);
  }
  /* for debug */
  long getAmount() const { return amount; }
};
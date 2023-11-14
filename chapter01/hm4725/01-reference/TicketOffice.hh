#pragma once

#include <optional>
#include <vector>
#include "Audience.hh"
#include "Ticket.hh"

class TicketOffice {
 private:
  long amount;
  std::vector<Ticket> tickets;

  std::optional<Ticket> getTicket() {
    if (tickets.size() == 0) return std::nullopt;
    Ticket ticket = tickets[0];
    tickets.erase(tickets.begin());
    return ticket;
  }
  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }

 public:
  TicketOffice() = delete;
  TicketOffice(const TicketOffice &obj)
      : amount(obj.amount), tickets(obj.tickets) {}
  TicketOffice(long amount, const std::vector<Ticket> &tickets)
      : amount(amount) {
    this->tickets.insert(std::end(this->tickets), std::begin(tickets),
                         std::end(tickets));
  }

  void sellTicketTo(Audience &audience) {
    std::optional<Ticket> ticket = getTicket();
    if (ticket.has_value()) {
      long amount = audience.buy(ticket.value());
      plusAmount(amount);
    }
  }
  /* for debug */
  long getAmount() const { return amount; }
};
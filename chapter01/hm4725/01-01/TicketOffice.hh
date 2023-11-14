#pragma once

#include <vector>
#include "Ticket.hh"

class TicketOffice {
 private:
  long amount;
  std::vector<Ticket *> tickets;

 public:
  TicketOffice() = delete;
  TicketOffice(const TicketOffice &) = delete;
  TicketOffice(long amount, const std::vector<Ticket *> &tickets)
      : amount(amount) {
    this->tickets.insert(std::end(this->tickets), std::begin(tickets),
                         std::end(tickets));
  }

  Ticket *getTicket() {
    if (tickets.size() == 0) return nullptr;
    Ticket *ticket = tickets[0];
    tickets.erase(tickets.begin());
    return ticket;
  }
  void minusAmount(long amount) { this->amount -= amount; }
  void plusAmount(long amount) { this->amount += amount; }
  long getAmount() const { return amount; }
};
#pragma once

#include <memory>
#include "Bag.hh"
#include "Ticket.hh"

class Audience {
 private:
  std::unique_ptr<Bag> bag;

 public:
  Audience() = delete;
  Audience(std::unique_ptr<Bag> bag) : bag(std::move(bag)) {}

  long buy(std::unique_ptr<Ticket> ticket) {
    return bag->hold(std::move(ticket));
  }
  /* for debug */
  long getAmount() { return bag->getAmount(); }
};
#pragma once

#include "Bag.hh"
#include "Ticket.hh"

class Audience {
 private:
  Bag bag;

 public:
  Audience() = delete;
  Audience(const Audience &obj) : bag(obj.bag) {}
  Audience(Bag bag) : bag(bag) {}

  long buy(const Ticket &ticket) { return bag.hold(ticket); }
  /* for debug */
  long getAmount() const { return bag.getAmount(); }
};
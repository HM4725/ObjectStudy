#pragma once

#include "Bag.hh"
#include "Ticket.hh"

class Audience {
 private:
  Bag *bag;

 public:
  Audience() = delete;
  Audience(Bag *bag) : bag(bag) {}
  long buy(Ticket *ticket) { return bag->hold(ticket); }
  /* for debug */
  long getAmount() const { return bag->getAmount(); }
};
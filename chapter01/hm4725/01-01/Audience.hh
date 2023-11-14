#pragma once

#include "Bag.hh"

class Audience {
 private:
  Bag *bag;

 public:
  Audience() = delete;
  Audience(Bag *bag) : bag(bag) {}

  Bag *getBag() const { return bag; }
  /* for debug */
  long getAmount() const { return bag->getAmount(); }
};
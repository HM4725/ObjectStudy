#pragma once

class Ticket {
 private:
  long fee;

 public:
  Ticket() = delete;
  Ticket(const Ticket &obj) : fee(obj.fee) {}
  Ticket(long fee) : fee(fee) {}

  long getFee() const { return fee; }
};
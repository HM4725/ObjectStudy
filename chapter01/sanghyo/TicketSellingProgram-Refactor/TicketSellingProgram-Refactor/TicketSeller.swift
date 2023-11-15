//
//  TicketSeller.swift
//  TicketSellingProgram-Refactor
//
//  Created by sanghyo on 11/15/23.
//

import Foundation

class TicketSeller {
    private var amount: Int
    private var tickets: [Ticket] = []
    
    init(amount: Int, tickets: [Ticket]) {
        self.amount = amount
        self.tickets = tickets
    }
    
    func sellTicketTo(audience: Audience) {
        guard let ticket = getTicket() else { return }
        plusAmount(amount: audience.buy(ticket: ticket))
        
    }
    
    func minusAmount(amount: Int) {
        self.amount -= amount
    }
    
    private func getTicket() -> Ticket? {
        return tickets.popLast()
    }
    
    private func plusAmount(amount: Int) {
        self.amount += amount
    }
    
    // test용 연산 property
    var getAmount: Int {
        return self.amount
    }
}

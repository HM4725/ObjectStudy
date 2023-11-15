//
//  TicketOffice.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

class TicketOffice {
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
}

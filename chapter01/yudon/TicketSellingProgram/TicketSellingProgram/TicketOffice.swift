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
        guard let ticket = self.getTicket() else {
            return
        }
        
        let amount = audience.buy(ticket: ticket)
        self.plusAmount(amount: amount)
    }
    
    private func getTicket() -> Ticket? {
        return tickets.popLast()
    }
    
    private func plusAmount(amount: Int) {
        self.amount += amount
    }

}

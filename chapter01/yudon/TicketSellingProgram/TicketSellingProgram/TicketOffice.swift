//
//  TicketOffice.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

internal class TicketOffice {

    private var amount: Int
    private var tickets: [Ticket] = []
    
    internal init(amount: Int, tickets: [Ticket]) {
        self.amount = amount
        self.tickets = tickets
    }
    
    internal func sellTicketTo(audience: Audience) {
        self.ticket()
            .flatMap { audience.buy(ticket: $0) }
            .map { self.removeLastTicket(amount: $0) }
    }
    
    private func ticket() -> Ticket? {
        return self.tickets.last
    }
    
    private func removeLastTicket(amount: Int) {
        _ = self.tickets.popLast()
        self.amount += amount
    }

}

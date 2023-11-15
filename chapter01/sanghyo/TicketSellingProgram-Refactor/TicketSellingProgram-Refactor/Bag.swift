//
//  Bag.swift
//  TicketSellingProgram-Refactor
//
//  Created by sanghyo on 11/15/23.
//

import Foundation

class Bag {
    private var amount: Int
    private var invitation: Invitation?
    private var ticket: Ticket?
    
    init(invitation: Invitation?, amount: Int) {
        self.invitation = invitation
        self.amount = amount
    }
    
    // study about convenience init is required
    convenience init(amount: Int) {
        self.init(invitation: nil, amount: amount)
    }
    
    private func hasInvitation() -> Bool {
        return invitation != nil ? true : false
    }
    
    private func hasTicket() -> Bool {
        return ticket != nil ? true : false
    }
    
    func hold(ticket: Ticket) -> Int {
        if hasInvitation() {
            setTicket(ticket: ticket)
            return 0
        } else {
            var ticketFee = ticket.getFee()
            minusAmount(amount: ticketFee)
            setTicket(ticket: ticket)
            return ticketFee
        }
    }
    
    private func setTicket(ticket: Ticket) {
        self.ticket = ticket
    }
    
    private func minusAmount(amount: Int) {
        self.amount -= amount
    }
    
    private func plusAmount(amount: Int) {
        self.amount += amount
    }
    
    // Test용 연산 property
    var getAmount: Int {
        return self.amount
    }
    
    
}

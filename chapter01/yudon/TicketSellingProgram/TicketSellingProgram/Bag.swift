//
//  Bag.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

internal class Bag {

    private var amount: Int
    private var invitation: Invitation?

    internal private(set) var ticket: Ticket?
    
    init(invitation: Invitation?, amount: Int) {
        self.invitation = invitation
        self.amount = amount
    }
    
    // study about convenience init is required
    convenience init(amount: Int) {
        self.init(invitation: nil, amount: amount)
    }
    
    internal func hold(ticket: Ticket) -> Int? {
        if self.hasInvitation() {
            return self.buyTicketWithInvitation(ticket: ticket)
        } 
        return self.buyTicketWithMoney(ticket: ticket)
    }

    private func buyTicketWithInvitation(ticket: Ticket) -> Int {
        self.ticket = ticket
        return 0
    }

    private func buyTicketWithMoney(ticket: Ticket) -> Int? {
        if self.amount >= ticket.fee {
            self.amount -= amount
            self.ticket = ticket
            return ticket.fee
        }
        return 0
    }
    
    private func hasInvitation() -> Bool {
        self.invitation != nil ? true : false
    }

}

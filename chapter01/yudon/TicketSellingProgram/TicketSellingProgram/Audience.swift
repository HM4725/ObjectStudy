//
//  Audience.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

internal class Audience {

    internal init(bag: Bag) {
        self.bag = bag
    }
    
    internal func buy(ticket: Ticket) -> Int? {
        self.bag.hold(ticket: ticket)
    }
    
    internal let bag: Bag

}

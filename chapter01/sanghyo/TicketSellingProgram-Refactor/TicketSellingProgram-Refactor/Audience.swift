//
//  Audience.swift
//  TicketSellingProgram-Refactor
//
//  Created by sanghyo on 11/15/23.
//

import Foundation

class Audience {
    private var bag: Bag
    
    init(bag: Bag) {
        self.bag = bag
    }
    
    func buy(ticket: Ticket) -> Int {
        return bag.hold(ticket: ticket)
    }
}


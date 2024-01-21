//
//  Ticket.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

class Ticket {
    private var fee: Int
    
    init(fee: Int) {
        self.fee = fee
    }
    
    func getFee() -> Int {
        return self.fee
    }
}

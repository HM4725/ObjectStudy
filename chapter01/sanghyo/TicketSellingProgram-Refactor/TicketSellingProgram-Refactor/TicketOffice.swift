//
//  TicketOffice.swift
//  TicketSellingProgram-Refactor
//
//  Created by sanghyo on 11/15/23.
//

import Foundation

class TicketOffice {
    private var ticketSellers: [TicketSeller]
    
    init(ticketSellers: [TicketSeller]) {
        self.ticketSellers = ticketSellers
    }
    
    func sellTo(audience: Audience) {
        guard let ticketSeller = getTicketSeller() else { return }
        ticketSeller.sellTicketTo(audience: audience)
    }
    
    private func getTicketSeller() -> TicketSeller? {
        return ticketSellers.popLast()
    }
    
    // Test용 연산 property
    var getAmount: Int {
        return self.ticketSellers.map { $0.getAmount }.reduce(0, +)
    }
}

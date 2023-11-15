//
//  Theater.swift
//  TicketSellingProgram-Refactor
//
//  Created by sanghyo on 11/15/23.
//

import Foundation

class Theater {
    private var ticketOffice: TicketOffice
    
    init(ticketOffice: TicketOffice) {
        self.ticketOffice = ticketOffice
    }
    
    func enter(audience: Audience) {
        ticketOffice.sellTo(audience: audience)
    }
}

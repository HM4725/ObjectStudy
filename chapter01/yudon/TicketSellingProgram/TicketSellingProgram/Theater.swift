//
//  Theater.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

internal class Theater {

    private var ticketOffice: TicketOffice
    
    init(ticketOffice: TicketOffice) {
        self.ticketOffice = ticketOffice
    }
    
    func enter(audience: Audience) {
        self.ticketOffice.sellTicketTo(audience: audience)
    }

}

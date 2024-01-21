//
//  main.swift
//  TicketSellingProgram
//
//  Created by sanghyo on 11/13/23.
//

import Foundation

let totalTicket = (1...100).map { _ in Ticket(fee: 300) }
let ticketOffice = TicketOffice(amount: 0, tickets: totalTicket)
let CGVTheater = Theater(ticketOffice: ticketOffice)



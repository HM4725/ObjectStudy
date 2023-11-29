//
//  Reservation.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct Reservation {
    private let customer: Customer
    private let screening: Screening
    private let fee: Money
    private let audienceCount: Int
    
    init(customer: Customer, screening: Screening, fee: Money, audienceCount: Int) {
        self.customer = customer
        self.screening = screening
        self.fee = fee
        self.audienceCount = audienceCount
    }
}

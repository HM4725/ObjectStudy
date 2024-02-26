//
//  Reservation.swift
//  GoodOOP
//
//  Created by sanghyo on 2/21/24.
//

import Foundation

struct Reservation {
    private var customer: Customer
    private var screening: Screening
    private var fee: Double
    private var audienceCount: Int
    
    init(customer: Customer, screening: Screening, fee: Double, audienceCount: Int) {
        self.customer = customer
        self.screening = screening
        self.fee = fee
        self.audienceCount = audienceCount
    }
}

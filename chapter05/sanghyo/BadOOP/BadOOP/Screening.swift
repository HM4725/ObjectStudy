//
//  Screening.swift
//  BadOOP
//
//  Created by sanghyo on 2/17/24.
//

import Foundation

// 예매하라 메시지에 응답
struct Screening {
    private var movie: Movie
    private var sequence: Int
    private var whenScreened: Date
    
    // 예매하라 메시지
    func reserve(customer: Customer, audienceCount: Int) -> Reservation {
        return Reservation(customer: customer, screening: self, fee: calculateFee(audienceCount: audienceCount), audienceCount: audienceCount)
    }
    
    func getSequence() -> Int {
        return sequence
    }
    
    func getWhenScreened() -> Date {
        return whenScreened
    }
    
    private func calculateFee(audienceCount: Int) -> Double {
        // movie 객체에게 메시지 전달
        return movie.calculateMovieFee(screening: self) * Double(audienceCount)
    }
}

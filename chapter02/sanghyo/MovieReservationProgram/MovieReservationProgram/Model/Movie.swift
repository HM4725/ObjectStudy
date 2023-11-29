//
//  Movie.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct Movie {
    private let title: String
    private let runningTime: Int
    private let fee: Money
    private let discountPolicy: DiscountPolicy
    
    init(title: String, runningTime: Int, fee: Money, discountPolicy: DiscountPolicy) {
        self.title = title
        self.runningTime = runningTime
        self.fee = fee
        self.discountPolicy = discountPolicy
    }
    
    func getFee() -> Money {
        return self.fee
    }
    
    func calculateMovieFee(screening: Screening) -> Money {
        return fee.minus(money: discountPolicy.calculateDiscountAmount(screening: screening))
    }
}

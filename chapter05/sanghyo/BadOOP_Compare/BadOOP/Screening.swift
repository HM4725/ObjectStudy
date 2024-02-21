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
    private var discountConditions: [DiscountCondition]
    
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
        // movie 객체에게 "계산하라" 메시지 전달
        return movie.calculateMovieFee(discountType: getDiscountType(screening: self)) * Double(audienceCount)
    }
    
    // Movie의 "계산하라" 책임에 영향을 주는 코드
    private func getDiscountType(screening: Screening) -> DiscountType {
        var discountType: DiscountType = .ten
        for condition in discountConditions {
            discountType = getBetterDiscountType(discountType, condition.getDiscountPercent(screening: self))
        }
        return discountType
    }
    
    private func getBetterDiscountType(_ type1: DiscountType, _ type2: DiscountType) -> DiscountType {
        return type1.rawValue > type2.rawValue ? type1 : type2
    }
}

//
//  Movie.swift
//  GoodOOP
//
//  Created by sanghyo on 2/21/24.
//

import Foundation

// 가격을 계산하라 메시지에 응답
class Movie {
    private var title: String
    private var runningTime: Int
    private var fee: Double
    // 모든 discount condition이 discountConditions 배열에 포함
    private var discountConditions: [DiscountCondition]
    
    init(title: String, runningTime: Int, fee: Double, discountConditions: [DiscountCondition]) {
        self.title = title
        self.runningTime = runningTime
        self.fee = fee
        self.discountConditions = discountConditions
    }
    
    // 계산하라 메시지
    func calculateMovieFee(screening: Screening) -> Double {
        if isDiscountable(screening: screening) {
            return fee - calculateDiscountAmount()
        }
        return fee
    }
    
    func calculateDiscountAmount() -> Double {
        return 0
    }
    
    func getFee() -> Double {
        return self.fee
    }
    
    private func isDiscountable(screening: Screening) -> Bool {
        for condition in discountConditions {
            if condition.isSatisfiedBy(screening: screening) {
                return true
            }
        }
        return false
    }
}

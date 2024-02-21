//
//  Movie.swift
//  BadOOP
//
//  Created by sanghyo on 2/17/24.
//

import Foundation

// 가격을 계산하라 메시지에 응답
struct Movie {
    private var title: String
    private var runningTime: Int
    private var fee: Double
    private var discountConditions: [DiscountCondition]
    
    private var movieType: MovieType
    private var discountAmount: Int
    private var discountPercent: Double
    
    // 계산하라 메시지
    func calculateMovieFee(screening: Screening) -> Double {
        if isDiscountable(screening: screening) {
            return fee - calculateDiscountAmount()
        }
        return fee
    }
    
    private func isDiscountable(screening: Screening) -> Bool {
        for condition in discountConditions {
            if condition.isSatisfiedBy(screening: screening) {
                return true
            }
        }
        return false
    }
    
    private func calculateDiscountAmount() -> Double {
        // Movie 객체에 movieType에 따라 쪼갤 수 있는 함수들이 존재
        switch movieType {
        case .amountDiscount:
            return calculateAmountDiscountAmount()
        case .percentDiscount:
            return calculatePercentDiscountAmount()
        case .noneDiscount:
            return calculateNoneDiscountAmount()
        }
    }
}

// MARK: Calculate Discount Amount
private extension Movie {
    func calculateAmountDiscountAmount() -> Double {
        return Double(discountAmount)
    }
    
    func calculatePercentDiscountAmount() -> Double {
        return fee * discountPercent
    }
    
    func calculateNoneDiscountAmount() -> Double {
        return 0
    }
}

//
//  AmountDiscountMovie.swift
//  GoodOOP
//
//  Created by sanghyo on 2/26/24.
//

import Foundation

final class AmountDiscountMovie: Movie {
    private var discountAmount: Double
    
    init(title: String, runningTime: Int, fee: Double, discountConditions: [DiscountCondition], discountAmount: Double) {
        self.discountAmount = discountAmount
        super.init(title: title, runningTime: runningTime, fee: fee, discountConditions: discountConditions)
    }
    
    override func calculateDiscountAmount() -> Double {
        return discountAmount
    }
}

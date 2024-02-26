//
//  PercentDiscountMovie.swift
//  GoodOOP
//
//  Created by sanghyo on 2/26/24.
//

import Foundation

final class PercentDiscountMovie: Movie {
    private var percent: Double
    
    init(title: String, runningTime: Int, fee: Double, discountConditions: [DiscountCondition], percent: Double) {
        self.percent = percent
        super.init(title: title, runningTime: runningTime, fee: fee, discountConditions: discountConditions)
    }
    
    override func calculateDiscountAmount() -> Double {
        return getFee() * percent
    }
    
}

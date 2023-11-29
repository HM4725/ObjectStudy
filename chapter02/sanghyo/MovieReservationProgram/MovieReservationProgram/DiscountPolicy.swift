//
//  DiscountPolicy.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

private protocol AbstractDiscountPolicy {
    func getDiscountAmount(screening: Screening) -> Money
}

class DiscountPolicy: AbstractDiscountPolicy {
    private let conditions: [DiscountCondition]
    
    fileprivate init(conditions: [DiscountCondition]) {
        self.conditions = conditions
    }
    
    func calculateDiscountAmount(screening: Screening) -> Money {
        for condition in conditions {
            if(condition.isSatisfiedBy(screening: screening)) {
                return getDiscountAmount(screening: screening)
            }
        }
        return Money.ZERO
    }
    
    fileprivate func getDiscountAmount(screening: Screening) -> Money { return Money.ZERO }
}

class AmountDiscountPolicy: DiscountPolicy {
    private let discountAmount: Money
    
    init(discountAmount: Money, discountCondition: [DiscountCondition]) {
        self.discountAmount = discountAmount
        super.init(conditions: discountCondition)
    }
    
    fileprivate override func getDiscountAmount(screening: Screening) -> Money {
        return discountAmount
    }
}

class PercentDiscountPolicy: DiscountPolicy {
    private let percent: Float
    
    init(percent: Float, discountCondition: [DiscountCondition]) {
        self.percent = percent
        super.init(conditions: discountCondition)
    }
    
    fileprivate override func getDiscountAmount(screening: Screening) -> Money {
        return screening.getMovieFee().times(percent: self.percent)
    }
}

class NoneDiscountPolicy: DiscountPolicy {
    override init(conditions: [DiscountCondition] = []) {
        super.init(conditions: conditions)
    }
    
    fileprivate override func getDiscountAmount(screening: Screening) -> Money {
        return Money.ZERO
    }
}

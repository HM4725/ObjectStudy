//
//  DiscountCondition.swift
//  BadOOP
//
//  Created by sanghyo on 2/17/24.
//

import Foundation

struct DiscountCondition {
    private var type: DiscountConditionType
    private var sequence: Int
    private var dayOfWeek: Int
    private var startTime: Date
    private var endTime: Date
    
    func isSatisfiedBy(screening: Screening) -> Bool {
        // DiscountCondition 객체에 type에 따라 쪼갤 수 있는 함수들이 존재
        if type == DiscountConditionType.period {
            return isSatisfiedByPeriod(screening: screening)
        }
        
        return isSatisfiedBySequence(screening: screening)
    }
    
    private func isSatisfiedByPeriod(screening: Screening) -> Bool {
        return dayOfWeek == screening.getWhenScreened().getDayOfWeek() &&
                startTime.compare(screening.getWhenScreened()) == .orderedAscending &&
                endTime.compare(screening.getWhenScreened()) == .orderedDescending
    }
    
    private func isSatisfiedBySequence(screening: Screening) -> Bool {
        return sequence == screening.getSequence()
    }
}

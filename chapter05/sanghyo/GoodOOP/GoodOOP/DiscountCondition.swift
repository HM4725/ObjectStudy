//
//  DiscountCondition.swift
//  GoodOOP
//
//  Created by sanghyo on 2/21/24.
//

import Foundation

protocol DiscountCondition {
    func isSatisfiedBy(screening: Screening) -> Bool
}

struct PeriodCondition: DiscountCondition {
    private var dayOfWeek: Int
    private var startTime: Date
    private var endTime: Date
    
    func isSatisfiedBy(screening: Screening) -> Bool {
        return dayOfWeek == screening.getWhenScreened().getDayOfWeek() &&
        startTime.compare(screening.getWhenScreened()) == .orderedAscending &&
        endTime.compare(screening.getWhenScreened()) == .orderedDescending
    }
}

struct SequenceCondition: DiscountCondition {
    private var sequence: Int
    
    func isSatisfiedBy(screening: Screening) -> Bool {
        return sequence == screening.getSequence()
    }
}

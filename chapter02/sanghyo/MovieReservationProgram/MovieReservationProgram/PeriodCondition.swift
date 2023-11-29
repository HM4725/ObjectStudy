//
//  PeriodCondition.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct PeriodCondition: DiscountCondition {
    private let day: DayOfWeek
    private let startTime: Date
    private let endTime: Date
    private var dayOfWeek: Int {
        return day.rawValue
    }
    
    init(day: DayOfWeek, startTime: Date, endTime: Date) {
        self.day = day
        self.startTime = startTime
        self.endTime = endTime
    }
    
    func isSatisfiedBy(screening: Screening) -> Bool {
        return screening.getStartTime().dayOfWeek == dayOfWeek &&
        [ComparisonResult.orderedAscending, ComparisonResult.orderedSame].contains(startTime.compare(screening.getStartTime())) &&
        [ComparisonResult.orderedDescending, ComparisonResult.orderedSame].contains(endTime.compare(screening.getStartTime())) 
    }
}

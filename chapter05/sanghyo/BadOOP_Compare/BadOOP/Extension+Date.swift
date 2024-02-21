//
//  Extension+Date.swift
//  BadOOP
//
//  Created by sanghyo on 2/17/24.
//

import Foundation

extension Date {
    func getDayOfWeek() -> Int {
        return Calendar.current.dateComponents([.weekday], from: self).weekday!
    }
}

//
//  Extension+Date.swift
//  GoodOOP
//
//  Created by sanghyo on 2/21/24.
//

import Foundation

extension Date {
    func getDayOfWeek() -> Int {
        return Calendar.current.dateComponents([.weekday], from: self).weekday!
    }
}

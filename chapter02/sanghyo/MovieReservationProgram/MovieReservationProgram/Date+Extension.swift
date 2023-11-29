//
//  Date+Extension.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

extension Date {
    var dayOfWeek: Int {
        return Calendar.current.dateComponents([.weekday], from: self).weekday!
    }
}

//
//  DiscountCondition.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

protocol DiscountCondition {
    func isSatisfiedBy(screening: Screening) -> Bool
}

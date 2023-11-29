//
//  SequenceCondition.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct SequenceCondition: DiscountCondition {
    private let sequence: Int
    
    init(sequence: Int) {
        self.sequence = sequence
    }
 
    func isSatisfiedBy(screening: Screening) -> Bool {
        return screening.isSequence(sequence: sequence)
    }
}

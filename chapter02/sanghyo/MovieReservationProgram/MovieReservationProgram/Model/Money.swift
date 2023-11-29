//
//  Money.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct Money {
    static let ZERO: Money = Money.wons(0)
    
    private let amount: Float
    
    static func wons(_ amount: Int) -> Money {
        return Money(Float(amount))
    }
    
    static func wons(_ amount: Float) -> Money {
        return Money(amount)
    }
    
    init(_ amount: Float) {
        self.amount = amount
    }
    
    func plus(money: Money) -> Money {
        return Money(self.amount + money.amount)
    }
    
    func minus(money: Money) -> Money {
        return Money(self.amount - money.amount)
    }
    
    func times(percent: Float) -> Money {
        return Money(self.amount*percent)
    }
    
    func times(cnt: Int) -> Money {
        return Money(self.amount*Float(cnt))
    }
    
    func isLessThan(other: Money) -> Bool {
        return self.amount < other.amount
    }
    
    func isGreaterThanOrEqual(other: Money) -> Bool {
        return self.amount >= other.amount
    }
}

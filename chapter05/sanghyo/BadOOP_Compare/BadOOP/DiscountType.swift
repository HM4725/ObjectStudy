//
//  DiscountType.swift
//  BadOOP
//
//  Created by sanghyo on 2/21/24.
//

import Foundation

// 추가 discount percent
enum DiscountType: Int {
    case seventy = 70
    case fifty = 50
    case ten = 10
    
    func percent() -> Int {
        return self.rawValue
    }
}

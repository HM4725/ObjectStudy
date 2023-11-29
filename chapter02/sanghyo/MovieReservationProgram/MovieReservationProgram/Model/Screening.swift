//
//  Screening.swift
//  MovieReservationProgram
//
//  Created by sanghyo on 11/29/23.
//

import Foundation

struct Screening {
    private let movie: Movie
    private let sequence: Int
    private let whenScreened: Date
    
    init(movie: Movie, sequence: Int, whenScreened: Date) {
        self.movie = movie
        self.sequence = sequence
        self.whenScreened = whenScreened
    }
    
    func getStartTime() -> Date {
        return self.whenScreened
    }
    
    
    func getMovieFee() -> Money {
        return movie.getFee()
    }
    
    func isSequence(sequence: Int) -> Bool {
        return self.sequence == sequence
    }
    
    func reserve(customer: Customer, audienceCount: Int) -> Reservation {
        return Reservation(customer: customer, screening: self, fee: calculateFee(audienceCount: audienceCount), audienceCount: audienceCount)
    }
}

private extension Screening {
    func calculateFee(audienceCount: Int) -> Money {
        return movie.calculateMovieFee(screening: self).times(cnt: audienceCount)
    }
}

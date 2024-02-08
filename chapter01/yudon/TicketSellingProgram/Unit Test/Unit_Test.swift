//
//  Unit_Test.swift
//  Unit Test
//
//  Created by sanghyo on 11/13/23.
//

import XCTest

final class Unit_Test: XCTestCase {

    private var initialAmount: Int!
    private var ticketFee: Int!
    private var audience: Audience!
    private var ticketOffice: TicketOffice!
    private var theater: Theater!
    private var tickets: [Ticket]!
    
    override func setUp() {
        super.setUp()
        self.initialAmount = 5000
        self.tickets = .init(repeating: Ticket(fee: 500), count: 30)
        self.ticketFee = tickets[0].fee
        self.ticketOffice = TicketOffice(amount: 5000, tickets: tickets)
        self.theater = Theater(ticketOffice: ticketOffice)
    }
    
    func test_초대장_없는_사람_티켓_구매_성공() {
        // given
        let bag = Bag(amount: initialAmount)
        self.audience = Audience(bag: bag)
        
        // when
        self.theater.enter(audience: audience)
        
        // then
        XCTAssertNotNil(self.audience.bag.ticket, "티켓 구매 실패")
    }
    
    func test_초대장_없는_사람_티켓_구매_실패() {
        // given
        let bag = Bag(amount: 300)
        self.audience = Audience(bag: bag)
        
        // when
        self.theater.enter(audience: audience)
        
        // then
        XCTAssertNil(self.audience.bag.ticket, "티켓 구매 실패 케이스에서, 티켓 구매 성공(구매 금액 부족)")
    }

    func test_초대장_있는_사람_티켓_획득_성공() {
        // given
        let invitation: Invitation = Invitation(when: Date())
        let bag = Bag(invitation: invitation, amount: 0)
        self.audience = Audience(bag: bag)
        
        // when
        theater.enter(audience: audience)
        
        // then
        XCTAssertNotNil(self.audience.bag.ticket, "티켓 구매 실패")
    }

}

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
    private var ticketSeller: TicketSeller!
    private var theater: Theater!
    private var tickets: [Ticket]!
    
    
    override func setUpWithError() throws {
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }

    override func tearDownWithError() throws {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }
    
    override func setUp() {
        super.setUp()
        self.initialAmount = 5000
        self.tickets = .init(repeating: Ticket(fee: 500), count: 30)
        self.ticketFee = tickets[0].getFee()
        self.ticketOffice = .init(amount: 5000, tickets: tickets)
        self.ticketSeller = .init(ticketOffice: ticketOffice)
        self.theater = .init(ticketSeller: ticketSeller)
    }
    
    func test_초대장_없는_사람() {
        // given
        var noInvitationBag: Bag = .init(amount: initialAmount)
        audience = .init(bag: noInvitationBag)
        
        // when
        theater.enter(audience: audience)
        
        // then
        XCTAssertEqual(noInvitationBag.getAmount, initialAmount - ticketFee, "두 값이 일치하지 않습니다")
    }
    
    func test_초대장_있는_사람() {
        // given
        var invitation: Invitation = .init(when: Date())
        var invitationBag: Bag = .init(invitation: invitation, amount: 5000)
        audience = .init(bag: invitationBag)
        
        // when
        theater.enter(audience: audience)
        
        // then
        XCTAssertEqual(invitationBag.getAmount, initialAmount, "두 값이 일치하지 않습니다")
    }

}

import XCTest
@testable import ElectronTouchID

final class ElectronTouchIDTests: XCTestCase {
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.
        XCTAssertEqual(ElectronTouchID().text, "Hello, World!")
    }

    static var allTests = [
        ("testExample", testExample)
    ]
}

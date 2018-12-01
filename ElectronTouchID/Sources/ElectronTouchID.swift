import Foundation
import LocalAuthentication

extension String: LocalizedError {/*Adds error.localizedDescription to Error instances*/
    public var errorDescription: String? { return self }
}

@_cdecl("is_supported")
public func is_supported() -> CBool {
    // Check if .deviceOwnerAuthenticationWithBiometrics will be supported (macOS 10.12.2 and later)
    // If not, this device doesn't support Touch ID anyway
    guard #available(macOS 10.12.2, *) else { return false }
    let context = LAContext()
    var error: NSError?
    // Check if this device supports Touch ID
    guard context.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: &error) else { return false }
    return true
}

@_cdecl("authenticate")
public func authenticate() {
  // let reasonString = String(cString: reason)
  let reasonString = "hi"
  let context = LAContext()
  var error: Error?

  if #available(macOS 10.12.2, *) {
  context.evaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, localizedReason: reasonString, reply: {(success: Bool, error: Error?) in
    print(success)
    print(error)
  })}
}

func handleError(errorCode: Int) -> String {
  var message = ""

  guard #available(macOS 10.13, *) else { return "Did not find error code on LAError.Code object" }
  switch errorCode {

  case LAError.Code.appCancel.rawValue:
      message = "Authentication was cancelled by application"

  case LAError.Code.authenticationFailed.rawValue:
      message = "The user failed to provide valid credentials"

  case LAError.Code.invalidContext.rawValue:
      message = "The context is invalid"

  case LAError.Code.passcodeNotSet.rawValue:
      message = "Passcode is not set on the device"

  case LAError.Code.systemCancel.rawValue:
      message = "Authentication was cancelled by the system"

  case LAError.Code.biometryLockout.rawValue:
      message = "Too many failed attempts."

  case LAError.Code.biometryNotAvailable.rawValue:
      message = "TouchID is not available on the device"

  case LAError.Code.userCancel.rawValue:
      message = "The user did cancel"

  case LAError.Code.userFallback.rawValue:
      message = "The user chose to use the fallback"

  default:
      message = "Did not find error code on LAError.Code object"

  }

  return message
}

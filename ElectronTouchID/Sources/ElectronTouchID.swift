import LocalAuthentication

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

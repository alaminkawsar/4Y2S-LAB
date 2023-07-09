func isPrime(_ number: Int) -> Bool {
    guard number >= 2 else {
        return false
    }
    
    for i in 2..<number {
        if number % i == 0 {
            return false
        }
    }
    
    return true
}

let num = 17 // Number to check for primality

if isPrime(num) {
    print("\(num) is prime.")
} else {
    print("\(num) is not prime.")
}

/**
kotlin Program to Find Factorial of a Number
 */
// the factorial of a non-negative number 
// n is the product of all positive whole numbers from 1 up to n.

fun main() {
    // Prompt the user to enter a non-negative integer
    print("Enter a non-negative integer: ")
    val n = readLine()?.toIntOrNull()

    if (n != null && n >= 0) {
        val factorial = calculateFactorial(n)
        println("The factorial of $n is: $factorial")
    } else {
        println("Invalid input. Please enter a non-negative integer.")
    }
}

fun calculateFactorial(n: Int): Long {
    if (n == 0 || n == 1) {
        return 1
    }
    var result = 1L
    for (i in 2..n) {
        result *= i
    }
    return result
}

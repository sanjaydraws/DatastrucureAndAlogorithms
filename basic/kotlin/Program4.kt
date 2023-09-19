/**
kotlin Program to Swap Two Numbers
 */

 fun main() {
    var firstNumber = 5
    var secondNumber = 10

    println("Before swapping:")
    println("First Number: $firstNumber")
    println("Second Number: $secondNumber")

    // Swapping the values
    val temp = firstNumber
    firstNumber = secondNumber
    secondNumber = temp

    println("\nAfter swapping:")
    println("First Number: $firstNumber")
    println("Second Number: $secondNumber")
}

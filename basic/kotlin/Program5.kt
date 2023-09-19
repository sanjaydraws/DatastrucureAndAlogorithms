/**
kotlin Program to Swap Two Numbers without using third variable
 */

fun main() {
    var firstNumber = 5
    var secondNumber = 10

    println("Before swapping:")
    println("First Number: $firstNumber")
    println("Second Number: $secondNumber")

    // Swapping the values without using a third variable
    firstNumber = firstNumber + secondNumber
    secondNumber = firstNumber - secondNumber
    firstNumber = firstNumber - secondNumber

    println("\nAfter swapping:")
    println("First Number: $firstNumber")
    println("Second Number: $secondNumber")
}

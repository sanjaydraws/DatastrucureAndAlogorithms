// kotlin Program to Reverse a Number

fun main() {
    // Prompt the user to enter a number
    print("Enter a number: ")
    val number = readLine()?.toIntOrNull()

    if (number != null) {
        val reversedNumber = reverseNumber(number)
        println("The reversed number is: $reversedNumber")
    } else {
        println("Invalid input. Please enter a valid integer.")
    }
}

fun reverseNumber(number: Int): Int {
    var reversed = 0
    var remaining = number

    while (remaining != 0) {
        val digit = remaining % 10
        reversed = reversed * 10 + digit
        remaining /= 10
    }

    return reversed
}

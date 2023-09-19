/**
kotlin Program to Check Whether a Number is a Palindrome or Not 
 */

fun main() {
    // Prompt the user to enter a number
    print("Enter a number: ")
    val number = readLine()?.toIntOrNull()

    if (number != null) {
        if (isPalindrome(number)) {
            println("$number is a palindrome.")
        } else {
            println("$number is not a palindrome.")
        }
    } else {
        println("Invalid input. Please enter a valid integer.")
    }
}

fun isPalindrome(number: Int): Boolean {
    var original = number
    var reversed = 0

    while (original > 0) {
        val digit = original % 10
        reversed = reversed * 10 + digit
        original /= 10
    }

    return number == reversed
}

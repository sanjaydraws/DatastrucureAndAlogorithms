// kotlin Program to Check Leap Year
/**
-> Years divisible by 4 are potential leap years.
-> If a year is divisible by 100, it may not be a leap year, except...
-> if it's also divisible by 400, in which case, it is a leap year.

 */

fun main() {
    // Prompt the user to enter a year
    print("Enter a year: ")
    val year = readLine()?.toIntOrNull()

    if (year != null && year > 0) {
        if (isLeapYear(year)) {
            println("$year is a leap year.")
        } else {
            println("$year is not a leap year.")
        }
    } else {
        println("Invalid input. Please enter a positive integer.")
    }
}

fun isLeapYear(year: Int): Boolean {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
}

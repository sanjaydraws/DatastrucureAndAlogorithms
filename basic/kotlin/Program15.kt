// kotlin Program to Print Fibonacci Series
/** 
The Fibonacci series is a sequence of numbers where each number (after the first two) is found 
by adding up the two numbers before it. It starts with 0 and 1.
*/
fun main() {
    // Prompt the user to enter the number of terms
    print("Enter the number of terms in the Fibonacci series: ")
    val numTerms = readLine()?.toIntOrNull()

    if (numTerms != null && numTerms > 0) {
        println("Fibonacci Series:")
        printFibonacciSeries(numTerms)
    } else {
        println("Invalid input. Please enter a positive integer.")
    }
}

fun printFibonacciSeries(numTerms: Int) {
    var firstTerm = 0
    var secondTerm = 1

    print("$firstTerm, $secondTerm")

    for (i in 3..numTerms) {
        val nextTerm = firstTerm + secondTerm
        print(", $nextTerm")

        firstTerm = secondTerm
        secondTerm = nextTerm
    }

    println()
}

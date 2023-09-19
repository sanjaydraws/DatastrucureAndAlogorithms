// kotlin Program to Calculate Sum of Natural Numbers 

fun calculateSum(n:Int):Int{
    return (n * (n + 1))/2
}
fun main() {
    // Prompt the user to enter a positive integer
    print("Enter a positive integer: ")
    val n = readLine()?.toIntOrNull()
    // val n = 7
    if (n != null && n > 0) {
        val sum = calculateSum(n)
        println("The sum of natural numbers from 1 to $n is: $sum")
    } else {
        println("Invalid input. Please enter a positive integer.")
    }
}
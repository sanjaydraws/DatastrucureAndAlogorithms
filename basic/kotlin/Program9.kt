

fun main() {
    // Prompt the user to enter a number
    print("Enter a number: ")

    // Read the user's input as an integer
    val number = readLine()?.toIntOrNull()

    if (number != null) {
        if (number % 2 == 0) {
            println("$number is even.")
        } else {
            println("$number is odd.")
        }
    } else {
        println("Invalid input. Please enter a valid integer.")
    }
}

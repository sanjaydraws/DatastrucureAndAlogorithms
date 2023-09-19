/**
kotlin Program to Print the ASCII Value of a Character
 */
fun main() {
    // Prompt the user to enter a character
    print("Enter a character: ")

    // Read the input character as a string
    val input = readLine()

    // Check if input is not null and is a single character
    if (input != null && input.length == 1) {
        // Get the ASCII value of the character
        val asciiValue = input[0].toInt()
        // val asciiValue = input[0].code // another way to get ASCII value 

        // Print the ASCII value
        println("The ASCII value of '$input' is $asciiValue")
    } else {
        println("Invalid input. Please enter a single character.")
    }
}

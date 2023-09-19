// kotlin Program to Check Whether a Character is Vowel or Consonant 


fun main() {
//     // Prompt the user to enter a character
    print("Enter a character: ")

    // Read the input character as a string and take the first character
    val input = readLine()?.trim()?.get(0)
    // val input = 'a'
    if (input != null) {
        // Check if the input is an alphabet character
        if (input.isLetter()) {
            // Check if the lowercase version of the character is in the set of vowels
            if (input.toLowerCase() in setOf('a', 'e', 'i', 'o', 'u')) {
                println("$input is a vowel.")
            } else {
                println("$input is a consonant.")
            }
        } else {
            println("Invalid input. Please enter an alphabet character.")
        }
    } else {
        println("Invalid input. Please enter a character.")
    }
}

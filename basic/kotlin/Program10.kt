fun main() {
    // Prompt the user to enter three numbers
    print("Enter three numbers separated by spaces: ")

    // Read the user's input as a string and split it into an array of strings
    val input = readLine()?.split(" ")

    if (input != null && input.size == 3) {
        // Convert the input strings to integers
        val number1 = input[0].toIntOrNull()
        val number2 = input[1].toIntOrNull()
        val number3 = input[2].toIntOrNull()

        if (number1 != null && number2 != null && number3 != null) {
            val maxNumber = maxOf(number1, number2, number3)
            println("The largest number is: $maxNumber")
        } else {
            println("Invalid input. Please enter valid numbers.")
        }
    } else {
        println("Invalid input. Please enter three numbers separated by spaces.")
    }
}

/**
fun customMaxOf(vararg numbers: Int): Int {
    if (numbers.isEmpty()) {
        throw IllegalArgumentException("Input list cannot be empty.")
    }

    var max = numbers[0]

    for (num in numbers) {
        if (num > max) {
            max = num
        }
    }

    return max
}

fun main() {
    val maxNumber = customMaxOf(10, 5, 8, 15, 3)
    println("The maximum number is: $maxNumber")
}


 */
// kotlin Program to Print an Integer Entered By the User

fun main(){
    print("Enter a Integer")
    val userInput = readLine()

    try{
        val userInteger = userInput?.toInt()
        if(userInput!=null){
            println("You entered: $userInteger")
        }else{
            println("Invalid Input. Please enter a valid integer")   
        }
    }
    catch(e:NumberFormatException){
        println("Invalid input. Please enter a valid integer.")
    }
}
/**
// Prompt the user to enter three numbers
    print("Enter three numbers separated by spaces: ")

    // Read the user's input as a string and split it into an array of strings
    val input = readLine()?.split(" ")
    if (input != null && input.size == 3) {
        // Convert the input strings to integers
        val number1 = input[0].toIntOrNull()
        val number2 = input[1].toIntOrNull()
        val number3 = input[2].toIntOrNull()
        // print number
    }
 */
/**
reverse a string
 */

fun reverseString(input: String): String {
    return input.reversed()
}
fun reverseStringWithoutCustomMethod(input: String): String {
    var reversed = ""

    for (i in input.length - 1 downTo 0) {
        reversed += input[i]
    }

    return reversed
}
fun reverseStringWithoutConcatenation(input: String): String {
    val charArray = input.toCharArray()

    var start = 0
    var end = input.length - 1

    while (start < end) {
        val temp = charArray[start]
        charArray[start] = charArray[end]
        charArray[end] = temp

        start++
        end--
    }

    return String(charArray)
}

fun main() {
    val str = "Hello, World!"
    val reversedStr = reverseStringWithoutCustomMethod(str)
    println("Reversed String: $reversedStr")
}




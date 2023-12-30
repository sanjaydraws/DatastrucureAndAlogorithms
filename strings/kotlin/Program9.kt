// Count Occurrences of a Character:
fun countOccurrences(input: String, char: Char): Int {
    return input.count { it == char }
}

fun countOccurrences(input: String, char: Char): Int {
    var count = 0
    for (c in input) {
        if (c == char) {
            count++
        }
    }
    return count
}

fun main() {
    val inputString = "Hello, World!"
    val charToCount = 'l'

    val result = countOccurrences(inputString, charToCount)

    println("The character '$charToCount' occurs $result times in the string.")
}

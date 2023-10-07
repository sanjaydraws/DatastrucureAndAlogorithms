/**
kotlin Program to Insert a String into Another String
 */

fun insertString(original: String, toInsert: String, position: Int): String {
    val stringBuilder = StringBuilder(original)
    stringBuilder.insert(position, toInsert)
    return stringBuilder.toString()
}

fun insertStringCustom(original: String, toInsert: String, position: Int): String {
    val result = CharArray(original.length + toInsert.length)

    var index = 0

    for (i in 0 until original.length) {
        if (i == position) {
            for (char in toInsert) {
                result[index++] = char
            }
        }
        result[index++] = original[i]
    }

    // If the position is at the end of the string, append the 'toInsert' string.
    if (position == original.length) {
        for (char in toInsert) {
            result[index++] = char
        }
    }

    return String(result)
}
fun main() {
    val originalString = "Hello World"
    val stringToInsert = " beautiful"
    val position = 5

    val modifiedString = insertString(originalString, stringToInsert, position)

    println("Original String: $originalString")
    println("String to Insert: $stringToInsert")
    println("Position: $position")
    println("Modified String: $modifiedString")
}

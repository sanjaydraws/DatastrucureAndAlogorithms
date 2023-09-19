/**
 check for substring
 */
fun containsSubstring(mainString: String, subString: String): Boolean {
    val mainLength = mainString.length
    val subLength = subString.length

    for (i in 0..mainLength - subLength) {
        var found = true
        for (j in 0 until subLength) {
            if (mainString[i + j] != subString[j]) {
                found = false
                break
            }
        }
        if (found) return true
    }
    return false
}

fun main() {
    val mainString = "Hello, World!"
    val subString = "World"

    val result = containsSubstring(mainString, subString)

    if (result) {
        println("'$subString' is a substring of '$mainString'")
    } else {
        println("'$subString' is not a substring of '$mainString'")
    }
}

fun hasUniqueCharacters(inputString: String): Boolean {
    val charSet = HashSet<Char>()
    for (char in inputString) {
        if (!charSet.add(char)) {
            return false
        }
    }
    return true
}

fun main() {
    val testString1 = "abcdefg"
    val testString2 = "hello"

    val result1 = hasUniqueCharacters(testString1)
    val result2 = hasUniqueCharacters(testString2)

    println("'$testString1' has unique characters: $result1")
    println("'$testString2' has unique characters: $result2")
}

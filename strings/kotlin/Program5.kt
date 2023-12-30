fun removeDuplicates(inputString: String): String {
    val charArray = inputString.toCharArray()
    val resultCharArray = mutableListOf<Char>()
    val seen = mutableSetOf<Char>()

    for (char in charArray) {
        if (seen.add(char)) {
            resultCharArray.add(char)
        }
    }

    return resultCharArray.joinToString("")
}

fun main() {
    val inputString = "programming"
    val result = removeDuplicates(inputString)

    println("Original String: $inputString")
    println("String with Duplicates Removed: $result")
}

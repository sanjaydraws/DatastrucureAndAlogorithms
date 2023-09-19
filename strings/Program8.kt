/**
reverse words in string

 */


fun reverseWords(sentence: String): String {
    return sentence.split(" ").reversed().joinToString(" ")
}

fun reverseWordsCustom(sentence: String): String {
    val words = mutableListOf<String>()
    var currentWord = StringBuilder()

    for (char in sentence) {
        if (char.isWhitespace()) {
            if (currentWord.isNotEmpty()) {
                words.add(currentWord.toString())
                currentWord.clear()
            }
        } else {
            currentWord.append(char)
        }
    }

    if (currentWord.isNotEmpty()) {
        words.add(currentWord.toString())
    }

    return words.reversed().joinToString(" ")
}

fun main() {
    val inputSentence = "Hello World Kotlin"

    val reversedSentence = reverseWordsCustom(inputSentence)

    println("Original sentence: $inputSentence")
    println("Reversed sentence: $reversedSentence")
}

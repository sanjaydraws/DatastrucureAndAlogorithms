// check Anagrams
// both words should use the same letters.

fun areAnagrams2(str1: String, str2: String): Boolean {
    val sanitizedStr1 = str1.filter { it.isLetter() }.toLowerCase()
    val sanitizedStr2 = str2.filter { it.isLetter() }.toLowerCase()

    return sanitizedStr1.length == sanitizedStr2.length &&
            sanitizedStr1.toCharArray().sorted() == sanitizedStr2.toCharArray().sorted()
}

fun areAnagramsCustom(str1: String, str2: String): Boolean {
    // lenght of string should be equal
    if (str1.length != str2.length) {
        return false
    }

    val charFrequency = mutableMapOf<Char, Int>()

    for (char in str1) {
        charFrequency[char] = charFrequency.getOrDefault(char, 0) + 1
    }

    for (char in str2) {
        if (!charFrequency.containsKey(char)) {
            return false
        }

        charFrequency[char] = charFrequency[char]!! - 1

        if (charFrequency[char] == 0) {
            charFrequency.remove(char)
        }
    }

    return charFrequency.isEmpty()
}
fun areAnagramsCustom(str1: String, str2: String): Boolean {
    if (str1.length != str2.length) {
        return false
    }

    val charFrequency = IntArray(26) // Assuming only lowercase English letters

    for (i in str1.indices) {
        charFrequency[str1[i] - 'a']++
        charFrequency[str2[i] - 'a']--
    }

    for (frequency in charFrequency) {
        if (frequency != 0) {
            return false
        }
    }

    return true
}

fun main() {
    val str1 = "listen"
    val str2 = "silent"
    val areAnag = areAnagramsCustom(str1, str2)
    if (areAnag) {
        println("$str1 and $str2 are anagrams.")
    } else {
        println("$str1 and $str2 are not anagrams.")
    }
}




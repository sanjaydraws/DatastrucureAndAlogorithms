// Count Vowels and Consonants:


fun countVowelsAndConsonants(input: String): Pair<Int, Int> {
    val vowels = "aeiouAEIOU"
    var vowelCount = 0
    var consonantCount = 0

    for (char in input) {
        if (char.isLetter()) {
            if (char in vowels) {
                vowelCount++
            } else {
                consonantCount++
            }
        }
    }

    return Pair(vowelCount, consonantCount)
}
fun countVowelsAndConsonantsUsingStandardLibrary(input: String): Pair<Int, Int> {
    val vowels = "aeiouAEIOU"
    val vowelCount = input.count { it in vowels && it.isLetter() }
    val consonantCount = input.count { it !in vowels && it.isLetter() }
    return Pair(vowelCount, consonantCount)
}

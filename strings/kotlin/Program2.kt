// write program to Check string Palindrome 


fun isPalindrome(input: String): Boolean {
    return input == input.reversed()
}
fun isPalindromeCustom(input: String): Boolean {
    var start = 0
    var end = input.length - 1

    while (start < end) {
        if (input[start] != input[end]) {
            return false
        }

        start++
        end--
    }

    return true
}

fun main() {
    val str = "racecar"
    val isPal = isPalindromeCustom(str)
    if (isPal) {
        println("$str is a palindrome.")
    } else {
        println("$str is not a palindrome.")
    }
}

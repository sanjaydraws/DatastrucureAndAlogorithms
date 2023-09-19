/**
 prime number is greator than 1, can not divided by any whole number other than itself
 */

 fun main() {
    val numberToCheck = 17 // Change this to any number you want to check

    val isPrimeResult = isPrime(numberToCheck)

    if (isPrimeResult) {
        println("$numberToCheck is a prime number.")
    } else {
        println("$numberToCheck is not a prime number.")
    }
}

fun isPrime(number:Int):Boolean{
    if(number < 2){
        return false 
    }
    for(i in 2 until number){
        if(number % i == 0){
            return false
        }
    }
    return true 
}
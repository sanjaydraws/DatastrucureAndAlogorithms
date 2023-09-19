// kotlin Program to Print Prime Numbers From 1 to N 


fun isPrime(num:Int):Boolean{
    if(num < 2){
        false 
    }
    for(i in 2 until num){
        if(num % i == 0){
            return false 
        }
    }
    return true 
}

fun main() {
    val num = 25
    for (i in 2..num) {
        if (isPrime(i)) {
                println(i)
        }
    }
}

 fun rearrange(arr: IntArray, n: Int) {
    var j = 0
    var temp: Int
    for (i in 0 until n) {
        if (arr[i] < 0) {
            if (i != j) {
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
            }
            j++
        }
    }
}

// print an array
fun printArray(arr: IntArray, n: Int) {
    for (i in 0 until n) print(arr[i].toString() + " ")
}


fun main(args: Array<String>) {
    val arr = intArrayOf(-1, 2, -3, 4, 5, 6, -7, 8, 9)
    val n = arr.size
    rearrange(arr, n)
    printArray(arr, n)
}



// Heap implementation 


//Heap creation: TC: O(n)
// insertion : T.c - O(log n)
// deletion : to access root node T.C O(log n)
// - nsize array to convert in Heap - O(n)

//Heap - find max and find min -O(1) and on array takes : O(n)

class Heap(private val capacity: Int) {
    private val arr = IntArray(capacity)
    private var size = 0

     /**
      * insert element in Heap
      */
    fun insert(value: Int) {
        if (size == capacity) {
            println("Heap Overflow")
            return
        }
        //size will be incresed in insertions
        size++
        var index = size
        arr[index] = value //starts assigning from 1 index 

        // take the value to it's current position 
        while (index > 1) {
            val parentIndex = index / 2
            if (arr[index] > arr[parentIndex]) {
                swap(index, parentIndex)
                index = parentIndex
            } else {
                break
            }
        }
    }

    fun printHeap() {
        for (i in 1..size) {
            print("${arr[i]} ")
        }
        println()
    }

    /**
     * delete element in Heap
     */
    fun deleteFromHeap(): Int {
        val answer = arr[1]
        //assign last element to rootnode 
        arr[1] = arr[size]
        // delete last element from it's original position
        size--
        var index = 1

        while (index < size) {
            val leftIndex = 2 * index
            val rightIndex = 2 * index + 1
            var largestOfIndex = index // assume root node has big value
            // check left child
            if (leftIndex <= size && arr[largestOfIndex] < arr[leftIndex]) {
                largestOfIndex = leftIndex
            }
            // check right child
            if (rightIndex <= size && arr[largestOfIndex] < arr[rightIndex]) {
                largestOfIndex = rightIndex
            }

            //if no change
            if (index == largestOfIndex) {
                break
            } else {
                swap(index, largestOfIndex)
                index = largestOfIndex
            }
        }
        return answer
    }

    private fun swap(i: Int, j: Int) {
        val temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    }
}

fun main() {
    val h = Heap(20)
    h.insert(10)
    h.insert(20)
    h.insert(5)
    h.insert(11)
    h.insert(6)
    
    println("Printing the content of Heap:")
    h.printHeap()

    val deletedElement = h.deleteFromHeap()
    println("Deleted element: $deletedElement")
    
    println("Printing the content of heap:")
    h.printHeap()
}

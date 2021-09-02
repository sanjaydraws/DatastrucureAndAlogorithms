
// Find the minimum and maximum element in an array using minimum comparisons
class FindMinMaxElement {


    public static void findMinMaxElement(int[] arr ){
        int max = arr[0];
        int min = arr[0];

        for (int i = 0;i<arr.length;i++){
            if(arr[i] >max) {
                max = arr[i];
            }

            if(arr[i] <min){
                min = arr[i];
            }
        }
        System.out.println("max element " + max);
        System.out.println("min element " + min);
    }

    public static void main(String[] args) {
     
        int[] arr = {1,2,3,5,6,3};

        findMinMaxElement(arr);
        // max element 6
        // min element 1
    }   
}

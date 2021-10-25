// Kth smallest element 

public class Program3 {
 
    static void kThSmallestElement(int arr[]){
        int k=0,temp, smallestNumber;
        if(arr.length > 0)
            temp = arr[0];
        for(int i = 0; i <arr.length ;i++){
            if(temp<arr[i+1]){
                
                k++;
            }
        }
    }
    public static void main(String[] args) {
        int arr[] = {7, 10, 4, 3, 20, 15};
    
    }

}

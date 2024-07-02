public class radix {
    static void radixSort(int[] arr) {
        int max = getMax(arr);
        // for(int exp = 1; max/exp > 0; exp *= 10)
        //     countSort(arr, exp);
        int [] count = new int[max+1];
        for(int i=0;i<arr.length;i++)
            count[arr[i]]++;
        int k=0;
        for (int i=0;i<count.length;i++){
            while(count[i]--!=0){
                arr[k++]=i;
            }
        }
    }
    static int getMax(int[] arr) {
        int max = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
            if(arr[i] > max)
                max = arr[i];
        return max;
    }
    // static void countSort(int[] arr, int exp) {
    //     int n = arr.length;
    //     int output[] = new int[n];
    //     int count[] = new int[10];
    //     for(int i=0;i<n;i++)
    //         count[(arr[i]/exp)%10]++;
    //     for(int i=1;i<10;i++)
    //         count[i] += count[i-1];
    //     for(int i=n-1;i>=0;i--) {
    //         output[count[(arr[i]/exp)%10]-1] = arr[i];
    //         count[(arr[i]/exp)%10]--;
    //     }
    //     for(int i=0;i<n;i++)
    //         arr[i] = output[i];
    // }
     
    public static void main(String[] args) {
          int [] arr = {1,2,4,4,5,5,5,2,2,3,4,5,6,7,8,9,4,4,5};
          radixSort(arr);
          for(int i=0;i<arr.length;i++)
              System.out.print(arr[i]+" ");
    }}
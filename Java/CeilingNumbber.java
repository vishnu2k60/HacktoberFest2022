package Java;

public class CeilingNumbber {
    public static void main(String[] args) {
        int[] arr = {-6,2,3,4,7,9,14,26,36,39,44};
        int tar = 49;
        int ans = ceilingnum(arr , tar);
//        while(ans == -1) {
//            tar+=1;
//            ans = ceilingnum(arr , tar);
//        }
        System.out.println(ans);
    }

    static int ceilingnum (int[] arr, int tar){

        if (tar > arr[arr.length-1]) {
                return -1;
        }
        int start = 0;
        int end = arr.length-1;

        while(start<=end) {
            // mid = (start + end ) / 2
            int mid = start + (end - start) / 2;

            if (tar < arr[mid]) {
                end = mid - 1;
            }
            else if (tar > arr[mid]) {
                start = mid + 1;
            }
            else
                return mid;
        }

        return start;

    }
    
}

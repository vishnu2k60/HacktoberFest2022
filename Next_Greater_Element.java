public class Next_Greater_Element  {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        //Initialising hashmap
        HashMap<Integer, Integer> map = new HashMap<>();
        //Initialising stack
        Stack<Integer> stack = new Stack<Integer>();
        
        //Iterating over the array
         for(int i=0;i<nums2.length;i++){
             
           //Terminating condition
             while(!stack.isEmpty()){
                 
                //If the top of stack is of lesser value than the array element
                 if(stack.peek()<nums2[i]){
                     
                    //Adding to the hashmap
                     map.put(stack.pop(), nums2[i]);
                 }
                 else{
                     break;
                 }
             }
            //Pushing on the stack
             stack.push(nums2[i]);
             
             
         }
        
        //Initializing array
        int[] arr=new int[nums1.length];
        
        //Iterating the array
        for(int i=0;i<nums1.length;i++){
            
            //FILLING THE NEW ARRAY WITH HASHMAP VALUES
            arr[i] = map.getOrDefault(nums1[i], -1);
        }
        
       // returning the answer array
        return arr;
        
    }
}

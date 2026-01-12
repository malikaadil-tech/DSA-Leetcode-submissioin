class Solution {
public:
    bool isEven(int n) {
    return n % 2 == 0;
    }
    int singleNonDuplicate(vector<int>& nums) {
        // (optimisatin through binary search )
        int n = nums.size();
        // check sepratrely for edge cases to avoid 
        if(n ==1)return nums[0];
        // check for first element 
        if(nums[0]!=nums[1])return nums[0];
        //check for last element 
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int s = 1;
        int e = n-2;
        int mid= s+(e-s)/2;
        while(s<=e){
            if(nums[mid] != nums[mid+1] && nums[mid] !=nums[mid-1]){
                return nums[mid];
            }
            else if((mid % 2!=0 && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1])){
                // i m on the left half and element on the right half so remove left half
                s = mid+1;
            }  
            else{
                // so element on the left half 
                e = mid-1;
            } 
            mid = s+(e-s)/2;  
        }


                
      return -1;  
       
    }
};
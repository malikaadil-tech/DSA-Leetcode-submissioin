class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       // b 
       int n =nums.size();
       int ans =0;
       
       int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            if(nums[i]> maxi){
                maxi = nums[i];
                ans = i;
            }

        
        }
      

        return ans;
    }
};
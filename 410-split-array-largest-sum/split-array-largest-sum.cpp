class Solution {
public:
// this is min(max) pattern
    int noSubarrays(vector<int>&nums,int lsum){
        int noSubArray = 1;
        int sum =0;
        for(int i =0;i<nums.size();i++){
            if(sum+nums[i]<=lsum){
                sum+=nums[i];
            }
            else{
                noSubArray++;
                sum = nums[i];
            }
        }
        return noSubArray;
    }
    int splitArray(vector<int>& nums, int k) {
        int low  = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans =-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int subArray = noSubarrays(nums,mid);
            if(subArray<=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;

        
    }
};
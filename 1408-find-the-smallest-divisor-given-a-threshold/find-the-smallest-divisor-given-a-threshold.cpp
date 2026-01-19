class Solution {
public:
int result(vector<int>& nums, int divisor){
    int result =0;
    for(int i =0;i<nums.size();i++){
        result = result+ ceil((double)nums[i]/(double)divisor);
    }
    return result;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n>threshold)return -1;
        int ans  = 1;
        int mini =1;
        int maxi = *max_element(nums.begin(),nums.end());
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
             if(result(nums,mid) <= threshold){
                ans = mid;
                maxi = mid-1;   
             }
             else{
                mini = mid+1;
             }

        }
        return ans ;

        
    }
};
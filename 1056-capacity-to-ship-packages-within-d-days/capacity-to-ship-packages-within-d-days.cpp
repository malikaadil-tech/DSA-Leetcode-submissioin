class Solution {
public:
    bool isPossible(vector<int>& weights,int capacity, int days){
        int sum =0;
        int n =weights.size();
        int dayUsed  = 1;
        for(int i =0;i<n;i++){
            if((sum + weights[i])>capacity){
                dayUsed = dayUsed+1;
                sum = weights[i];
            }
            else{
                sum+=weights[i];   
            }
        }
        if(dayUsed > days){
            return false;
        }
        else{
            return true;
        }
       
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(),weights.end());
        int maxi =  std::accumulate(weights.begin(), weights.end(), 0);
        int ans  =-1;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2; 
            if(isPossible(weights,mid, days)){
                ans = mid;
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return ans;
        
    }
};
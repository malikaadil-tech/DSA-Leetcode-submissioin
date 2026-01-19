class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day,int m, int k){
        int n = bloomDay.size();
        int cnt=0;
        int nB=0;
       for(int i =0;i<n;i++){
            if(bloomDay[i]<=day){
               cnt++;
            }
             else{
                 nB =  nB+(cnt/k);
                cnt=0;
            }
       }
       nB =  nB+(cnt/k);
       if(nB>=m){
           return true;
       }
       else{
           return false;
       }
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k>n){return -1;}
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        // by binary search 
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            if(isPossible(bloomDay,mid,m,k) == true){
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
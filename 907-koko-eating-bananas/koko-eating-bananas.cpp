class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i =0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long  countTotalHours(vector<int> &piles,int hourly){
        long long totalHour =  0;
        for(int i= 0;i<piles.size();i++){
            totalHour += (piles[i] + hourly - 1) / hourly;
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e  = findMax(piles);
        int ans  =1;
        while(s<=e){
            int mid = s+(e-s)/2;
            long long totalHour = countTotalHours( piles,mid);
            if(totalHour <=h){
                e = mid-1;  
            }
            else{
                s=mid+1;
            }
        }
       return s;
        
    }
};
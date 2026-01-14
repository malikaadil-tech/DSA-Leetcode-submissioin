class Solution {
public:
    bool isPerfectSquare(int num) {
        // binary search
        int s =1;
        int e = num;
        while(s<=e){
            int mid = s+(e-s)/2;
            long long val = (long long)mid*mid;
            if(val == num){
                return true;
            }
            else if(val >num){
                e = mid-1;
            }
            else{
                s =mid+1;
            }
            
        }
        return false;
        
    }
};
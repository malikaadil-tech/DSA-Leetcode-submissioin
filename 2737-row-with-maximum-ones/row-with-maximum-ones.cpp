class Solution {
public:
int lowerBound(vector<int>&arr ,int x){
    sort(arr.begin(),arr.end());
    int low  =0;
    int high = arr.size()-1;
    int ans = arr.size();
    while(low<=high){
        int mid  = low+(high-low)/2;
        if(arr[mid] >= x){
            ans = mid;
            // check smaller index on left 
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int index = 0;
        int max_cnt =0;
        for(int i =0;i<n;i++){
            int cnt_ones = m - lowerBound(mat[i],1);
            if(cnt_ones > max_cnt){
                max_cnt = cnt_ones;
                index= i;
            }
        }
        return {index, max_cnt};
    }  
};
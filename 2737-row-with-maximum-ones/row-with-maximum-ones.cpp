class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int index =-1;
        int max_cnt = -1;
        for(int i =0;i<n;i++){
            int cnt_row = 0;
            for(int j =0;j<m;j++){
                cnt_row+=mat[i][j];
            }
            if(cnt_row > max_cnt){
                max_cnt = cnt_row;
                index = i;
            }
        }
        return {index,max_cnt};
        
    }
};
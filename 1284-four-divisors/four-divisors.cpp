class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       
        int ans =0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            int count =0;
            int sum = 0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j == 0){
                    int j1= j;
                    int j2 = (nums[i]/j);
                    if(j1 == j2){// perfect square
                       count++;
                       sum = sum+j1;
                    }   
                    else{ // divisor pair
                        count= count+2;
                        sum = sum+j1+j2;
                    }
                    if(count > 4){break;}   
                }
            }
            if(count == 4){
                ans = ans+sum;
            }
            
        }
        return ans;       
    }
    
};
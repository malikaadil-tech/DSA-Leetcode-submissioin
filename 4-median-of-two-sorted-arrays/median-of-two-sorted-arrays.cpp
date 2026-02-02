class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size();
        int m = nums2.size();
        int k = n+m;
        int index2 = k/2;
        int index1= index2-1;
        int i =0;
        int j = 0;
        int indexele1 = -1;
        int indexele2 = -1;
        int cnt =0;
        while(i<n && j<m){
            if(nums1[i]< nums2[j]){
                if(cnt == index1) indexele1 = nums1[i];
                if(cnt  == index2) indexele2 = nums1[i];
                cnt++;
                i++;
             }
            else{ if(cnt == index1) indexele1 = nums2[j];
                if(cnt  == index2) indexele2 = nums2[j];
                cnt++;
                j++;
            }
        }
        //remaining elements 
        while(i<n){
            if(cnt == index1) indexele1 = nums1[i];
            if(cnt  == index2) indexele2 = nums1[i];
                cnt++;
                i++;
        }
        while(j<m){
            if(cnt == index1) indexele1 = nums2[j];
            if(cnt  == index2) indexele2 = nums2[j];
                cnt++;
                j++;
        }
        // check whether k is odd or even npw 
        if(k%2 == 1){
            // k is odd
            return indexele2;
        }
        else{
            return (double)(double)(indexele1 + indexele2)/2.0;
        }



    
        
    }
};
class Solution {
public:
    string largestOddNumber(string num) {
        int index=-1;
        for(int i = num.size()-1;i>=0;i--){
            if((num[i]-'0')%2 == 1){
                index = i;
                break;  
            }
        }
         //skiping leading zeros upto odd digit 
         int i = 0;
         while(i<=index && num[i] == '0')i++;
        // return substring of largest odd number 
        //string.substr(start_index, length)
         return num.substr(i,index-i+1);
   
    }
};
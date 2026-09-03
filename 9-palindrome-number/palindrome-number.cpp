class Solution {
public:
    int reverseNumber(int n){
    int num  =0;
    if(n == 0) return 0;
    while(n!=0){
        int digit = n%10;
        // check for overflow 
        // overflow for positive no 
        if((num >INT_MAX/10)|| (num  == INT_MAX/10) && digit>7) return 0;
        // overflow for negative no 
        if((num<INT_MIN/10)||(num == INT_MIN/10) && digit < -8) return 0;
        num = num*10+digit;
          n = n/10;
    }
   return num;
}
// palindrome number 
bool  isPalindrome(int n){
    if(n<0) return false;
    if(n == reverseNumber(n)){
        return true;
    }
    else{
        return false;
    }

}
};
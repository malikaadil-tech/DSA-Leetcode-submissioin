class Solution {
public:
    int myAtoi(string s) {
        long long num =0;
        bool negative =false;
        bool started = false;// this is for when we start getting actualno 
        for(int i=0;i<s.size();i++){
            // ignore leading space 
            if(s[i]==' ' && !started){
                //leadind space ingnore this
                continue; 
            }
            // check sign
            else if((s[i] == '-' || s[i]=='+') && !started){
                started = true;
                if(s[i]== '-'){
                    negative = true;
                }
                continue;
            }
            // digit 
             if(isdigit(s[i])){
                started = true;
                int digit = s[i]-'0'; // convert character into digit 
                // set limit for checking overflow 
                long long limit;
                if(negative){
                    limit = -(long long)INT_MIN;

                }
                else{
                    limit = INT_MAX;
                }

                // check overflow before updating num so that it remain in range
                if(num>limit/10 || (num == limit/10 && digit>limit%10)){
                    if(negative){
                        return INT_MIN;
                    }
                    else{
                        return INT_MAX;
                    }
                }
                num=num*10+(s[i]-'0');
            }
            // any other character break
            else{
                break;
            }

        }
        // if there is a negative sign apply 
    if(negative){
        num=-num;
    }
     return (int)num;   
    }
};
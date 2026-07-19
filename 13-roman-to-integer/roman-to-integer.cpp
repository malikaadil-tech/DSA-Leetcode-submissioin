class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanNo;
      romanNo['I'] = 1;
       romanNo['V'] = 5;
       romanNo['X'] = 10;
        romanNo['L'] = 50;
        romanNo['C'] = 100;
        romanNo['D'] = 500;
        romanNo['M'] = 1000;
        int intNo = 0;
        for( int i=0;i<=s.length()-1;i++){
            if((i==s.length()-1) || (romanNo[s[i]]>=romanNo[s[i+1]])){
                intNo = intNo + romanNo[s[i]];
            }
            else if(i < s.length()-1 &&romanNo[s[i]]<romanNo[s[i+1]]){
                intNo = intNo +( romanNo[s[i+1]]-romanNo[s[i]]);
                i++;
            }
        }
        return intNo;
        
        
    }
};
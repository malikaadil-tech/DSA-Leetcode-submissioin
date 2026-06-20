class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
       // optimal approach 
       // double the string 
        string doubled = s+s;
       // iterate string and check with goal 
        if (doubled .find(goal) != -1)
        return true;

    return false;

        
    }
};
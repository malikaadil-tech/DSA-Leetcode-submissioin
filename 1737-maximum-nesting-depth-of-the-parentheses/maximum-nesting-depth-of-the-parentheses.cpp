class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int curDepth = 0;
        for(char ch:s){
            if(ch == '('){
                curDepth++;
                maxDepth = max(maxDepth,curDepth);
            }
            else if(ch == ')'){
                curDepth--;
                maxDepth = max(maxDepth,curDepth);
            }
        }
        return maxDepth;
        
    }
};
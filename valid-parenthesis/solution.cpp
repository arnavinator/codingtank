#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // must cover condition such as {()}  being TRUE
        stack<char> stk;
        for(int i=0; i<s.size(); i++) {
            switch(s[i]) {
                // whenever we see the first end bracket, its counterpart better be on top of stack!
                case '{':  
                    stk.push('}'); 
                    break;
                case '[':  
                    stk.push(']'); 
                    break;
                case '(':  
                    stk.push(')'); 
                    break;
                default:
                    if (stk.empty() || s[i] != stk.top())  // condition not satisified
                        return false;
                    else  // counterpart found, remove from stack to prep for next end bracket
                        stk.pop();
            }
        }
        return stk.size();        
    }

};

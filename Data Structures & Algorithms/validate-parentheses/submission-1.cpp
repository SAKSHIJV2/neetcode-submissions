class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        int top=-1;
        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){
                stac.push(c);
            }
            else{
                if(stac.empty()){
                    return false;
                }
                if(c==')' && stac.top()!='('){
                    return false;
                }
                if(c == ']' && stac.top() != '[')
                    return false;

                if(c == '}' && stac.top() != '{')
                    return false;

                stac.pop();
            }
        }
        
        return stac.empty();
    }
    
};

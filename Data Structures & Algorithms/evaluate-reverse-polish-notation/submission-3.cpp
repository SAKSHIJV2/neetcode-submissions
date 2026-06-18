class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c:tokens){
            if(c!="+" && c!="-" && c!="*" && c!="/"){
                st.push(stoi(c));
            }
            else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(c=="+"){    
                    st.push(op1+op2);
                }
                else if(c=="-"){
                    st.push(op1-op2);
                }
                else if(c=="*"){
                    st.push(op1*op2);
                }
                else if(c=="/"){
                    st.push(op1/op2);
                }
            }
        }
        return st.top();
    }
};

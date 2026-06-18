class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c:tokens){
            if(c!="+" && c!="-" && c!="*" && c!="/"){
                st.push(stoi(c));
            }
            else{
                if(st.empty()){
                    return 0;
                }

                if(c=="+"){
                    int op2=st.top();
                    st.pop();
                    int op1=st.top();
                    st.pop();
                    st.push(op1+op2);
                }
                if(c=="-"){
                    int op2=st.top();
                    st.pop();
                    int op1=st.top();
                    st.pop();
                    st.push(op1-op2);
                }
                if(c=="*"){
                    int op2=st.top();
                    st.pop();
                    int op1=st.top();
                    st.pop();
                    st.push(op1*op2);
                }
                if(c=="/"){
                    int op2=st.top();
                    st.pop();
                    int op1=st.top();
                    st.pop();
                    st.push(op1/op2);
                }
            }
        }
        return st.top();
    }
};

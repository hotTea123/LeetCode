class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> cor= {{'{', '}'},{'(',')'},{'[',']'}};
        for(char c:s){
            if(c == '{' || c=='(' || c=='[')
                st.push(c);
            else{
                if(st.empty() || cor[st.top()] != c)
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
class Solution {
   public:
    bool isnum(string s) {
        int n = s.size();
        for (int i = 1; i < n; i++)
            if (!isdigit(s[i]))
                return false;
        return isdigit(s[0]) || (s[0] == '-' && n > 1);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (isnum(tokens[i]))
                st.push(stoi(tokens[i]));
            else {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(n1 + n2);
                else if (tokens[i] == "-")
                    st.push(n1 - n2);
                else if (tokens[i] == "*")
                    st.push(n1 * n2);
                else if (tokens[i] == "/")
                    st.push(n1 / n2);
            }
        }
        return st.top();
    }
};
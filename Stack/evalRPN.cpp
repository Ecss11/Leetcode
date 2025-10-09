class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string token : tokens) {
            int n1, n2;
            if (token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/") {
                n1 = stoi(st.top());
                st.pop();
                n2 = stoi(st.top());
                st.pop();
            } else {
                st.push(token);
                continue;
            }

            int n3;
            if (token == "+") {
                n3 = n2 + n1;
                st.push(to_string(n3));
            } else if (token == "-") {
                n3 = n2 - n1;
                st.push(to_string(n3));
            } else if (token == "*") {
                n3 = n2 * n1;
                st.push(to_string(n3));
            } else {
                n3 = n2 / n1;
                st.push(to_string(n3));
            }
        }

        int result = stoi(st.top());
        return result;
    }
};
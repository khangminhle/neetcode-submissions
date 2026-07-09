class Solution {
public:
    bool checkOperators(string s) {
        if(s == "+") return true;
        if(s == "-") return true;
        if(s == "*") return true;
        if(s == "/") return true;

        return false;
    }

    int do_operator(string s1, string s2, string op) {
        int numb1 = stoi(s1);
        int numb2 = stoi(s2);
        if(op == "+") {
            return numb1 + numb2;
        }
        if(op == "-") {
            return numb1 - numb2;
        }
        if(op == "*") {
            return numb1 * numb2;
        }
        if(op == "/") {
            return numb1 / numb2;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<string> st;

        for(int i = 0; i < n; i++) {
            if(checkOperators(tokens[i])) {
                string s1 = st.back();
                st.pop_back();
                string s2 = st.back();
                st.pop_back();
                int numb = do_operator(s2, s1, tokens[i]);

                st.push_back(to_string(numb));
            } else {
                st.push_back(tokens[i]);
            }
        }

        return stoi(st.back());
    }
};

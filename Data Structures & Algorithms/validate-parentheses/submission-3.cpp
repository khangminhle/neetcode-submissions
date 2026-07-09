class Solution {
public:
    bool isValid(string s) {
        vector<char> paren;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '{') {
                paren.push_back('}');
                continue;
            }

            if(s[i] == '(') {
                paren.push_back(')');
                continue;
            }

            if(s[i] == '[') {
                paren.push_back(']');
                continue;
            }

            if(paren.empty()) return false;

            if(s[i] != paren.back()) {
                return false;
            } else {
                paren.pop_back();
            }
        }

        if(paren.empty()) return true;

        return false;
    }
};

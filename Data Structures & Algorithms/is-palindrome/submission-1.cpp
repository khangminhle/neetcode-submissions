class Solution {
public:
    char getValidChar(char c) {
        if(c >= '0' && c <= '9') return c;
        if(c >= 'a' && c <= 'z') return c;
        if(c >= 'A' && c <= 'Z') return c + 32;
        return '.';
    }
    bool isPalindrome(string s) {
        int n = s.size();
        

        string new_string;
        new_string.reserve(n);
        for(int i = 0; i < n; i++) {
            char c = getValidChar(s[i]);
            if(c != '.') {
                new_string.push_back(c);
            }
        }
        int l = 0;
        int r = new_string.size()-1;
        while(l <= r) {
            if(new_string[l] != new_string[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
};

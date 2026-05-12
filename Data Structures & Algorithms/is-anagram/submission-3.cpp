class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) {return false;}

        unordered_map<char, int> hmS;
        unordered_map<char, int> hmT;

        for(int i = 0; i < s.size(); i++) {
            if(hmS.count(s[i]) > 0) {
                hmS[s[i]] += 1;
            } else {
                hmS[s[i]] = 0;
            }
        }

        for(int i = 0; i < t.size(); i++) {
            if(hmT.count(t[i]) > 0) {
                hmT[t[i]] += 1;
            } else {
                hmT[t[i]] = 0;
            }
        }

        if(hmS == hmT) {return true;}

        return false;
    }
};
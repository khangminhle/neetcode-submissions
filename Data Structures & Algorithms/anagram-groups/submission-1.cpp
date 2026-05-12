class Solution {
public:

    bool isAnagram(string a, string b) {
        // Check the length of 2 strings
        if(a.size() != b.size()) {return false;}

        unordered_map<char, int> hmA;
        unordered_map<char, int> hmB;
        int n = a.size();

        for(int i = 0; i < n; i++) {
            if(hmA.count(a[i]) > 0) {
                hmA[a[i]] += 1;
            } else {
                hmA[a[i]] = 0;
            }

            if(hmB.count(b[i]) > 0) {
                hmB[b[i]] += 1;
            } else {
                hmB[b[i]] = 0;
            }
        }

        if(hmA == hmB) {return true;}

        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result {};
        unordered_set<int> checkedIndexes;

        for(int i = 0; i < strs.size(); i++) {

            if(checkedIndexes.count(i) > 0) {continue;}

            vector<string> groupAnagrams = {strs[i]};
            for(int j = i+1; j < strs.size(); j++) {

                if(checkedIndexes.count(j) > 0) {continue;}

                if(isAnagram(strs[i], strs[j])) {
                    groupAnagrams.push_back(strs[j]);
                    checkedIndexes.insert(j);
                }

            }

            result.push_back(groupAnagrams);
        }

        return result;
    }
};
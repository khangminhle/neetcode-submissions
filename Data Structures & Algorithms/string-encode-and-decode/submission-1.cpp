class Solution {
public:
    string encode(vector<string> &strs) {
        int n = strs.size();

        string encode = "";
        char delimiter = '#';

        for(int i = 0; i < n; i++) {
            string str = strs[i];
            encode += to_string(str.size()) + delimiter + str;
        }

        return encode;
    }

    vector<string> decode(string s) {
        int n = s.size();

        if(n == 0) {
            return {};
        }

        vector<string> strs;
        int startIndex = 0;
        char delimiter = '#';
        
        int i = startIndex;
        for(; i < n; i++) {
            if(s[i] == delimiter) {
                //cout<<"i: "<<i<<endl;
                int len = stoi(s.substr(startIndex,i-startIndex));

                //cout<<"len: "<<len<<endl;
                //cout<<str.substr(i+1, len)<<endl;

                strs.push_back(s.substr(i+1, len));

                startIndex =(i+1+len);
                i = startIndex;
                //cout<<startIndex<<endl;
            }
        }

        return strs;
    }
};
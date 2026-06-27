class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = 9;
        int cols = 9;

        unordered_map<char, vector<pair<int, int>>> hm;


        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                //cout<<board[i][j]<<' ';
                if(board[i][j] != '.') {
                    hm[board[i][j]].push_back({i, j});
                }
            }
            //cout<<endl;
        }

        for(int i = 1; i <= 9; i++) {
            char number = '0' + i;
            int n = hm[number].size();

            for(int j = 0; j < n-1; j++) {
                //cout<<"number: "<<hm[number][j].first<<" "<<hm[number][j].second<<endl;
                for(int k = j+1; k < n; k++) {
                    //cout<<"numb: "<<hm[number][k].first<<" "<<hm[number][k].second<<endl;

                    if(hm[number][k].first == hm[number][j].first) {

                        return false;
                    }

                    if(hm[number][k].second == hm[number][j].second) {
                        return false;
                    }

                    if((hm[number][k].first)/3 == (hm[number][j].first)/3) {
                        if((hm[number][k].second)/3 == (hm[number][j].second)/3) {
                            //cout<<"region"<<endl;
                            return false;
                        }
                    }
                }
            }

        }

        //cout<<"true"<<endl;

        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int num_row = 9;
        int num_col = 9;

        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool regions[9][9] = {false};

        for(int i = 0; i < num_row; i++) {
            for(int j = 0; j < num_col; j++) {
                //cout<<board[i][j]<<' ';
                if(board[i][j] == '.') continue;
                int number = board[i][j] - '1';
                //cout<<"number: "<<number<<endl;
                int regionID = (i/3)*3 + (j/3);
                //cout<<"regionID: "<<regionID;

                if(rows[number][i]) return false;
                if(cols[number][j]) return false;
                if(regions[number][regionID]) return false;


                rows[number][i] = true;
                cols[number][j] = true;
                regions[number][regionID] = true;

            }
            //cout<<endl;
        }

        return true;
    }
};
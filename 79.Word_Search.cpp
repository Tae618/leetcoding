class Solution {
private:
    bool searchWord(vector<vector<char>> board, string word, int i,int j, int k)
    {
        if(i<0 || j<0)
            return false;
        if(i>=board.size() || j>=board[0].size() || k>=word.size())
            return false;
        if(board[i][j]=='\0' || board[i][j]!=word[k])
            return false;
        char temp = board[i][j];
        board[i][j]='\0';
        if(k==word.size()-1)
            return true;
        if(searchWord(board, word, i-1,j,k+1) || searchWord(board, word, i+1,j,k+1) || searchWord(board, word, i,j-1,k+1) || searchWord(board, word, i, j+1,k+1))
        {
            return true;
        }
       
        board[i][j] = temp;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size()==0 || board[0].size()==0 || word.size()==0)
            return word=="";
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(searchWord(board, word,i,j,0))
                        return true;
                }
            }
        }
        //cout<<"At here!!!"<<endl;
        return false;
    }
};

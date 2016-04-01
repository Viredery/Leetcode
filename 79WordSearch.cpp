class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        vector< vector<char> >::iterator p_vector = board.begin();
        while(p_vector != board.end()) {
            vector<char>::iterator p = p_vector->begin();
            while(p != p_vector->end()) {
                vector<char>::iterator result = find(p, p_vector->end(), word[0]);
                if(result != p_vector->end()) {
                    string::iterator p_word = word.begin() + 1;
                    int m = board.end() - board.begin();
                    int n = p_vector->end() - p_vector->begin();
                    vector<int> tmp(n,0);
                    vector< vector<int> > visited(m,tmp);
                    if(func(board,word,p_word,result,p_vector,visited) == true)
                        return true;
                    p = result + 1;
                }
                else
                    p = result;
            }
            p_vector++;
        }
        return false;
    }
    bool func(vector< vector<char> >& board,string &word,string::iterator p_word,vector<char>::iterator result,vector< vector<char> >::iterator p_vector, vector< vector<int> > &visited) {
        if(p_word == word.end())
            return true;
        else {
            int m = p_vector - board.begin();
            int n = result - p_vector->begin();
            visited[m][n] = 1;
            int m_max = board.end() - board.begin();
            int n_max = p_vector->end() - p_vector->begin();
            if(m - 1 >= 0 && board[m-1][n] == *p_word && visited[m-1][n] == 0)
                if(func(board, word, p_word+1, (p_vector-1)->begin()+n, p_vector-1, visited) == true)
                    return true;
            if(m + 1 != m_max && board[m+1][n] == *p_word && visited[m+1][n] == 0)
                if(func(board, word, p_word+1, (p_vector+1)->begin()+n, p_vector+1, visited) == true)
                    return true;
            if(n - 1 >= 0 && board[m][n-1] == *p_word && visited[m][n-1] == 0)
                if(func(board, word, p_word+1, result-1, p_vector, visited) == true)
                    return true;
            if(n + 1 != n_max && board[m][n+1] == *p_word && visited[m][n+1] == 0)
                if(func(board, word, p_word+1, result+1, p_vector, visited) == true)
                    return true;
            visited[m][n] = 0;
            return false;
        }
    }
};

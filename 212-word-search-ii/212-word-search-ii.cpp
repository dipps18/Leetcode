class Trie{
public:
    Trie* root[26] = {nullptr};
    bool isEnd = false;    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* node = new Trie();
        BuildTrie(node, words);
        vector<string> res;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                dfs(res, board, node, i, j, "");
            }

        }
        return res;
    }
    
    void dfs(vector<string>& res, vector<vector<char>>& board, Trie* node, int i, int j, string word)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == '*') return;
        char ch = board[i][j] - 'a';
        if(!node->root[ch]) return;
        word.push_back(ch + 'a');
        if(node->root[ch]->isEnd)
        {
            res.push_back(word);
            node->root[ch]->isEnd = false;
        }
        board[i][j] = '*';
        dfs(res, board, node->root[ch], i + 1, j, word);
        dfs(res, board, node->root[ch], i - 1, j, word);
        dfs(res, board, node->root[ch], i, j + 1, word);
        dfs(res, board, node->root[ch], i, j - 1, word);
        board[i][j] = ch + 'a';
    }
    
    void BuildTrie(Trie* root, vector<string> &words)
    {
        Trie* node;
        for(int i = 0; i < words.size(); i++)
        {
            node = root;
            for(int j = 0; j < words[i].size(); j++)
            {
                int ch = words[i][j] - 'a';
                if(!node->root[ch]) node->root[ch] = new Trie();
                node = node->root[ch];
            }
            node->isEnd = true;
        }
    }
};
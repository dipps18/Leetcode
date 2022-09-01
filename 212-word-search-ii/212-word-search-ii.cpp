class Trie{
public:
    Trie* root[26] = {nullptr};
    string word;
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
                dfs(res, board, node, i, j);
            }
        }
        return res;
    }
    void dfs(vector<string>& res, vector<vector<char>>& board, Trie* node, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*') return;
        int ch = board[i][j] - 'a';
        if(!node->root[ch]) return;
        if(!node->root[ch]->word.empty())
        {
            res.push_back(node->root[ch]->word);
            node->root[ch]->word = "";
        }
        board[i][j] = '*';
        dfs(res, board, node->root[ch], i + 1, j);
        dfs(res, board, node->root[ch], i - 1, j);
        dfs(res, board, node->root[ch], i, j + 1);
        dfs(res, board, node->root[ch], i, j - 1);
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
            node->word = words[i];
        }
    }
};
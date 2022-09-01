class Trie{
public:
    unordered_map<int, Trie*>root;
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
                bool found = false;
                dfs(res, board, node, i, j, "", found);
            }

        }
        return res;
    }
    
    void dfs(vector<string>& res, vector<vector<char>>& board, Trie* node, int i, int j, string word, bool& found)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == '*') return;
        char ch = board[i][j] - 'a';
        if(node->root.find(ch) == node->root.end()) return;
        word.push_back(ch + 'a');
        if(node->root[ch]->isEnd)
        {
            res.push_back(word);
            if(node->root[ch]->root.size() == 0)
            {
                node->root.erase(ch);
                return;
            }
            else
                node->root[ch]->isEnd = false;
        }
        board[i][j] = '*';
        dfs(res, board, node->root[ch], i + 1, j, word, found);
        dfs(res, board, node->root[ch], i - 1, j, word, found);
        dfs(res, board, node->root[ch], i, j + 1, word, found);
        dfs(res, board, node->root[ch], i, j - 1, word, found);
        board[i][j] = ch + 'a';
        if(found && node->root[ch]->root.size() == 0)
        {
            node->root.erase(ch);
        }
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
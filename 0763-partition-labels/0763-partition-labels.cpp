class Solution {
public:
    vector<int> partitionLabels(string s) {
        int dict[26];
        std::vector<int> res;
        for(int i = 0; i < s.size(); i++)
        {
            dict[s[i] - 'a'] = i;
        }
        
        int curStart = 0, curEnd = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if(i > curEnd)
            {
                res.push_back(curEnd - curStart + 1);
                curStart = i;
                curEnd = dict[idx];
            }
            else
                curEnd = max(curEnd, dict[idx]);
        }
        res.push_back(curEnd - curStart + 1);
        return res;
    }

    // Alternative method O(n) + 26log(26) + O(26) - Maybe slightly better for large values for n since it requires only one pass
    // vector<int> partitionLabels(string s) {
    //     std::vector<std::vector<int>> interval(26, std::vector<int>(2, -1));
    //     std::vector<int> labels;
    //     int curGroupStart = 0, curGroupEnd = -1;
    //     for(int i = 0; i < s.size(); i++)
    //     {
    //         int idx = s[i] - 'a';
    //         if(interval[idx][0] != -1)
    //             interval[idx][1] = i;
    //         else
    //         {
    //             interval[idx][0] = i;
    //             interval[idx][1] = i;
    //         }
    //     }

    //     struct
    //     {
    //         bool operator()(std::vector<int> a, 
    //                         std::vector<int> b) const 
    //         { 
    //             return a[0] < b[0]; 
    //         }
    //     }customLess;
    //     sort(interval.begin(), interval.end(), customLess);
    //     for(int i = 0; i < 25; i++)
    //     {
    //         if(interval[i][0] == -1)
    //             continue;

    //         if(interval[i][1] > interval[i + 1][0])
    //         {
    //             curGroupEnd = max(interval[i][1], interval[i + 1][1]);
    //             interval[i + 1][1] = curGroupEnd;
    //         }
    //         else
    //         {
    //             curGroupEnd = interval[i][1];
    //             labels.push_back(curGroupEnd - curGroupStart + 1);
    //             curGroupStart = interval[i + 1][0];
    //             curGroupEnd = interval[i + 1][1];
    //         }
    //     }
    //     labels.push_back(curGroupEnd - curGroupStart + 1);
    //     return labels;
    // }
};
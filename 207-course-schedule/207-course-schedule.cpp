class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        vector<vector<int>> courses(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++)
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        for(int i = 0; i < courses.size(); i++)
            if(!helper(visited, courses, i)) return false;
        return true;
    }
    
    bool helper(unordered_set<int>& visited, vector<vector<int>>& courses, int& course)
    {
        if(!visited.insert(course).second) return false;
        for(int j = 0; j < courses[course].size(); j++)
        {
            if(!helper(visited, courses, courses[course][j])) return false;
        }
        courses[course].clear();
        visited.erase(course);
        return true;
    }
};
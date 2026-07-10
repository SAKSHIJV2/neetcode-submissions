class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> visiting;
    bool dfs(int courses){
        if(visiting[courses]){
            return false;
        }
        if(visited[courses]){
            return true;
        }
        visiting[courses]=true;
        for(auto next:graph[courses]){
            if(!dfs(next)){
                return false;
            }
        }
        visited[courses]=true;
        visiting[courses]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses,false);
        visiting.resize(numCourses,false);
        for(auto pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }
};

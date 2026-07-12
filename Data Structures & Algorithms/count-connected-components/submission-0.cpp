class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> graph;
    void dfs(int node){
        visited[node]=true;
        for(auto next:graph[node]){
            if(!visited[next]){
                dfs(next);
            }           
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        visited.resize(n,false);
        graph.resize(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i);
            }
        }
        return count;
    }
};

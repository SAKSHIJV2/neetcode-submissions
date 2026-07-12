class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool dfs(int node,int target){
        if(node==target){
            return true;
        }
        visited[node]=true;
        for(auto next:graph[node]){
            if(!visited[next]){
                if(dfs(next,target))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        graph.resize(edges.size()+1);
        visited.resize(edges.size()+1,false);
        for(auto it:edges){
            visited.assign(graph.size(),false);
            if(dfs(it[0],it[1])){
                return it;
            }
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
    }
};

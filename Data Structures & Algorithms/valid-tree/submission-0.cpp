class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool dfs(int node, int parent)
    {
        visited[node] = true;
        for(auto next : graph[node])
        {
            if(!visited[next])
            {
                if(!dfs(next, node))
                    return false;
            }
            else if(next != parent)
            {
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;
        graph.resize(n);
        visited.resize(n,false);
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        if(!dfs(0,-1))
            return false;
        for(bool v : visited)
        {
            if(!v)
                return false;
        }
        return true;
    }
};
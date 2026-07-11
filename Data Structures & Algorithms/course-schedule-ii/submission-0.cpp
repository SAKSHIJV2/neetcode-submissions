class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(auto pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        for(auto pre:prerequisites){
            indegree[pre[0]]++;
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto next:graph[curr]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};

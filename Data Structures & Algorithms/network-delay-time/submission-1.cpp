class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(n+1,INT_MAX);
        for(auto t:times){
            graph[t[0]].push_back({t[1],t[2]});
        }
        distance[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int time=curr.first;
            int node=curr.second;
            if(time>distance[node]){
                continue;
            }
            for(auto next:graph[node] ){
                int neighbour=next.first;
                int weight=next.second;
                int dist=weight+time;
                if(dist<distance[neighbour]){
                    distance[neighbour]=dist;
                    pq.push({dist,neighbour});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};
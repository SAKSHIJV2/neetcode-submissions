class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int distance=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            distance=x*x +  y*y;
            pq.push({distance,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto node=pq.top();
            ans.push_back({node.second.first,node.second.second});
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        queue<pair<pair<int,char>,int>> q;
        int time=0;
        int available_time=0;
        unordered_map<char,int> mp;
        for(auto it:tasks){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                auto task=pq.top();
                pq.pop();
                task.first--;
                available_time=n+1+time;
                if(task.first>0){
                    q.push({task,available_time});

                }
            }
            
        }       
        return time;
    }
};

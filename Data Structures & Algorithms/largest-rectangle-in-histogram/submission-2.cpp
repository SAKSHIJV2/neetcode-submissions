class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mono;
        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<=n;i++){
            int curr;
            if(i==n){
                curr=0;
            }
            else{
                curr=heights[i];
            }
            
            while(!mono.empty() && curr < heights[mono.top()]){
                int height=heights[mono.top()];
                mono.pop();
                int next=i;
                int prev;
                if(mono.empty()){
                    prev=-1;
                }
                else{
                    prev=mono.top();
                }
                int width=next-prev-1;
                int area=height*width;
                maxarea=max(area,maxarea);
            }
            mono.push(i);
        }
        return maxarea;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] =0;
        for( int i=1;i<n;++i){
            for(auto& edge: times){
                if(dist[edge[0]] != INT_MAX && dist[edge[0]]+edge[2]<dist[edge[1]]){
                    dist[edge[1]] = dist[edge[0]]+ edge[2];
                }
            }
        }
        int res= 0;
        for(int i= 1;i<= n; ++i){
            if(dist[i] == INT_MAX) return -1;
            res =max(res, dist[i]);
        }
        return res;
    }
};
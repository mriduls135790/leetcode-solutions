class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& f: flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src] =0;
        queue<pair<int, int>> q;
        q.push({src,0});
        int flights_taken= 0;
        while(!q.empty() && flights_taken <= k){
            int sz= q.size();
            while(sz--){
                auto[u, cost] =q.front();
                q.pop();
                for(auto& [v, wt]: adj[u]){
                    if(cost + wt < dist[v]){
                        dist[v] = cost +wt;
                        q.push({v, dist[v]});
                    }
                }
            }
            flights_taken++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
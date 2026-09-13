class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int> color (n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !dfs(i, 0 , color,graph)) return false;
        }
        return true;   
    }
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph){
        color[node] =c;
        for(int nei: graph[node]){
            if(color[nei] == -1){
                if(!dfs(nei, 1-c, color, graph)) return false;
            } else if(color[nei] == color[node]){
                return false;
            }
        }
        return true;
    }
};
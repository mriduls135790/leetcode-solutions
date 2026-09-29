class Solution {
public:
int findParent(int node, vector<int>& parent){
    if(node ==parent[node]) return node;
    return parent[node] =findParent(parent[node], parent);
}
void unionNodes(int u, int v, vector<int>& parent, vector<int>& size){
    int rootU= findParent(u, parent);
    int rootV= findParent(v,parent);
    if(rootU!= rootV){
        if (size[rootU]< size[rootV]){
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else{
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), size(n,1);
        for(int i=0;i<n;i++) parent[i]= i;
        unordered_map<string,int> emailToIdx;
        for(int i= 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
            string email= accounts[i][j];
            if(emailToIdx.find(email) != emailToIdx.end()){
                unionNodes(i, emailToIdx[email], parent, size);
            } else{
                emailToIdx[email] =i;
            }
        } 
    }
    unordered_map<int, vector<string>> merged;
    for(auto it: emailToIdx){
        int root =findParent(it.second, parent);
        merged[root].push_back(it.first);
    }
    vector<vector<string>> res;
    for(auto it: merged){
        vector<string> temp =it.second;
        sort(temp.begin(), temp.end());
        temp.insert(temp.begin(), accounts[it.first][0]);
        res.push_back(temp);
    }
    return res;  
    }
};
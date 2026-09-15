class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& edge : prerequisites){
            int course =edge[0];
            int prerequisite= edge[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i= 0; i<numCourses;i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        vector<int> answer(numCourses);
        int index=0;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            answer[index++] =curr;
            for(int neighbour : graph[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(index != numCourses){
            return {};
        }
        return answer;
    }
};
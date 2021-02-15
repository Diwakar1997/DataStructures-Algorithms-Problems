//https://leetcode.com/problems/minimum-height-trees/submissions/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<set<int>> graph(n);
        vector<int> result;
        if(n < 2) {
            
            for(int i = 0; i < n; i++) {
                result.push_back(i);
            }
            
            return result;
        }
        for(auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        queue<int> leaves;
        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 1) {
                leaves.push(i);
            }
        }
        int rem = n;
        while(rem > 2) {
            queue<int> q;
            rem -= leaves.size();
            while(!leaves.empty()) {
                int v = leaves.front();
                leaves.pop();
                for(auto it = graph[v].begin(); it != graph[v].end(); it++) {
                    int n = *it;
                    graph[v].erase(n);
                    graph[n].erase(v);
                    if(graph[n].size() == 1) {
                        q.push(n);
                    }
                }
            }
            leaves.swap(q);
        }
        while(!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};
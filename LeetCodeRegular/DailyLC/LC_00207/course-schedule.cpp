class Solution {

private:
    vector<vector<int>> edges;
    vector<int> status;
    vector<int> result;
    bool valid = true;

public:
    void dfs(int u){
        status[u] = 1;
        for(int v: edges[u]){
            if(status[v] == 0){
                dfs(v);
                if(!valid){
                    return;
                }
            }
            else if(status[v] == 1){
                valid = false;
                return;
            }
        }
        status[u] = 2;
        result.push_back(u);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        status.resize(numCourses);

        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
        }

        for(int i = 0; i <numCourses && valid; i++){
            if(!status[i]){
                dfs(i);
            }
        }

        if(!valid){
            return false;
        }
        return true;
    }
};

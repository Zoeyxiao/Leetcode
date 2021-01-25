/*
547. 省份数量
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。
*/

class UnionFind{
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    //int sum =0;

    UnionFind(int n): count(n), parent(vector<int>(n)), rank(vector<int>(n)){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        if(x != parent[x]){
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx != rooty){
            if(rank[rootx] <= rank[rooty]){
                //parent[rootx] = rooty;
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if(rank[rootx] == rank[rooty]){
                rank[rootx] += 1;
            }
            //}else{
            //   parent[rooty] = rootx;   
            //}
            count--;
        }
    }

    int getCount(){
        return count;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i = 0 ; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j]){
                    uf.Union(i, j);
                }
            }   
        }
        return uf.getCount();    
    }
};


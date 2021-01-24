/*
用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。
如果不可能，则返回 -1 。 

 

示例 1：
输入：n = 4, connections = [[0,1],[0,2],[1,2]]
输出：1
解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
*/




class UnionFind{
public:
    vector<int> parent;
    vector<int> rank;
    int setCount;
    int rest;
    
    UnionFind(int n): setCount(n), parent(vector<int>(n)), rank(vector<int>(n)), rest(0){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            //rank[i] = 1;
            //setCount++;
        }
    }
    //路径压缩
    int Find(int x){
        if(x != parent[x]){
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    //按秩合并
    void Union(int x, int y){
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx != rooty){
            if(rank[rootx] <= rank[rooty]){
                parent[rootx] = rooty;
            }else if(rank[rootx] == rank[rooty]){
                rank[rootx] += 1;
                //rank[rooty] += 1;
            }else{
                parent[rooty] == rootx;  
            }
            setCount--;
        }
        else{
            rest++; 
        }      
    }

    int getCount() {
        return setCount;
    }

    int getRest(){
        return rest;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);

        for (const auto& conn: connections) {
            uf.Union(conn[0], conn[1]);
        }
        if(uf.getRest() < uf.getCount()-1){
            return -1;
        }
        return uf.getCount() - 1;
    }
};

/*
959. 由斜杠划分区域
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
返回区域的数目。
*/


class UnionFind{
public:
    vector<int> parent;
    vector<int> rank;
    int count;

    UnionFind(int n): count(1), parent(n), rank(n){
        for(int i =0; i < n; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        if(parent[x] != x){
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y){
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx != rooty){
            if(rank[rootx] <= rank[rooty]){
                parent[rootx] = rooty;
            }else if(rank[rootx == rank[rooty]]){
                rank[rootx] += 1;
            }else{
                parent[rooty] = rootx;
            }
        }else{
            count++;
        }   
    }
    
    int getCount(){
        return count;
    }
};



class Solution {
public:
    int regionsBySlashes(vector<string>& grid){
        int n = grid.size();
        if(n ==0) return 0;
        //vector<int> node;
        //每行顶点数目
        int m = n + 1;
        //顶点总数
        int num = m * m;

        UnionFind uf(num + 1);
        //将所有边缘节点合并
        for(int i = 0; i < num; i++){
            if(i / m == 0 || i % m == 0 || i % m == m-1 || i / m == m-1){
                uf.Union(num, i);
            }
        }

        //访问每个单元网格
        for(int i = 0; i < n; i++){
            auto s = grid[i];
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '/'){
                    uf.Union((i+1)*m+j, i*m+j+1);
                }else if (s[j] == '\\'){
                    uf.Union(i*m+j, (i+1)*m+j+1);
                }
            }
        }

        return uf.getCount();
    }
};

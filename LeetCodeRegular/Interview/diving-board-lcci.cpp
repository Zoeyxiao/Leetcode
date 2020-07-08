class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
    //int divingBoard(int shorter, int longer, int k) {
        if(k == 0){
            return {};
        }
        if(shorter == longer){
            return vector <int> (1, shorter * k);
        }
        vector <int> length(k+1);
        if(shorter < longer && k>0){
            for(int i = 0; i <= k; ++i){
                length[i] = shorter * (k-i) + longer * i;
            }
        }
        return length;
    }
};

/*
解题思路：
若k=0, 则length为空值；
若shorter = longer, 则length = shorter * k = longer * k;
若shorter <= longer且k > 0， 则length = short * (k-i) + longer * i; 其中i为longer的个数；
其实就是一个简单的递归问题
*/

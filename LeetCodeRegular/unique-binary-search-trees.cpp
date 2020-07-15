class Solution {
public:
    int numTrees(int n) {
      vector<int> count(n+1,0);
      count[0] = 1;
      count[1] = 1;
    
      for(int i = 2; i <= n; i++){
          for(int j = 1; j <= i; j++ ){
              count[i] += count[j-1] * count[i-j]; 
          }
      }
      return count[n];
    }
};

/*
DP问题，重点在于怎么去实现迭代
核心思想在于怎么将主问题分成子问题来解决，不需要想得太过复杂，其实只要根节点确定之后，那么左右子树的组合数也就随之确定了
*/

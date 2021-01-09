/*
633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
解题思路：双指针，平方根
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        long  i = 0, j = sqrt(c);
        int powSum = 0 ;
        while(i <= j){
            powSum = i*i + j*j;
            if(powSum == c){
                return true;
            }else if (powSum > c){
                j = j - 1;
            }else{
                i = i + 1;
            }
        }
        return false;
    }    
};

/*
时间复杂度：O(sqrt(c)); 空间复杂度：O(1);
*/

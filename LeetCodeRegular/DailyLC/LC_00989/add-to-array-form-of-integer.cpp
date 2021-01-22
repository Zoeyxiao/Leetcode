/*
989. 数组形式的整数加法
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int size = A.size();
        vector<int> result;
        for (int i = size-1; i >= 0; i--){
            int sum  = 0;
            sum = A[i] + K % 10;
            K /= 10;
            if(sum >= 10){
                K++;
                sum -= 10;
            }
            result.push_back(sum);
        }
        for (; K > 0; K /= 10) {
            result.push_back(K % 10);
        }//最高位溢出的处理办法，或者K比A位数高的处理办法
        reverse(result.begin(), result.end());
        return result;
    }
};

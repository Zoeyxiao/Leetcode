class Solution {
public:
    string addStrings(string num1, string num2) {
        string num3 = "";
        int mid = 0;
        int n = num1.length(), m = num2.length();
        int i = n-1, j = m-1;
        int x = 0, y = 0;
        while(i >= 0 || j >= 0 || mid != 0){
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + mid;
            num3.push_back('0' + sum % 10);
            mid = sum / 10;
            i--;
            j--;
        }
        // 计算完以后的答案需要翻转过来
        reverse(num3.begin(), num3.end());
        return num3;
    }
};

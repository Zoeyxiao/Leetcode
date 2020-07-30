class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3){
            return n-1;
        }
        
        int r = n % 3;
        int k = n / 3;
        int mul = 0;
        
        if(r == 0){
            mul = pow(3, k);
            return mul;
        }
        else if(r == 1){
            mul = pow(3, k-1) * 2 * 2;
            return mul;
        }
        else{
            mul = pow(3, k) * 2;
            return mul;
        }
    }
};


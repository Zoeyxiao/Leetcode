class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0){
            return -1;
        }
        int len = 1;
        for(int N = 1; N % K != 0; len++){
            N = N % K;
            N = N * 10 + 1; //缩小原本的数，利用 N*10+1同余于（N%K）*10 +1；
        }
        return len;
    }
};

/*
难点在于如果用普通的N%K来循环进行判断，循环到第10次整型就会存在溢出的问题；
所以要用同余的方法来将数变小
*/

##461. 汉明距离
##两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

##给出两个整数 x 和 y，计算它们之间的汉明距离。

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count('1')
      
###代码没有什么难度，主要是不熟悉python代码，bin是转换二进制，“ ^ ”是异或


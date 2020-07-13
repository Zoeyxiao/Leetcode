class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        sort(nums1.begin(), nums1.end()); //可以用标准库直接对数组进行排序
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> interSection;

        while( i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                interSection.push_back(nums1[i]); //给向量插入值用push_back，不能直接赋值
                i++;
                j++;
            }
        }
        return interSection;
        
    }
};

/*
如果两个数组是有序的，则可以便捷地计算两个数组的交集。

首先对两个数组进行排序，然后使用两个指针遍历两个数组。

初始时，两个指针分别指向两个数组的头部。每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，则将指向较小数字的指针右移一位，如果两个数字相等，
将该数字添加到答案，并将两个指针都右移一位。当至少有一个指针超出数组范围时，遍历结束。
（这是我的解题思路，与官方题解第二个思路一致，因此直接将官方解答放在这里）
*/

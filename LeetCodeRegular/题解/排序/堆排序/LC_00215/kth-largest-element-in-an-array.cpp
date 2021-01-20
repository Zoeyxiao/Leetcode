/*
215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/

class Solution {
public:
    //逐级下降函数
    void MaxHearpify(vector<int>& a, int i, int HeapSize){
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < HeapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < HeapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            MaxHearpify(a, largest, HeapSize);
        }
    }
    //建堆
    void BuildmaxHeap(vector<int>& a, int HeapSize){
        for(int i = HeapSize /2; i >= 0; i--){
            MaxHearpify(a, i, HeapSize);
        }
    }
    //寻找第k个最大的值
    int findKthLargest(vector<int>& nums, int k) {
        int HeapSize = nums.size();
        BuildmaxHeap(nums, HeapSize);
        for(int i = nums.size()- 1; i >= nums.size()- k + 1; i--){
            swap(nums[0], nums[i]);
            HeapSize = HeapSize -1;
            MaxHearpify(nums, 0, HeapSize);
        }
        return nums[0];
    }
};

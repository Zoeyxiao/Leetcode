class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, ind = n;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target <= nums[mid]){
                ind = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ind;   
    }
};

/*
二分查找法，关键在于不要把问题想得太复杂， 比如如果原数组没有需要插入的话，并不需要push_back这种命令，直接顺序放在最后，然后返回最后位置的索引就可以了
*/

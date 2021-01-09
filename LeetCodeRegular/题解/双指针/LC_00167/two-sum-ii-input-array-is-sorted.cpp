class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> index(2);
        int i = 0, j = n-1;
        while(i < j){
            int sum = 0;
            sum = numbers[i] + numbers[j];
            if(sum < target){
                i++;
            }
            if(sum > target){
                j--;
            }
            if(sum == target){
                index[0] = i+1;
                index[1] = j+1;
                return index;
            }
        } 
    return {-1, -1};
    }
};

/*
我采用的是双向指针的方法，每周的第一题真的都比较简单，题解中还可以用二分查找，准备也写一写，如下，虽然写出来了，但是对于low的赋值感觉并不明晰，需要再理理思路
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> index(2);
        int i = 0, j = n-1;
        int mid = 0;
        for(i = 0; i < n-1; i++){
            int low = i + 1;
            while(low <= j){
                mid = (j - low ) / 2 + low;
                if(numbers[mid] < target - numbers[i]){
                low = mid + 1;
                }
                if(numbers[mid] > target - numbers[i]){
                j = mid - 1;
                }
                if(numbers[mid] == target - numbers[i]){
                index[0] = i + 1;
                index[1] = mid + 1;
                return index;
                }
            }
        }
        return {-1, -1};
    }
};
/*
****************************************************************************************************
****************又重新写了一遍，感觉代码简洁了一点，双指针的方法****************************************
****************************************************************************************************
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                return {i + 1, j + 1};
            }else if (sum < target){
                i = i + 1; 
            }
            else{
                j = j - 1;
            }            
        }
        return {-1, -1};
    }
};

/*
*************时间复杂度：O(n); 空间复杂度：O(1);**************************************************************
*/

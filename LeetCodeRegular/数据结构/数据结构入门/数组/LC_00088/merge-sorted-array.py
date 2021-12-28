'''
88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
'''

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        k = m+n-1
        while m > 0 and n > 0:
            if nums1[m-1] < nums2[n-1]:
                nums1[k] = nums2[n-1]
                n -= 1
            else:
                nums1[k] = nums1[m-1]
                m -= 1
            k -= 1
        nums1[:n] = nums2[:n]
        
'''
https://leetcode-cn.com/problems/merge-sorted-array/solution/fu-xue-ming-zhu-dong-hua-ti-jie-cong-hou-teq6/

【负雪明烛】解题思路
本题重点：

两个数组有序；
合并结果放到 nums1 中
注意题目给出的数组的方式：nums1 中本身有效的数字是前 mm 位，nums1 的长度是 m + nm+n，因此正好可以放下 nums1[0:m] + nums2[0:n]。

合并两个有序数组，我们第一反应肯定是想到了归并排序。归并排序是把两个有序的数组合并、放到另外一个数组中。所以空间复杂度是 O(M + N)O(M+N) 的。

由于本题给出的 nums1 是能够保证其长度能够放得下 m + n 个元素的，所以可以直接把合并的结果放到 nums1 中。

思路一：如果两个数组从开头向结尾（数字从小到大）进行比较，那么每次把比较之后的数字放置到 nums1 中的前面，则需要把 nums1 中第 k 个位置后面的元素向后移动。移动次数比较多。
思路二：如果两个数组从结尾向开头（数字从大到小）进行比较，那么每次把比较之后的数字放置到 nums1 中的后面，由于后面的数字本身就是提供出来的多余的位置，都是 0，因此不需要对 nums1 进行移动。
显然思路二更好。

从后向前进行比较
确定了主要的思路之后，实现起来其实很简单。

当 m > 0 并且 n > 0 时，从后向前比较 num1[m - 1]num1[m−1] 和 nums2[n - 1]nums2[n−1] ：
如果是 nums1[m - 1]nums1[m−1] 大，则把 nums1[m - 1]nums1[m−1]放到 num1num1 的第 m + n - 1m+n−1 位置，并让 m -= 1m−=1。
如果是 nums1[n - 1]nums1[n−1] 大，则把 nums2[n - 1]nums2[n−1] 放到 num1num1 的第 m + n - 1m+n−1 位置，并让 n -= 1n−=1。
当上面的遍历条件结束的时候，此时 m 和 n 至少有一个为 0。
当 m == 0 时，说明 num1 的数字恰好用完了，此时 nums2 可能还剩元素，需要复制到 nums1 的头部；
当 n == 0 时，说明 num2 的数字恰好用完了，此时 nums1 可能还剩元素，由于剩余的这些元素一定是 nums1 和 nums2 中最小的元素，所以不用动，直接留在原地就行。

'''

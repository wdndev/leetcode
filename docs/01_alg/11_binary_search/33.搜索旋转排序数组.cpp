/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.94%)
 * Likes:    2772
 * Dislikes: 0
 * Total Accepted:    792.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始
 * 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
// 1.暴力方法
//   1.1 O(n)遍历
//   1.2 还原 O(logN) -> 升序 -> 二分查找
// 2.正解：二分查找
//   a.单调，不是严格意义单调，是半单调
//   b.边界
//   c.idx
class Solution {
public:
    // 使用二分查找：

    // - 如果target在[mid+1, high]序列中，则low=mid+1，否则，high=mid，关键是如何判断target在[mid+1, high]序列中，具体判断如下：
    // - 当[0, mid]序列是升序：nums[0] ≤ nums[mid]，当target>nums[mid] || target <nums[0]，则向后规约；
    // - 当[0, mid]序列存在旋转位：nums[0] > nums[mid]，当target<nums[0] && target >nums[mid]，则向后规约；
    // - 其他情况就是向前规约了

    // 循环判断，直到排除到只剩一个元素时，退出循环，如果该元素和target相同，直接返回下标，否则返回-1.
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while (left < right) {
            // 注意此处，主要是为了防止数据溢出
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
            } 
            // 当[0,mid]有序时，向后规约条件
            if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0])) {
                left = mid + 1;
            
            // 当[0, mid]发生旋转时，向后规约条件
            } else if (target > nums[mid] && target < nums[0]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left == right && nums[left] == target ? left : -1;
    }
};
// @lc code=end


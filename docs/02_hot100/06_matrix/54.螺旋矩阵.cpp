/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.88%)
 * Likes:    1543
 * Dislikes: 0
 * Total Accepted:    430.1K
 * Total Submissions: 861.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 按层模拟：可以将矩阵看成若干层，首先输出最外层的元素，
    // 其次输出次外层的元素，直到输出最内层的元素。
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> order;

        int left = 0;
        int right = cols - 1;
        int top = 0;
        int bottom = rows - 1;

        while (left <= right && top <= bottom) {
            // 从左到右
            for (int col = left; col <= right; col++) {
                order.push_back(matrix[top][col]);
            }
            // 从上到下
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            // 现在idx在右下角
            if (left < right && top < bottom) {
                // 从右到左
                for (int col = right - 1; col > left; col--) {
                    order.push_back(matrix[bottom][col]);
                }
                // 从下到上
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return order;
    }
};
// @lc code=end


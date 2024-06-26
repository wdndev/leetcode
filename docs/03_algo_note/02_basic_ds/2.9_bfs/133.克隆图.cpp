/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 *
 * https://leetcode.cn/problems/clone-graph/description/
 *
 * algorithms
 * Medium (69.77%)
 * Likes:    674
 * Dislikes: 0
 * Total Accepted:    131.8K
 * Total Submissions: 188.9K
 * Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
 *
 * 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
 * 
 * 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
 * 
 * class Node {
 * ⁠   public int val;
 * ⁠   public List<Node> neighbors;
 * }
 * 
 * 
 * 
 * 测试用例格式：
 * 
 * 简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val =
 * 2），以此类推。该图在测试用例中使用邻接列表表示。
 * 
 * 邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
 * 
 * 给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
 * 输出：[[2,4],[1,3],[2,4],[1,3]]
 * 解释：
 * 图中有 4 个节点。
 * 节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
 * 节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
 * 节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
 * 节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：adjList = [[]]
 * 输出：[[]]
 * 解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。
 * 
 * 
 * 示例 3：
 * 
 * 输入：adjList = []
 * 输出：[]
 * 解释：这个图是空的，它不含任何节点。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 
 * 输入：adjList = [[2],[1]]
 * 输出：[[2],[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 节点数不超过 100 。
 * 每个节点值 Node.val 都是唯一的，1 <= Node.val <= 100。
 * 无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
 * 由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
 * 图是连通图，你可以从给定节点访问到所有节点。
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // bfs
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        // 哈希表
        std::unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        // 队列
        std::queue<Node*> queue;
        queue.push(node);

        while (!queue.empty()) {
            // 取出结点
            Node* tmp_node = queue.front();
            queue.pop();
            // 遍历邻居
            for (auto& node_v : tmp_node->neighbors) {
                // 如果没有被访问过，克隆，存储在哈希表中
                if (visited.find(node_v) == visited.end()) {
                    visited[node_v] = new Node(node_v->val);
                    queue.push(node_v);

                }
                // 更新当前邻居结点
                visited[tmp_node]->neighbors.push_back(visited[node_v]);
            }

        }

        return visited[node];
    }
private:
    // 访问过结点的标记
    std::unordered_map<Node*, Node*> m_visited;
    // dfs
    Node* dfs(Node* node) {
        // 如果该结点被访问过了，则直接从哈希表中取出克隆的结点
        if (m_visited.find(node) != m_visited.end()) {
            return m_visited[node];
        }

        // 克隆结点，注意，不会克隆邻居
        Node* clone_node = new Node(node->val);
        // 哈希表存储
        m_visited[node] = clone_node;
        // 遍历该节点的邻居节点，并更新克隆结点的邻居结点
        for (auto& neighbor : node->neighbors) {
            clone_node->neighbors.push_back(this->dfs(neighbor));
        }

        return clone_node;
    }
};
// @lc code=end


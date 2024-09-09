/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // simulate the process
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int x = 0;
        int y = 0;
        int nextX;
        int nextY;
        int index = 0;
        vector<pair<int,int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        // at each step, fill in val and check next index
        // if next index invalid, update dirs and check again
        // if next index already filled in, change dir and update
        while (head) {
            // cout << x << " " << y << "\n";
            ans[x][y] = head->val;
            head = head->next;
            // prevent infinite loop when we fill in entire 2D vector exactly
            if (!head) continue;
            nextX = x + dirs[index].first;
            nextY = y + dirs[index].second;
            // we will either go out of bounds or next index is already filled in
            while (nextX < 0 || nextX == m || nextY < 0 || nextY == n || ans[nextX][nextY] != -1) {
                index = (index + 1) % 4;
                nextX = x + dirs[index].first;
                nextY = y + dirs[index].second;
            }
            x = nextX;
            y = nextY;
        }
        return ans;
    }
};
// 10
// 1
// [8,24,5,21,10,11,11,12,6,17]
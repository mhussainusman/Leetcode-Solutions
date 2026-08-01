 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  // Approach: fast/slow to find middle, reverse second half,
// then walk both halves in lockstep summing twin pairs.
// Time: O(n)
// Space: O(1)
using namespace std;
#include <algorithm>
class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: find middle using fast/slow
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow now points to the start of the second half

        // Step 2: reverse the second half
        ListNode *prev = nullptr, *curr = slow;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        // prev is now the head of the reversed second half

        // Step 3: walk first half and reversed second half together
        ListNode *first = head, *second = prev;
        int maxSum = 0;
        while (second != nullptr) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
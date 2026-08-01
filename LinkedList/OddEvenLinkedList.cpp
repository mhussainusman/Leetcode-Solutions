 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         if (head == nullptr || head->next == nullptr) return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // save start of even chain for later

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;   // link odd to next odd node
            odd = odd->next;          // advance odd

            even->next = odd->next;   // link even to next even node
            even = even->next;        // advance even
        }

        odd->next = evenHead; // attach even chain after odd chain
        return head;
    
    }
};
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
    ListNode *deleteMiddle(ListNode *head) {
            int N = 0;
            ListNode *fast = head;
            while (fast != nullptr) {
                    fast = fast->next;
                    ++N;
            }
            int M = N / 2;
            if (M == 0) {
                    ListNode *node = head;
                    head = head->next;
                    delete node;
                    return head;
            }
            ListNode *slow = head;
            for (int i = 0; i < M - 1; ++i) {
                    slow = slow->next;
            }
            ListNode *node = slow->next;
            if (slow->next->next == nullptr) {
                    slow->next = nullptr;
            } else slow->next = slow->next->next;
            delete node;
            return head;
    }
};
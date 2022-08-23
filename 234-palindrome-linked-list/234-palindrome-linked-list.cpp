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
    bool isPalindrome(ListNode* head) {
        ListNode* pre = NULL, *slow = head, *fast = head;
        while(fast && fast->next){
            ListNode* temp = slow;
            fast = fast->next->next;
            slow = slow->next;
            temp->next = pre;
            pre = temp;
        }
        if(fast != NULL) slow = slow->next;
        while(pre){
            if(pre->val != slow->val) return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
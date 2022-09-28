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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head;
        
        for(int i=0; i<n && first != nullptr; i++) first = first->next;
        
        if(first == nullptr) return head->next;
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete(temp);
        return head;
    }
};
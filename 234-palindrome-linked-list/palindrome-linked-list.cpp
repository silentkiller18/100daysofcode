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
 #include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
 ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast) slow = slow->next;
        slow = reverse(slow);
        
        while(slow){
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr= head;
        while(curr){
            curr= curr->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
};
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
    ListNode* oddEvenList(ListNode* head) {
         if(head == NULL) return NULL;
        
        ListNode *odd = head;
        ListNode *even = head->next;

        ListNode *node = even;

        while(node && node->next){
            odd->next = node->next;
            odd = node->next;
            node->next = node->next->next;
            node = node->next;
        }

        odd->next = even;

        return head;
    }
};
// practice link = https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


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
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            count = count+1;
            curr = curr->next;
        }
        int check = count-n-1;
        count = 0;
        curr = head;
        if(check  == -1){
            return head->next;
        }
        while(curr!=NULL){
            if(count == check){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
            count += 1;
        }
        return head;
    }
};
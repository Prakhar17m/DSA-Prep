// problem link = https://leetcode.com/problems/merge-k-sorted-lists/description/


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minh;

        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                minh.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(minh.size()>0){
            auto it = minh.top();
            minh.pop();
            if(it.second->next){
                minh.push({it.second->next->val,it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
        }
        return dummynode->next;
    }
};
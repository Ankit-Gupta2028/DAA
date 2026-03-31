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
        priority_queue<int,vector<int> ,greater<int>> p1;

        for(int i=0;i<lists.size();i++){
            ListNode* node=lists[i];
            while(node != NULL){
                p1.push(node->val);
                node=node->next;
            }
        }
        ListNode* Head = new  ListNode(-1);
        ListNode* temp1 = Head;
        while(!p1.empty()){
            ListNode* temp2 = new  ListNode(p1.top());
            temp1->next=temp2;
            temp1=temp1->next;
            p1.pop();
        }
        return Head->next;

    }
};
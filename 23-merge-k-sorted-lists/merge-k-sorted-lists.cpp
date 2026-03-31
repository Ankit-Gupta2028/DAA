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

        auto cmf=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*> ,decltype(cmf)> p1(cmf);

        for(auto node: lists){
            if(node){
                p1.push(node);
            }
            
        }
        ListNode* head= new ListNode(-1);
        ListNode* temp=head;
        while(!p1.empty()){

            temp->next=p1.top();
            temp=temp->next;
            if(p1.top()->next){
                p1.push(p1.top()->next);
            }
            p1.pop();

        }
        return head->next;

        

    }
};
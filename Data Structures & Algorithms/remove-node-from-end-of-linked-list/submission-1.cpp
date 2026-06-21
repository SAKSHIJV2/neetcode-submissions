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
        int count=1;
        ListNode *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        int k=count-n;
        count=0;
        ListNode *traverse=head;
        ListNode *prev=nullptr;
        while(count!=k){
            count++;
            prev=traverse;
            traverse=traverse->next;
        }
        if(k==0){
            head=head->next;
            delete traverse;
        }
        else{
            prev->next=traverse->next;
            delete traverse;          
        }
        return head;
    }
};

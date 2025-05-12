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


        if(head == nullptr) return head;
        if(head -> next == nullptr) return nullptr; 


        map<int, ListNode*> mpp;
        ListNode* current = head;
         int i = 1;

        while(current != nullptr){
             
            mpp[i] = current;

            current = current -> next;
            i++;
        }

        int nodePositionFromStart = i - n;
        // the node is the first element of the linkedlist
        if(nodePositionFromStart == 1){

            ListNode* current = mpp[nodePositionFromStart];
            current = current -> next;
            head = current;
            
        }

        // the node is the last node of the linkedlist
        else if(nodePositionFromStart == i){
            ListNode* current = mpp[nodePositionFromStart - 1];
            
            current -> next = nullptr;
        }

        else{
            ListNode* current = mpp[nodePositionFromStart - 1];

            current -> next = current -> next -> next;

        }

        return head;
        
    }
};

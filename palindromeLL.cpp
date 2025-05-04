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



    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }


    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next; 
            fast = fast -> next -> next;
        }

        slow = slow -> next;

        // this pointer will also be used to reverse the linkedlist again
        // ** you can only reverse from starting to end, not end to starting in a singly linkedlist
        ListNode* headFromLast = reverseLinkedList(slow); 
         
        ListNode* first = head;
        ListNode* second = headFromLast;

        bool isPalindrome = true;

        while(second != nullptr){

            if(first -> val != second -> val){
                isPalindrome = false;
                break;
            }

            first = first -> next;
            second = second -> next;

        }
        
        reverseLinkedList(slow);
        return isPalindrome;

    }
};

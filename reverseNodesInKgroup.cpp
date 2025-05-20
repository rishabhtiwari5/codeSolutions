class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            ListNode* front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }
        return prev;
    }


    ListNode* getKthNode(ListNode* current, int k) {
        k = k-1;
        while (current != nullptr && k > 0) {
            k--;
            current = current->next;
        }
        return current;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* prevLast = nullptr;


        while (current != nullptr) {
            ListNode* kThNode = getKthNode(current, k);
            if (kThNode == nullptr) {
                if (prevLast) {
                    prevLast->next = current;
                }
                break;
            }


            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;
            reverseLinkedList(current);


            if (current == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }


            prevLast = current;
            current = nextNode;
        }


        return head;
    }
};






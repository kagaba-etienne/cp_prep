#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* correct = head;
        ListNode* temp = head;
        int distance = 0;

        while(distance < (n)) {
            end = end->next;
            ++distance;
        }

        if(end != NULL) {
            end = end->next;
        } else {
            head = correct->next;
            return head;
        }

        while(end != NULL) {
            end = end->next;
            correct = correct->next;
        }

        correct->next = correct->next->next;

        return head;
    }
};
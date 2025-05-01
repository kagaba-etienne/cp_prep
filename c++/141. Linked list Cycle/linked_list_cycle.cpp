#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow) {
            return true;
        }
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(3);
    ListNode* sec = new ListNode(2);
    ListNode* thir = new ListNode(0);
    ListNode* four = new ListNode(-4);

    head->next = sec;
    sec->next = thir;
    thir->next = four;

    // Without a cycle
    cout<<hasCycle(head)<<endl;

    // With a cycle
    four->next = sec;
    cout<<hasCycle(head)<<endl;

    return 0;
}
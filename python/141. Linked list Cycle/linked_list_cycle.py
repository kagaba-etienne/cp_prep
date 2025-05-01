from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def has_cycle(head: Optional[ListNode]) -> bool:
    slow = head
    fast = head

    while(fast and fast.next):
        slow = slow.next
        fast = fast.next.next

        if (fast == slow): return True

    return False


if __name__ == '__main__':
    head = ListNode(3)
    sec = ListNode(2)
    thir = ListNode(0)
    four = ListNode(-4)

    head.next = sec
    sec.next = thir
    thir.next = four

    # Without a cycle
    print(has_cycle(head))

    # With a cycle
    four.next = sec

    print(has_cycle(head))
public class LinkedListCycle {

    public static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null) {
            fast = fast.next;
            if(fast != null) {
                slow = slow.next;
                fast = fast.next;
            }

            if(fast == slow) {
                return true;
            }
        }

        return false;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(3);
        ListNode sec = new ListNode(3);
        ListNode thir = new ListNode(3);
        ListNode four = new ListNode(3);

        head.next = sec;
        sec.next = thir;
        thir.next = four;

        // Without a cycle
        System.out.println(hasCycle(head));

        // With a cycle
        four.next = sec;

        System.out.println(hasCycle(head));
    }
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
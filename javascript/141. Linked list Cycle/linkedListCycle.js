class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    var fast = head;
    var slow = head;

    while(fast != null) {
        fast = fast.next;

        if(fast != null) {
            fast = fast.next;
            slow = slow.next;
        }


        if(fast === slow) {
            return true;
        }
    }

    return false;
};

var head = new ListNode(3);
var sec = new ListNode(2);
var thir = new ListNode(0);
var four = new ListNode(-4);

head.next = sec;
sec.next = thir;
thir.next = four;

// Without a cycle
console.log(hasCycle(head));

// With a cycle
four.next = sec;

console.log(hasCycle(head));
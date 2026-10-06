class Solution {
    Node removeDuplicates(Node head) {

        if (head == null || head.next == null) {
            return head;
        }

        Node newnode = new Node(-1);
        Node temp = newnode;

        Node slow = head;
        Node fast = head.next;

        while (fast != null) {

            if (fast.data != slow.data) {
                temp.next = slow;
                temp = temp.next;

                slow = fast;
            }

            fast = fast.next;
        }

        // Add last unique node
        temp.next = slow;
        temp = temp.next;

        // Very important: cut old duplicate links
        temp.next = null;

        return newnode.next;
    }
}
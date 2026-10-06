# PREP55 - Rating 900

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Remove Duplicates from Sorted List

You are given head of the  **non-empty**  sorted linked list where the value of the $i^{th}$ node will be $A_i$.

Your task is to delete all duplicates such that each element appears only once and return the linked list sorted.

### Input:
- First line will contain $T$, number of test cases. Then the test cases follow.
- The first line contains one integer $N$ — the length of the linked list.
- The second line contains $N$ space separated integers $A_1, A_2, \ldots A_N$ — the value of the linked list nodes starting from the head for the linked list.

 **Note:** 

- For Java language, you need to:

Complete the function in the submit solution tab:

```
Node removeDuplicates(Node head){...}

```

$\$

- For C++ language, you need to:

Complete the function in the submit solution tab:

```
Node *removeDuplicates(Node*  head){...}

```

$\$

- For Python language, you need to:

Complete the function in the submit solution tab:

```
def Node removeDuplicates(self, head):

```

### Output:

The function you complete should return the required answer.

### Constraints
- $1 \leq T \leq 10$
- $1 \leq N, A_i \leq 10^5$
### Sample 1:
Input
Output

```
3
5
1 1 6 8 8
5
1 2 3 4 5
4
5 5 5 5
```

```
1 6 8 
1 2 3 4 5 
5 
```

### Explanation:

 **Test case $1$:**  We will remove duplicate entry of $1$, $8$. So the sorted linked list will be $1 \rightarrow 6 \rightarrow 8$.

 **Test case $2$:**  There is no duplicate entry. So the sorted linked list will be $1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 5$.

 **Test case $3$:**  We will remove duplicate entry of $5$. So the sorted linked list will be $5$.

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-06T07:07:02.203Z  

```java
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
```

---

[View on CodeChef](https://www.codechef.com/problems/PREP55)
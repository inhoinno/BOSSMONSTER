/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


 /*/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            
            curr = curr.next;
        }
        
        if (l1 != null) {
            curr.next = l1;
        }
        if (l2 != null) {
            curr.next = l2;
        }
        
        return dummy.next;
    }
}

MymergeTwoLst
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //l1 + l2(n) then sort(n)
        //2 l1+l2 while sorting
        ListNode n = new ListNode(0);
        ListNode head= new ListNode(0);
    if(l1 == null && l2 == null)
        return null;
    if(l1 == null && l2 !=null)
        return l2;
    else if(l1 != null && l2 ==null)
        return l1;

    if(l1.val <= l2.val){
        n = l1;
        head = n;
        l1 = l1.next;
        n.next = null;
    }
    else if(l1.val > l2.val){
        n = l2;
        head = n;
        l2 = l2.next;
        n.next = null;
    }
        

    while(l1 != null || l2 != null){
        if(l2 == null){
            n.next = l1;
            l1 = l1.next;
            n = n.next; 
            continue;
        }
        if(l1 == null){
            n.next = l2;
            l2 = l2.next;
            n = n.next;
            continue;
        }
        if(l1.val <= l2.val){ //l1이 더 작거나 l1 = l2일때
            n.next = l1;
            l1 = l1.next;
            n = n.next;            
        }else if(l1.val > l2.val){ //l2 가 더 작을때
            n.next = l2;
            l2 = l2.next;
            n = n.next;
        }

    }
    n.next = null;
    return head;






    }
}
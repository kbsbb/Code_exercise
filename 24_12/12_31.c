//题目：链表相交
//链接：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
//描述：给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode listnode;

//计算链表长度
int GetListLen(listnode* list) {
    int ret = 0;
    while (list) {
        ret++;
        list = list->next;
    }
    return ret;
}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //求两个链表长度
    int len1 = GetListLen(headA);
    int len2 = GetListLen(headB);

    //求出两个链表长度的差值，找出长链表
    int differ = len1 - len2;
    listnode* fast = headA;
    listnode* slow = headB;

    if (len1 < len2) {
        differ = len2 - len1;
        fast = headB;
        slow = headA;
    }

    //让快指针先走differ步，目的让两个链表到尾节点距离相同
    while (differ--) {
        fast = fast->next;
    }

    //两个链表同时走，如果两个节点指针相同表示相交，如果走到尾没有返回表示没有相交
    while (fast) {
        if (fast == slow) {
            return fast;
        }
        fast = fast->next;
        slow = slow->next;

    }
    return NULL;

}
#include "stdio.h"

struct ListNode {
    int val;
    struct ListNode *next;
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL || head->next == NULL) {
        return head;
    }
    int n = 1;
    struct ListNode* iter = head;
    while (iter->next != NULL) {
        iter = iter->next;
        n++;
    }
    int add = n - k % n;
    if (add == n) {
        return head;
    }
    iter->next = head;
    while (add--) {
        iter = iter->next;
    }
    struct ListNode* ret = iter->next;
    iter->next = NULL;
    return ret;
}
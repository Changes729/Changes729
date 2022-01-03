#include "ListNode.h"
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = new ListNode;
    ListNode *node = NULL;
    int advance_num = 0;

    do {
      if (node == NULL) {
        node = result;
      } else {
        node->next = new ListNode;
        node = node->next;
      }

      auto v1 = l1 == NULL ? 0 : l1->val;
      auto v2 = l2 == NULL ? 0 : l2->val;

      auto value = v1 + v2 + advance_num;
      node->val = value % 10;
      advance_num = value / 10;

      l1 = l1 == NULL ? NULL : l1->next;
      l2 = l2 == NULL ? NULL : l2->next;

    } while (l1 != NULL || l2 != NULL || advance_num != 0);

    return result;
  }
};
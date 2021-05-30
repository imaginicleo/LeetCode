#pragma once

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* root = new ListNode(-1);
        root->next = head;
        ListNode* pre = root;
        ListNode* cur = root;
        while (cur)
        {
        label:
            bool equalflag = false;
            while (cur && cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
                equalflag = true;
            }
            if (equalflag)
            {
                cur = cur->next; //跳过相同的最后一个结点
                goto label;
            }
            pre->next = cur;
            pre = cur;
            if (cur)cur = cur->next; //判断此时是否是空指针
        }
        return root->next;
    }
};

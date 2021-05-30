#include "Solution.h"
int main(int argc, char* argv[])
{
    ListNode *test1 = new ListNode(1,new ListNode(1,new ListNode(1,new ListNode(2,new ListNode(3)))));
    Solution *solution = new Solution;
    ListNode *result = solution->deleteDuplicates(test1);
    return 0;
}

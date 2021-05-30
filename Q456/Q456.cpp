#include <iostream>

#include "Solution.h"
int main(int argc, char* argv[])
{
    std::vector<int> nums = {-2,1,2,-2,1,2};
    auto solution = *new Solution();
    std::cout<<solution.find132pattern(nums);
    return 0;
}

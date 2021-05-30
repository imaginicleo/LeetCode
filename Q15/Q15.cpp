#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) const {
        vector<vector<int>> result;
        const int size = nums.size();
        if (size < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (nums[left] + nums[right] > -nums[i]) {
                    right--;
                }
                else if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                }
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

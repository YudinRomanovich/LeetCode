#include <iostream>
#include <vector>



// 35. Search Insert Position

class Solution35 {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int x = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[x-1] < target) {
                return x;
            }
            if (nums[i] >= target) {
                return i;
            }
        }
        return 0;
    }
};


int main() {

    Solution35 sol;

    std::vector<int> nums = { 1,3,5,6 };
    
    std::cout<<sol.searchInsert(nums, 5);

    return 0;
}
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

// 69. Sqrt(x)

class Solution69 {
public:
    int mySqrt(int x) {
        for (unsigned int i = 0; i < 50000; i++) {
            if (i * i > x) { return i - 1; }
            if (i * i == x) { return i; }
        }
        return 0;
    }
};

// 9. Palindrome Number

class Solution9 {
public:
    bool isPalindrome(int x) {
        long int CopyNum = x;
        long int reverse = 0;
        long int rem;

        x = CopyNum;

        while (x > 0) {
            rem = x % 10;
            reverse = reverse * 10 + rem;
            x /= 10;
        }

        if (reverse == CopyNum) return true;
        else return false;
    }
};


int main() {

    Solution35 sol35;
    std::vector<int> nums = { 1,3,5,6 };
    Solution69 sol69;
    std::cout << sol69.mySqrt(5)<<'\n';
    Solution9 sol9;
    std::cout << sol9.isPalindrome(22);
 


    

    return 0;
}
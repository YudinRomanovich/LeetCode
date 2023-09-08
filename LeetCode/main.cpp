#include <iostream>
#include <vector>
#include <algorithm>



 //35. Search Insert Position

class Solution35 {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto x = nums.size();
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

// 1. Two Sum

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

//875. Koko Eating Bananas

class Solution875 {
public:
    long int minEatingSpeed(std::vector<int>& piles, long int h) {
        std::sort(piles.begin(), piles.end());
        int count = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int ukus = piles[i];
            for (int j = 0; j < piles.size(); ) {
                for (; piles[j]>0; piles[j]-=ukus)
                {
                    if (h == 0) {
                        i++;

                    }
                    if (piles[j] == ukus) {
                        j++;
                        count++;
                        h--;
                        break;
                    }
                    if (piles[j] <= 0) {
                        j++;
                        break;
                    }
                    if (piles[j]>0) {
                        h--;
                        count++;
                        continue;
                    }
                    
                    
                }
                if (piles[j] <= 0) {
                    i++;
                    break;
                }


            }
           
        }
        return count;
    }
};

//2154. Keep Multiplying Found Values by Two

class Solution2154 {
public:
    int findFinalValue(std::vector<int>& nums, int original) {
        if (nums.size() == 1 && nums[0] == original) {
            return original * 2;
        }
        for (int j = 0; j < nums.size() - 1; ) {
            if (nums[j] != original) {
                j++;
            }
            if (nums[j] == original) {
                original = original * 2;
                j = 0;
            }
        }
        return original;
    }
};

//2310. Sum of Numbers With Units Digit K

class Solution2310 {
public:

    int minimumNumbers(int num, int k) {
        int countOfSet = 0;
        int numMaxSize = num;
        for (int i = 0; i < numMaxSize; ) {
            num--;
            i++;
            if (num % 10 == 9 && i % 10 == 9) {
                if (num + i == numMaxSize) {
                    countOfSet++;
                }
            }

        }
        return countOfSet;
    }
};


int main() {

    //Solution35 sol35;
    //std::vector<int> nums = { 1,3,5,6 };
    //Solution69 sol69;
    //std::cout << sol69.mySqrt(5)<<'\n';
    //Solution9 sol9;
    //std::cout << sol9.isPalindrome(22)<<'\n';
    //Solution1 sol1;
   /* Solution875 sol875;
    std::vector<int> piles = { 3,6,7,11 };
    std::cout<<sol875.minEatingSpeed(piles,8);*/
    Solution2310 sol2310;
    std::cout<<sol2310.minimumNumbers(58, 9);
    

    return 0;
}
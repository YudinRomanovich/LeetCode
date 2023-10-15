#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

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
    int minimumNumbers(int sum, int k) {
        if (sum == 0) return 0;
        for (int i = 1; i <= 10; ++i)
            if ((i * k) % 10 == sum % 10 && i * k <= sum) return i;
        return -1;
    }
};

//2236. Root Equals Sum of Children

class Solution2236 {
public:
    bool checkTree(TreeNode* root) {
        if (root->right->val + root->left->val == root->val) {
            return true;
        }
        else return false;
    }
};

//1913. Maximum Product Difference Between Two Pairs

class Solution1913 {
public:
    int maxProductDifference(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);
    }
};

//13. Roman to Integer

class Solution13 {
public:
    int romanToInt(std::string s) {

        std::unordered_map<char, int> roman;

        roman.emplace('I', 1);
        roman.emplace('V', 5);
        roman.emplace('X', 10);
        roman.emplace('L', 50);
        roman.emplace('C', 100);
        roman.emplace('D', 500);
        roman.emplace('M', 1000);
        


        int sol13sum = 0;



        for (int i = 0; i < s.size(); i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                sol13sum += roman[s[i + 1]] - roman[s[i]];
                i++;
            }
            else {
                sol13sum += roman[s[i]];
            }
        }

        return sol13sum;
    }
};

//2553. Separate the Digits in an Array

class Solution2553 {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> tmpVec;
        tmpVec.reserve(nums.size() * 5);
        for (auto& count : nums) {
            int countRate = count % 10;
            int iRate = 0;
            int i = 1;
            if (count < 10) {
                iRate = 0;
            }
            if (count >= 10 && count < 100) {
                iRate = 1;
            }
            if (count >= 100 && count < 1000) {
                iRate = 2;
            }
            if (count >= 1000 && count < 10000) {
                iRate = 3;
            }
            if (count >= 10000 && count < 100000) {
                iRate = 4;
            }
            if (count >= 100000 && count < 1000000) {
                iRate = 5;
            }
            int iMultiply = iRate;
            for (; iMultiply > 0; iMultiply--) {
                i *= 10;
            }
            for (; iRate >= 0; i /= 10) {
                tmpVec.push_back((count / i) % 10);
                iRate--;
            }

        }
        nums.clear();
        for (auto count = tmpVec.begin(); count < tmpVec.end(); count++) {
            nums.push_back(*count);
        }
        return nums;
    }
};

//1768. Merge Strings Alternately
class Solution1768 {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string* buffer = new std::string;
        std::string result;

        for (size_t i = 0; i < word1.size() + word2.size(); i++) {
            if (word1.size() == 0) {
                buffer->push_back(word2[i]);
                i++;
                continue;
            }
            else if (word2.size() == 0) {
                buffer->push_back(word1[i]);
                i++;
                continue;
            }
            else if (word1.size() != 0 && word2.size() != 0) {
                while (i < word1.size()) {
                    buffer->push_back(word1[i]);
                    if (i < word2.size()) {
                        buffer->push_back(word2[i]);
                    }
                    i++;
                }
            }

            while (i < word2.size()) {
                buffer->push_back(word2[i]);
                i++;
            }
        }

        for (auto& a : *buffer) {
            result.push_back(a);
        }

        delete buffer;
        return result;
    }

};

int main() {

    return 0;
}
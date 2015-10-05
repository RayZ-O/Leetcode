// Given an array of n integers where n > 1, nums, return an array output such that
// output[i] is equal to the product of all the elements of nums except nums[i].

// Solve it without division and in O(n).

// For example, given [1,2,3,4], return [24,12,8,6].


class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return vector<int>(size, 0);
        vector<int> s(size);
        thread t([&]() {
            s[0] = nums[0];
            for (int i = 1; i < size; i++) {
                s[i] = s[i - 1] * nums[i];
            }
        });
        vector<int> v(size);
        v[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            v[i] = v[i + 1] * nums[i];
        }
        t.join();
        vector<int> output(size);
        output[0] = v[1];
        output[size - 1] = s[size - 2];
        for (int i = 1; i < size - 1; i++) {
            output[i] = s[i - 1] * v[i + 1];
        }
        return output;
    }
};

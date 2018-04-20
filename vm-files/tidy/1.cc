// clang-tidy -checks=* 1.cc --
// clang-tidy -checks='-*,modernize-loop-convert' tidy/1.cc --

#include <vector>

int sum(const std::vector<int> &nums) {
    int res = 0;

    for (std::vector<int>::const_iterator it = nums.begin();
         it != nums.end(); ++it) {
        res += *it;
    }
    
    return res;
}


int sum2() {
    const int N = 3;
    int nums[N] = {1, 2, 3};
    
    int res = 0;

    for (int i = 0; i < N; ++i) {
        res += nums[i];
    }
    
    return res;
}

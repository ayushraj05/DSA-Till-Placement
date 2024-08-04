class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> accu = {0};
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                accu.push_back(sum);
            }
        }
        sort(accu.begin(), accu.end());

        for (int i = left; i <= right; ++i)
        {
            res = (res + accu[i]) % 1000000007;
        }
        
        return res;
    }
};
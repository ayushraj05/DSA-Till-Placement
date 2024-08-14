class Solution {
public:

    int slidingWindowCount(vector<int> &nums, int d){
        int i =0, j = 1;
        int n = nums.size();
        int pairCount =0;

        while(j <n){
            while(nums[j] - nums[i] > d)
                i++;
            pairCount += j-i;
            j++;
        }
        return pairCount;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l =0;
        int r = nums[n-1] - nums[0]; // highest distance;

        int result =0;

        while(l<=r){
            int mid = l+ (r-l)/2;
            int countPair = slidingWindowCount(nums,mid);

            if(countPair <k){
                l = mid+1;
            }
            else{
                result = mid; //storing mid as possible result;
                r = mid-1;
            }
        }
        return result;
    }
};
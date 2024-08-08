class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        // Space optimisation :)))))))))

        int first1 = 0;
        int second1 =0;
        int third1 =0;

        int first2 =0;
        int second2 =0;
        int third2 =0;


        for(int i =n-2;i>=0;i--){
            first1 = max(nums[i]+ second1, third1);
            second1 = third1;
            third1 = first1;
            
        }
        for(int i = n-1;i>0;i--){
            first2 = max(nums[i]+ second2, third2);
            second2 = third2;
            third2 = first2;
            
        }

        return max(first1, first2);

    }
};
class Solution {
public:
    
    int nthUglyNumber(int n) {
        vector<int> ans(n+1);
        int i2 = 1,i3 = 1, i5 =1;
        ans[1] = 1;

        for(int i =2;i<=n;i++){
            int i2ugly = ans[i2]*2;
            int i3ugly = ans[i3]*3;
            int i5ugly = ans[i5]*5;

            int minugly = min(min(i2ugly,i3ugly), i5ugly);
            ans[i] = minugly;

            if(minugly == i2ugly){
                i2++;
            }
            if(minugly == i3ugly){
                i3++;
            }
            if(minugly == i5ugly){
                i5++;
            }
        }
        return ans[n];
    }
};
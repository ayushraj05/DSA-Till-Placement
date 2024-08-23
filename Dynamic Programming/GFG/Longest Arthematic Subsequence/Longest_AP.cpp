class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        // code here
        int n = a.size();
        
        if(n <= 2)
        return n;
        
        unordered_map<int,int> m[n];
        int d;
        int ans =2;
        
        for(int i =1; i<n;i++){
            for(int j = i-1; j>=0;j--){
                d = a[i] - a[j];
                if(m[j].count(d)){
                    m[i][d] = max(m[i][d], 1+ m[j][d]);
                    ans = max(ans, m[i][d]);
                }
                else{
                    if(!m[i].count(d)){
                        m[i][d] = 2;
                    }
                }
            }
        }
        return ans;
    }
};
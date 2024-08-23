class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int size = 0, start, end, mid, index;
       vector<int> LIS(n);
       // 0 based indexing
       LIS[0] =a[0];
       
       for(int i =1;i <n;i++){
           start = 0, end = size;
           index = size+1;
           while(start <= end){
               mid = (start+end)/2;
               if(LIS[mid] < a[i]){
                   start = mid+1;
               }
               else if(LIS[mid] == a[i]){
                   index = mid;
                   break;
               }
               else{
                   index = mid;
                   end = mid-1;
               }
           }
           
           LIS[index] = a[i];
           size = max(size,index);
       }
       return size+1;
    }
};
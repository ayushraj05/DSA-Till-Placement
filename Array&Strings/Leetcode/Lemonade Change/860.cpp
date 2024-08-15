class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        int n = bills.size();
        for(int i =0 ; i< n;i++){
            // i = 5;
            if(bills[i] == 5){
                five++;
            }
            // i = 10;
            if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            // i = 20;
            if(bills[i] == 20){
                // 10 + 5
                if(ten && five){
                    ten--;
                    five--;
                    twenty++;
                }
                // 5+ 5+5
                else if( five >= 3){
                    five -= 3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
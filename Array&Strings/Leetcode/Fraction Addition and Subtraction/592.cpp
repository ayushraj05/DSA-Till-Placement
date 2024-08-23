class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.size();
        while(i < n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-' );

            if(expr[i] == '+' || expr[i] == '-'){
                i++;
            }

            // making numeroato
            while(i<n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currNume = (currNume* 10) + val;
                i++;
            }
            i++; // this is for the slash;

            if(isNeg == true){
                currNume *= -1;
            }

            // buuild the curr denominator;

            while(i <n && isdigit(expr[i])){
                int val = expr[i] - '0';
                currDeno = (currDeno*10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = currDeno * deno;

        }
        
        int GCD = abs(__gcd(nume,deno));
        
        nume /= GCD;
        deno /= GCD;
        return to_string(nume) + '/' + to_string(deno);

    }
};
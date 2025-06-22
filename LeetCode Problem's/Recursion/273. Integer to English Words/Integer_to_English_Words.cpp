class Solution {
public:
    // Approach - Recursion T.C = O(log10 num) , S.C = O(log10 num) where    , log10 num + 1 = no of digits in num
    // storing the name of some base numbers as their name cant be derived
    unordered_map<int, string> belowTen = {{1,"One"}, {2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
    unordered_map<int, string> belowTwenty = {{10,"Ten"}, {11, "Eleven"}, {12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
    // the are names of the digits when they are at Tens Place.
    unordered_map<int, string> belowHundred = {{1,"Ten"}, {2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};

    string solve(int num){
        // Consider differnret cases of what number can be
        if(num<10){ // 7     
            return belowTen[num];
        }
        else if(num < 20){ // 17
            return belowTwenty[num];
        }
        else if(num < 100){ //97
            return belowHundred[num/10] + ((num % 10 !=0)? " " + solve(num%10): "");
        }
        else if(num < 1000){ //997 - less than thoudsand - we treat them as hundreds
            return solve(num/100) + " Hundred" + ((num % 100 !=0)? " " + solve(num%100): "");     // in each case check for remianig part if "0" do nothing
        }
        else if(num < 1000000){ //999997 -less than million - we treat them as thousands
            return solve(num/1000) + " Thousand" + ((num % 1000 !=0) ?" " + solve(num%1000): "");
        }
        else if(num < 1000000000){ // 999999997 - less than billion number - we treat them as miilions
            return solve(num/1000000) + " Million" + ((num % 1000000 != 0)?" " + solve(num%1000000): "");
        }
        // otherwise
        // num >= 1000000000 - more tham billion we treat  them as billions itself
        return solve(num/1000000000) + " Billion" + ((num % 1000000000 != 0)?" " + solve(num%1000000000): "");
    }

    string numberToWords(int num) {
        // for edge case if num is 0
        if(num == 0){
            return "Zero";
        }

        return solve(num);
    }
};
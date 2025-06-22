class Solution {
public:
    // Approach- Hashing Type T.C= O(n) , S.C = O(1)
    string intToRoman(int num) {
        // Store given things
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string result = "";

        // traverse in both array using "i"
        for(int i=0;i<13;i++){
            if(num==0){ // means we got Roman so stop
                break;
            }
            int times = num/val[i]; // finds how many times a val[i] can divide num if 0 means means nothing will hapeen and num will no reduce
            while(times){
                result = result + sym[i];
                times--;
            }
            num = num % val[i];
        }
        return result;
    }
};
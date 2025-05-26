class Solution {
private:
    void helper(string digits,string output,int index,vector<string> &ans,string mapping[]){
        // Base Case
        if(index>=digits.length()){
            // add the made output to the ans
            ans.push_back(output);
            return; // stop here
        }

        // Derive the actual number from the "digits" string
        int number = digits[index] - '0'; // as it will be giving a char we need integer so do this to get integer
        string value = mapping[number]; // to get the all characters possible corresponding to that number

        for(int i=0;i<value.length();i++){ // access each character individually 
            // add it into output
            output.push_back(value[i]);
            helper(digits,output,index+1,ans,mapping); // call the function for next number now
            // when backtrack remove the added element first  (because here we are not doing include , exclude wala scenario)
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans; // to store all possible letter combinations that can made from digits
        string output = ""; // to store a single letter string made
        int index = 0; // to keep track of digits

        if(digits.empty()){
            return ans;
        }

        // To store mapping of a single digit to what letter we can derive from it
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        // Actual function to form all combinations
        helper(digits,output,index,ans,mapping);

        // return all the combinations
        return ans;
    }
};
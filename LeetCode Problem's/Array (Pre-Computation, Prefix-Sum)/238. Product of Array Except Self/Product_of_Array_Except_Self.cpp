class Solution {
public:
    // Approach - 1 Bruteforce , T.C = O(n^2)
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        // for each element calculate total product by leaving itself in that product
        for(int i=0;i<nums.size();i++){
            int product = 1;
            for(int j=0;j<nums.size();j++){
                if(i!=j){ // leave itself
                    product = product * nums[j];
                }
            }
            result.push_back(product);
        }

        return result;
    }
    */
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightProduct(n,0);
        vector<int> result;

        rightProduct[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            rightProduct[i] = nums[i] * rightProduct[i+1];
        }

        int reqTotal = 1;
        int leftProduct = 1;
        for(int i=0;i<n-1;i++){
            reqTotal = leftProduct * rightProduct[i+1];
            result.push_back(reqTotal);
            leftProduct = leftProduct * nums[i];
        }

        result.push_back(leftProduct);
        return result;

    }
    */

    // Approach 2 : Using Division opereator , T.C = O(n) , S.C = O(1)
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        int totalProduct = 1;
        int ProdWithoutZero = 1; // stores roduct without taking zero
        int countZeros = 0; // to count no of zeroes

        for(int i=0;i<n;i++){
            totalProduct = totalProduct * nums[i];
            if(nums[i]!=0){
                ProdWithoutZero = ProdWithoutZero * nums[i];
            }
            else if(nums[i]==0){
                countZeros++;
            }
        }

        // traverse each element 
        for(int i=0;i<n;i++){
            if(nums[i]!=0){ 
                if(countZeros>0){ // means if zeroes exist in list so product will be 0
                    result[i] = 0;
                }
                else{
                    result[i] = totalProduct/nums[i];
                }
            }
            else{
                if(countZeros>1){ // checks if their are still more zeroes if we allowed one
                    result[i] = 0;
                }
                else{
                    result[i] = ProdWithoutZero;
                }
            }
        }

        return result;
    }
    */

    // Approach - 3 Pre-Computation with extra space
    // T.C = O(n) , S.C = O(n)
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        // stores product of all elements left to ith index
        vector<int> leftProduct(n,0);
        // stores product of all elements right to ith index
        vector<int> rightProduct(n,0);

        // all left elements product for ith index
        leftProduct[0] = 1;
        for(int i=1;i<n;i++){
            leftProduct[i] = nums[i-1] * leftProduct[i-1];
        }

        // all lefrightt elements product for ith index
        rightProduct[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            rightProduct[i] = nums[i+1] * rightProduct[i+1];
        }

        // store answer for each ith index
        for(int i=0;i<n;i++){
            result[i] = leftProduct[i] * rightProduct[i];
        }
        return result;
    }
    */

    // Approach - 4 Pre-Computation without extra space
    // T.C = O(n) , S.C = O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        // We will store leftproduct in result first
        // then using a rightproduct variable calculate answer to prevent using extra space

        // all left elements product for ith index
        result[0] = 1;
        for(int i=1;i<n;i++){
            result[i] = nums[i-1] * result[i-1];
        }

        int rightProduct = 1;
        // store answer for each ith index
        for(int i=n-1;i>=0;i--){
            result[i] = result[i] * rightProduct;
            rightProduct = rightProduct * nums[i];
        }
        return result;
    }
};
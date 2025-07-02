class Solution {
public:
    // T.C = O(n) , S.C = O(1)
    int getMaxLen(vector<int>& nums) {
         
        int ans = 0; // max length of subarray with positive product
        int pos = 0;  // max length of subarray with positive product till the arr[i]
        int neg = 0;   // max length of subarray with negative product till the arr[i]

        // traverse all elements
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){ // agar zero wala element aa jaye 
                pos = 0;
                neg = 0;
            }
            else if(nums[i]>0){ // agar postive element aaye
                if(neg==0){
                    pos++;
                }
                else{
                    pos++;
                    neg++;
                }
            }
            else if(nums[i]<0){ // agar negative element aaye
                if(neg==0){
                    neg = pos + 1;
                    pos = 0;
                }
                else{
                    int temp = pos;
                    pos = neg + 1;
                    neg = temp + 1;
                }
            }
            // har bar hum ek ek element ko check kar rahe honge isliya jo pos hoga usse ans ke sath check karte rehna
            ans = max(ans,pos);
        }

        return ans;
    }



    // Approach 2 - T.C = O(n)
    /*
    int getMaxLen(vector<int>& nums) {      
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;){
            int start = i;
            while(start < n && nums[start]==0){
                start++;
            }
            int end = start;

            // total -ve no lement ka coiunt nikal lo har selected subarray ke liya 
            // aur unmei se first -ve aur last -ve ka index bhi nikal kar rakho
            int count = 0;
            int sn = -1;
            int en = -1;
            while(end < n && nums[end]!=0){ // to consider only 1 subarray at a time agar zeroes array mei ha too
                if(nums[end]<0){
                    if(sn==-1) sn = end;
                    en = end;
                    count++;
                }
                end++;
            }


            if(count%2==0) ans = max(ans,end-start); // matlabeven no of negative hai direct ans nikal sakte
            else{ // mtalb odd no of -ve
                ans = max(ans,end-sn-1); // agar first -ve consider na kare
                ans = max(ans,en-start); // agar last -ve consider naa kare
            }
            i = end+1; // next subarray check karte
        }
        return ans;
    }
    */
};
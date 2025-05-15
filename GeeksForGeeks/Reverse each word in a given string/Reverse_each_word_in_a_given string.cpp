class Solution {
  public:
    string helperReverse(string &temp){
        int start = 0 , end = temp.length() - 1;
        while(start<=end){
            swap(temp[start],temp[end]);
            start++;
            end--;
        }
        return temp;
    }
    string reverseWords(string &s) {
        // result
        string result = "";
        
        // code here
        int n = s.length();
        
        // Ignore Leading Spaces
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        
        string temp;
        for(int k=i;k<n;k++){
            if(s[k]!=' '){
                temp.push_back(s[k]);
            }
            if(s[k]==' ' || k==n-1){
                while(s[k+1]==' '){
                    k++;
                }
                if(k==n-1){
                    result = result + helperReverse(temp); 
                }
                else{
                    result = result + helperReverse(temp) + " ";
                }
                temp = "";
            }
        }
        
        return result;
        
    }
};
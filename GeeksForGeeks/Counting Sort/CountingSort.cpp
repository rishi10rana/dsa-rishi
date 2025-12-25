class Solution {
  public:
    // T.C = O(n) + O(n) + O(k) + O(n) + O(n) = O(4n + k) = O(n)
    // S.C = O(n) + O(k+1)
    string countSort(string s) {
        // code here
        
        // apply standard count sort algorithm
        int n = s.length();
        int k = INT_MIN;
        for(int i=0;i<n;i++){
            k = max(k, int(s[i]));
        }
        
        int count[k+1];
        memset(count, 0 , sizeof(count));
        
        char b[n];
        
        // count each character occurance
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        
        // update count array to store their position till which position each character should be stored
        for(int i=1;i<=k;i++){
            count[i] = count[i] + count[i-1];
        }
        
        // store the correct sorted order characters in new char array in correct indexes
        // need to scan original string from end
        for(int j=n-1;j>=0;j--){
            b[--count[s[j]]] = s[j];
        }
        
        // copy these sorted chracters in original string
        for(int i=0;i<n;i++){
            s[i] = b[i];
        }
        
        return s;
    }
};
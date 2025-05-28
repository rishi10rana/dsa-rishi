class Solution {
  public:
    int firstOccurance(vector<int> &arr,int x){
        int low = 0;
        int high = arr.size()-1;
        int mid = low + (high-low)/2;
        int temp = -1; // ye make sure karega agar element nahi mila to -1 return kare
        
        while(low<=high){
            if(arr[mid]==x){
                temp = mid; // index ko store kara do aur update kardo raho to find first occurance
                high = mid - 1; // kyuki agar first occurance jaha element mila uske mostly left mei hi ho sakta
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else if(arr[mid]>x){
                high = mid - 1;
            }
            mid = low + (high-low)/2;
        }
        return temp;
    }
    
    int lastOccurance(vector<int> &arr,int x){
        int low = 0;
        int high = arr.size()-1;
        int mid = low + (high-low)/2;
        int temp = -1; // ye make sure karega agar element nahi mila to -1 return kare
        
        while(low<=high){
            if(arr[mid]==x){
                temp = mid; // index ko store kara do aur update kardo raho to find last occurance
                low = mid + 1; // kyuki agar last occurance ,jaha element mila uske mostly right mei hi ho sakta
            }
            else if(arr[mid]<x){
                low = mid + 1;
            }
            else if(arr[mid]>x){
                high = mid - 1;
            }
            mid = low + (high-low)/2;
        }
    return temp;
    }
    
    vector<int> find(vector<int>& arr, int x) {
        // code here
        vector<int> ans; // To store answer
        int first = firstOccurance(arr,x);
        int last = lastOccurance(arr,x);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
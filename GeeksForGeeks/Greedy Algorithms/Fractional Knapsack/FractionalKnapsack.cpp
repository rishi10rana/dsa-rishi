// class implemented

struct Item{
    int value;
    int weight;
    double valueByWt;
};

bool comp(Item a, Item b){
    return a.valueByWt > b.valueByWt;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        // no of items
        int n = val.size();
        
        // store info of items
        vector<Item> items(n);
        for(int i=0;i<n;i++){
            items[i].value = val[i];
            items[i].weight = wt[i];
            items[i].valueByWt = (double)val[i]/wt[i];
        }
        
        // sort the items bassed on their value/ weight ratio in descending
        sort(items.begin(), items.end(), comp);
        
        double maxValue = 0;
        int i = 0;
        // select itms an place them in bag
        
        while(i<n && capacity > 0){
            if(items[i].weight<=capacity){ // can place this item completely
                capacity = capacity - items[i].weight;
                maxValue = maxValue + items[i].value;
            }
            else{
                maxValue = maxValue + ((double)capacity/items[i].weight) * items[i].value;
                capacity = 0; 
            }
            i++;
        }
        
        return maxValue;
    }
};

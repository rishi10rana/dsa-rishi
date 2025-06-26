/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/
/* The below method sorts the stack s
you are required to complete the below method */

// T.C = O(n*n) S.C = O(n*n)
static void sortedInsert(stack<int> &s,int num){
    // base case insert num if stack empty or top < num means yahi sahi jagah hai num ke liya
    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }
    // matlab abbhi bhi jagah dundhni hai to top ko nikalate raho
    int temp = s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(temp);
}

void SortedStack ::sort() {
    // base case stop and return back when stack becomes empty
    if(s.empty()){
        return;
    }
    // store element before popping
    int num = s.top();
    s.pop();
    // pop the next element
    sort();
    // jab wapis aao to element ko insert karo n sorted way
    sortedInsert(s,num);
}

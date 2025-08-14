class Node{
    public:
    int freq;
    char ch;
    Node *left, *right;
    
    Node(int freq, char ch){
        this->freq = freq;
        this->ch = ch;
        this->left = NULL;
        this->right = NULL;
    }
}
;
// Custom comp
class comp{
    public:
    bool operator()(Node *a, Node *b){
        // jo bhi hum comp mei jo tarika use karte compare karne ka uska ulta karte heap me
        return a->freq > b->freq;
    }
};

class Solution {
  public:
  
    // Data Left Right
    void preorder(Node* root, string& temp, vector<string>& result){
        // base case
        if(root == NULL){
            return;
        }
        // agar leaf node tak pahuch gaye
        if(root->left==NULL && root->right==NULL){
            result.push_back(temp);
            return;
        }
        
        // Left jaate to 0 leta
        temp.push_back('0');
        preorder(root->left, temp, result);
        temp.pop_back(); // jab wapis aao
        
        // Right jaate to 1 leta
        temp.push_back('1');
        preorder(root->right, temp, result);
        temp.pop_back();
    }
  
  
    // Greedy Approach - sabse chota wale freq wale characters ko choose karo phela 
    // T.C = O(N * logN + N) = O(NlogN)
    // S.C = O(N)
  
  
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        
        // build the min heap based on freq (jis ki freq choti wo sabse phela)
        priority_queue<Node *, vector<Node *>, comp> pq;
        
        // node bana kar prority queue mei daalo
        for(int i=0;i<N;i++){
            pq.push(new Node(f[i] ,S[i]));
        }
        
        
        // Making the HUFFMAN TREE
        
        // ab two nodes jinki minimum freq hai unhe pakad kar pq is nakalo aur unhe merge karke ek new node banao
        while(pq.size() > 1){
            Node* first = pq.top();
            pq.pop();
            Node* second = pq.top();
            pq.pop();
            
            // merge them
            Node* root = new Node(first->freq + second->freq, '$');
            root->left = first;
            root->right = second;
            // isko wapis pq mei daaldo
            pq.push(root);
        }
        
        // pq mei last mei ek hi node bachta wo root node hota huffman tree ka wo lelo
        // Root Node lelo ab
        Node* root = pq.top();
        pq.pop();
        
        // ab huffman tree ke huffman codes ko preorder tarika se ek vector mei daal kar return karna
        vector<string> result;
        string temp = "";
        
        preorder(root, temp, result);
        return result;
    }
};
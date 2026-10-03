struct Node{
    Node* Links[26];
    bool flag = false;

    bool iscontainchar(char ch){
        return (Links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        Links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return Links[ch - 'a'];
    }
    void setend (){
        flag = true;
    }
};
class Trie {
private:
    Node* root;
public:
  
    Trie(){
        root = new Node();
    }
    
    void insert(string word) {
         Node* node = root ;

         for(int i=0;i<word.size();i++){

            if(!node->iscontainchar(word[i])){
                node->put(word[i],new Node());
            }
            // movie to the reference trie.
            node = node->get(word[i]);
         }
         node->setend();
    }
    
    bool search(string word) {
         Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->iscontainchar(word[i])){
                node = node->get(word[i]);
            }else{
                return false;
            }
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
          Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->iscontainchar(prefix[i])){
                node = node->get(prefix[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
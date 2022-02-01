struct Node{
    Node *links[26];
    int currentPrefix = 0;
    int currentEnd = 0;
    
    bool isKeyContains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    void incrementPrefix()
    {
        currentPrefix++;
    }
    void decrementPrefix()
    {
        currentPrefix--;
    }
    void incrementEnd()
    {
        currentEnd++;
    }
    void decrementEnd()
    {
        currentEnd--;
    }
    int getWords(){
        return currentEnd;
    }
    int getPrefix()
    {
        return currentPrefix;
    }
    
};

class Trie{
    private: Node *root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(!node->isKeyContains(word[i]))
            {
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
            node->incrementPrefix();
        }
        node->incrementEnd();
        
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(node->isKeyContains(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getWords();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(node->isKeyContains(word[i]))
            {
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *node = root;
        for(int i =0 ; i < word.length(); i++)
        {
            if(node->isKeyContains(word[i])){
                node = node->get(word[i]);
            }
            node->decrementPrefix();
        }
        node->decrementEnd();
    }
};

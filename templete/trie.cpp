// note: using a class is only necessary if you want to store data at each node.
// otherwise, you can implement a trie using only hash maps.
struct TrieNode {
    int data;
    unordered_map<char, TrieNode*> children;
    TrieNode() : data(0), children(unordered_map<char, TrieNode*>()) {}
};

TrieNode* buildTrie(vector<string> words) {
    TrieNode* root = new TrieNode();
    for (string word: words) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // at this point, you have a full word at curr
        // you can perform more logic here to give curr an attribute if you want
    }

    return root;
}

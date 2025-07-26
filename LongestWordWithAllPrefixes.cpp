#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, string& path, string& best) {
        // Only update if the path is longer or lexicographically smaller
        if (path.length() > best.length() || 
           (path.length() == best.length() && path < best)) {
            best = path;
        }

        for (int i = 0; i < 26; i++) {
            TrieNode* child = node->children[i];
            if (child && child->isEnd) {
                path.push_back('a' + i);
                dfs(child, path, best);
                path.pop_back();  // backtrack
            }
        }
    }

    string findLongestCompleteString() {
        string path = "", best = "";
        dfs(root, path, best);
        return best.empty() ? "None" : best;
    }
};

string longestCompleteString(vector<string>& words) {
    Trie trie;
    unordered_set<string> wordSet(words.begin(), words.end());

    for (string& word : words) {
        trie.insert(word);
    }

    return trie.findLongestCompleteString();
}

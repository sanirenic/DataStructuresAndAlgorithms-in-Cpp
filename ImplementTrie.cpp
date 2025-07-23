/*Problem Statement: Implement a Trie data structure that supports the following methods:

Insert (word): To insert a string `word` in the Trie.
Count Words Equal To (word): Return the count of occurrences of the string word in the Trie.
Count Words Starting With (prefix): Return the count of words in the Trie that have the string “prefix” as a prefix.
Erase (word): Delete one occurrence of the string word from the Trie.*/


#include <bits/stdc++.h>
using namespace std;

// TrieNode definition
class TrieNode {
public:
    TrieNode* children[26]; // for a-z
    int wordCount;          // number of times this word ends here
    int prefixCount;        // number of words passing through this node

    TrieNode() {
        wordCount = 0;
        prefixCount = 0;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~TrieNode() {
        // Recursively delete all children
        for (int i = 0; i < 26; i++) {
            if (children[i])
                delete children[i];
        }
    }
};

// Trie definition
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = new TrieNode();
            node = node->children[i];
            node->prefixCount++; // this prefix is used
        }
        node->wordCount++; // word ends here
    }

    // Count words equal to a given word
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (node->children[i] == nullptr)
                return 0;
            node = node->children[i];
        }
        return node->wordCount;
    }

    // Count words starting with a given prefix
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (node->children[i] == nullptr)
                return 0;
            node = node->children[i];
        }
        return node->prefixCount;
    }

    // Erase a word from the trie (one occurrence)
    void erase(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            TrieNode* next = node->children[i];
            next->prefixCount--;  // one fewer word passes through here
            node = next;
        }
        node->wordCount--; // one fewer word ends here
    }

    // Destructor to release memory
    ~Trie() {
        delete root;
    }
};



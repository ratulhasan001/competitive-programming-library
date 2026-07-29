#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode *children[ALPHABET];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET; i++) children[i] = nullptr;
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *crawl = root;
    for (char c : key) {
        int index = c - 'a';
        if (!crawl->children[index]) crawl->children[index] = new TrieNode();
        crawl = crawl->children[index];
    }
    crawl->isEndOfWord = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *crawl = root;
    for (char c : key) {
        if (!crawl->children[c - 'a']) return false;
        crawl = crawl->children[c - 'a'];
    }
    return crawl->isEndOfWord;
}

int32_t main() {
    TrieNode *root = new TrieNode();
    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        insert(root, word);
    }
    string query;
    cin >> query;
    cout << (search(root, query) ? "Found" : "Not Found") << endl;
    return 0;
}

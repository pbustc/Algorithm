#include <vector>
#include <string>

using namespace std;

// 前缀树的基本操作
// 此处以26个小写字母组成的字符串为例,用数组存储速度较快
// 若考虑到大小写及数字等组成的字符串,可用哈希表进行存储

struct Trie {
    bool isEnd; //是否到达一个字符串的结尾
    vector<Trie *> children; // 子节点的指针数组
    Trie() {
        this->children = vector<Trie *>(26, nullptr); // 此处的字符为小写英文字母
        this->isEnd = false;
    }
};

// 将一个字符串插入到前缀树中
void insert(string s, Trie *root){
    Trie *cur = root;
    for(auto x : s){
        if(cur->children[x - 'a'] == nullptr){
          	cur->children[x - 'a'] = new Trie();
        }
    cur = cur -> children[x - 'a'];
   	}
    cur -> isEnd = true;
}

// 从前缀树中查找相应的字符串
bool search(string s, Trie *root){
    Trie *cur = root;
    for(auto x : s){
        if(cur->children[x - 'a'] == nullptr)
            return false;
        cur = cur -> children[x - 'a'];
    }
    return cur->isEnd;
}


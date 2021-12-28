#include <vector>
#include <string>

using namespace std;

// ǰ׺���Ļ�������
// �˴���26��Сд��ĸ��ɵ��ַ���Ϊ��,������洢�ٶȽϿ�
// �����ǵ���Сд�����ֵ���ɵ��ַ���,���ù�ϣ����д洢

struct Trie {
    bool isEnd; //�Ƿ񵽴�һ���ַ����Ľ�β
    vector<Trie *> children; // �ӽڵ��ָ������
    Trie() {
        this->children = vector<Trie *>(26, nullptr); // �˴����ַ�ΪСдӢ����ĸ
        this->isEnd = false;
    }
};

// ��һ���ַ������뵽ǰ׺����
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

// ��ǰ׺���в�����Ӧ���ַ���
bool search(string s, Trie *root){
    Trie *cur = root;
    for(auto x : s){
        if(cur->children[x - 'a'] == nullptr)
            return false;
        cur = cur -> children[x - 'a'];
    }
    return cur->isEnd;
}


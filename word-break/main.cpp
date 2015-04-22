#include <cstddef>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

// hasher for const char*
size_t str_hash(const char* str, int len) {
    size_t h = 0;
    while(len-->0) {
        h = 5*h + *str;
        ++str;
    }
    return h;
}

const size_t AVLTREE_MAX_HEIGHT = 62;

struct AVLTreeNode {
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;
    size_t key;
    int value;
    AVLTreeNode(size_t k=0, int v=0) : left(nullptr), right(nullptr), height(1), key(k), value(v) {}
};

int avl_height(AVLTreeNode* root) {
    return root?root->height:0;
}

int avl_height_update(AVLTreeNode* root) {
    // assert(root!=NULL);
    return (root->height = std::max(avl_height(root->left), avl_height(root->right)) + 1);
}

int avl_balance_factor(AVLTreeNode* root) {
    // assert(root!=NULL);
    return avl_height(root->left) - avl_height(root->right);
}

AVLTreeNode* avl_rotate_left(AVLTreeNode* root) {
    // assert(root!=nullptr);
    AVLTreeNode* right = root->right;
    // assert(right!=nullptr);
    root->right= right->left;
    right->left = root;
    avl_height_update(root);
    avl_height_update(right);
    return right;
}

AVLTreeNode* avl_rotate_right(AVLTreeNode* root) {
    // assert(root!=nullptr);
    AVLTreeNode* left = root->left;
    // assert(right!=nullptr);
    root->left = left->right;
    left->right = root;
    avl_height_update(root);
    avl_height_update(left);
    return left;
}

// true:    insert;
// false:   update;
bool avl_insert(AVLTreeNode*& root, size_t key, int value) {
    AVLTreeNode* path[AVLTREE_MAX_HEIGHT] = {nullptr};
    int top_pos = 1;
    AVLTreeNode* curr = root;
    while(curr!=NULL) {
        path[top_pos++] = curr;
        if(curr->key>key) {
            curr = curr->left;
        } else if(curr->key<key) {
            curr = curr->right;
        } else {
            return false;
        }
    }

    curr = new AVLTreeNode(key, value);
    AVLTreeNode* parent = path[--top_pos];
    if(parent==nullptr) root = curr;
    else if(parent->key<key) parent->right = curr;
    else parent->left = curr;

    while(parent!=nullptr) {
        int parent_balance_factor = avl_balance_factor(parent);
        int curr_balance_factor = avl_balance_factor(curr);
        if(parent_balance_factor==2) {
            if(curr_balance_factor==-1) {
                curr = avl_rotate_left(curr);
                parent->left = curr;
            }

            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_right(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==-2) {
            if(curr_balance_factor==1) {
                curr = avl_rotate_right(curr);
                parent->right = curr;
            }


            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_left(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==0) {
            // origin: left - right = -1
            // now: left = left + 1
            break;
        }
        avl_height_update(parent);
        curr = parent;
        parent = path[--top_pos];

    }

    return true;
}


bool avl_search(AVLTreeNode* const root, size_t key, int* value) {
    AVLTreeNode* temp = root;
    while(temp) {
        if(temp->key==key) {
            if(value) *value = temp->value;
            return true;
        }
        if(temp->key < key) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return false;
}

bool avl_delete(AVLTreeNode*& root, size_t key, int* value) {
    AVLTreeNode* path[AVLTREE_MAX_HEIGHT] = {nullptr};
    int top_pos = 1;
    AVLTreeNode* curr = root;
    AVLTreeNode* remove = nullptr;
    while(curr!=NULL) {
        if(curr->key==key)
            break;
        path[top_pos++] = curr;
        if(curr->key>key)
            curr = curr->left;
        else 
            curr =curr->right;
    }
    if(curr==nullptr)
        return false;

    remove = curr;
    if(curr->left!=nullptr && curr->right!=nullptr)
    {
        remove = curr->left;
        path[top_pos++] = curr;
        while(remove->right) {
            path[top_pos++] = remove;
            remove = remove->right;
        }
    }

    AVLTreeNode* parent = path[--top_pos];
    if(parent==nullptr) {
        // assert(remove==curr);
        root = remove->left ? remove->left : remove->right;
        delete(remove);
        return true;
    }

    if(remove!=curr) {
        curr->key = remove->key;
        curr->value = remove->value;
    }
    curr = remove->left ? remove->left : remove->right;
    if(remove==parent->left)
        parent->left = curr;
    else
        parent->right = curr;

    delete(remove);

    while(parent!=nullptr) {
        parent->height = avl_height_update(parent);
        int parent_balance_factor = avl_balance_factor(parent);
        if(parent_balance_factor==2) {
            int curr_balance_factor = avl_balance_factor(parent->left);
            if(curr_balance_factor==-1)
                parent->left = avl_rotate_left(parent->left);
            
            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_right(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==-2) {
            int curr_balance_factor = avl_balance_factor(parent->right);
            if(curr_balance_factor==1)
                parent->right = avl_rotate_right(parent->right);

            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_left(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor == 1 || parent_balance_factor == -1) {
            break;
        }
        //curr = parent;
        avl_height_update(parent);
        parent = path[--top_pos];
    }
    return true;
}

void print_tree_inorder(AVLTreeNode* root, int level = 0) {
    if(!root) return;
    if(!level) cout << "----------" << endl;
    print_tree_inorder(root->left, level+1);
    cout << root->key << "(" << level << "," << root->height << "), ";
    print_tree_inorder(root->right, level+1);
    if(!level) cout << endl;
}


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size()==0) return false;
        AVLTreeNode* head = nullptr;
        int max_len = INT_MIN;
        int min_len = INT_MAX;
        for(auto& item : wordDict) {
            size_t h = str_hash(item.c_str(), item.size());
            //cout << "insert: " << item << " hash: " << h << endl;
            bool ret = avl_insert(head, h, 1);
            //print_tree_inorder(head);
            assert(ret);
            max_len = max(max_len, (int)item.size());
            min_len = min(min_len, (int)item.size());
        }
        vector<bool> reached(s.size()+1, false);
        reached[0] = true;
        for(int i=0; i<s.size(); ++i) {
            if(!reached[i]) continue;
            for(int len = min_len; len<=max_len && i+len<=s.size(); ++len) {
                size_t h = str_hash(s.c_str()+i, len);
                reached[i+len] = avl_search(head, h, nullptr);
            }
        }
        return reached[s.size()];
    }
};


int main(int argc, char** argv) {
    string str = "leetcode";
    unordered_set<string> dict({"leet", "code"});

    string str_2 = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
    unordered_set<string> dict_2({"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"});

    string str_3 = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
    unordered_set<string> dict_3({"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"});

    Solution s;
    cout << s.wordBreak(str, dict) << endl;
    cout << dict_2.size() << endl;
    cout << s.wordBreak(str_2, dict_2) << endl;
    cout << s.wordBreak(str_3, dict_3) << endl;

/*
    AVLTreeNode* head = nullptr;

    print_tree_inorder(head);

    avl_insert(head, 10, 10);
    print_tree_inorder(head);
    

    avl_insert(head, 20, 20);
    print_tree_inorder(head);
    
    avl_insert(head, 30, 30);
    print_tree_inorder(head);
    
    avl_insert(head, 40, 40);
    print_tree_inorder(head);
    
    avl_insert(head, 25, 25);
    print_tree_inorder(head);
    
    avl_insert(head, 24, 24);
    print_tree_inorder(head);
    
    avl_delete(head, 30, nullptr);
    print_tree_inorder(head);

    avl_delete(head, 40, nullptr);
    print_tree_inorder(head);
*/
    return 0;
}

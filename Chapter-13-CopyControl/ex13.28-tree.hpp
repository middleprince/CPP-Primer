#ifndef ex13_28_tree_h
#define ex13_28_tree_h

#include <string>
using std::string;
class TreeNode {
public:
    TreeNode() : value(string()), count(new int(1)), 
        left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &old) : value(old.value), 
        count(old.count), left(old.left), right(old.right) { ++*count;}
    TreeNode & operator=(const TreeNode &rval);
    
    ~TreeNode() {
        if(--*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }  
            if (right) {
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;

};

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &old) : root(new TreeNode(*old.root)) {}
    BinStrTree & operator=(const BinStrTree &rval);

    ~BinStrTree() {
        delete root; 
    }

private:
    TreeNode *root;
};


TreeNode & TreeNode::operator=(const TreeNode &rval) {
    ++*rval.count;
    if(--*count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }  
        if (right) {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
    value = rval.value;
    count = rval.count;
    left = rval.left;
    right = rval.right;

    return *this;
}

BinStrTree & BinStrTree::operator=(const BinStrTree &rval) {
    auto *newroot = new TreeNode(*rval.root);
    delete root;
    root = newroot;
    return *this;
}


#endif

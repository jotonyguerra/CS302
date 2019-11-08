#include <iostream>
#include <fstream>

using namespace std;

template <class Type>
class mobileTree
{
    struct binTreeNode
    {
        Type wL, dL, wR, dR;

        binTreeNode *left;
        binTreeNode *right;
    };

    public:
    void buildMobile(binTreeNode*, ifstream& file);
    int getWeight(binTreeNode*);
    void destroyTree(binTreeNode*);
};


// template <class Type>
// void buildMobile(binTreeNode<Type> *r, ifstream &inFile);

// template <class Type>
// int getWeight(binTreeNode<Type> *r);
// //return a negative number if not balanced.

// //post order traversal to destroy tree.
// template <class Type>
// void destroyTree(binTreeNode<Type> *r);

template <class Type>
void mobileTree<Type>::buildMobile(binTreeNode tree, istream&inFile) 
{
    Type tempWL, tempDL, tempWR, tempDR; 
    inFile.open();

    inFile >> tempWL;
    tree = new binTreeNode; 
    
    inFile.close();
};
template <class Type>
int mobileTree<Type>::getWeight(binTreeNode * tree) {
    int temp;

    return temp;
};

template <class Type>
void mobileTree<Type>::destroyTree(binTreeNode *r) {
    if (r != NULL) {
        destroyTree(r->left);
        destroyTree(r->right);
    }
        
    delete r; 
};
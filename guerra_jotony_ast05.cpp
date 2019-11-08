#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
//#include "mobileTreeclass.cpp"
using namespace std;

template <class Type>
struct binTreeNode
{
    Type wL, dL, wR, dR;

    binTreeNode<Type> *left;
    binTreeNode<Type> *right;
};

// struct binTreeNode* newNode(int data) {
//   struct binTreeNode* tree = new(struct node);
//   tree->data = data;
//   tree->left = NULL;
//   tree->right = NULL;

//   return(tree);
// }

template <class Type>
void buildMobile(binTreeNode<Type> *r, ifstream& x, int);

template <class Type>
int getWeight(binTreeNode<Type> *r);
//return a negative number if not balanced.

//post order traversal to destroy tree.
template <class Type>
void destroyTree(binTreeNode<Type> *r);
template <class Type>
void preorderPrint( binTreeNode<Type> * r );

int main()
{
    ifstream x;
    binTreeNode<int> * root;
    string fileName;
    int rootwL, rootdL, rootwR, rootdR, count = 0;

    cout << "Enter input file: ";
    cin >> fileName;

    x.open(fileName.c_str());
    x >> rootwL >> rootdL >> rootwR >> rootdR;
    root->wL = rootwL;
    cout << "wL:" << root-> wL << endl;
    root->dL = rootdL;
    root->wR = rootwR;
    root->dR = rootwL;
    root->left = root->right = NULL;
    buildMobile(root, x, count);
    preorderPrint(root);
    //insert in preOrder Traversal.
    if (getWeight(root) > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    destroyTree(root);
    x.close();
    return 0;
};

template <class Type>
void buildMobile(binTreeNode<Type> *tree, ifstream& x, int count)
{
    int tempWL, tempDL, tempWR, tempDR;
    binTreeNode<int> * branch; 
    if (x.eof())
    {
        return;
    }
    x >> tempWL >> tempDL >> tempWR >> tempDR;
    branch = new binTreeNode<int>;
    branch->wL = tempWL; 
    branch->dL = tempDL;
    branch->wR = tempWR;
    branch->dR = tempDR;
    branch->left = branch->right = NULL;
    if (count == 0) {
        tree->left = branch;
    } else {
        tree = branch;
    }
    count++;
    //if first call then set tree left = branch?
    //tree = branch
    //   
    buildMobile(branch->right, x, count);
    buildMobile(branch->left, x, count);
    //buildMobile(tree->right, x); 
};
template <class Type>
int getWeight(binTreeNode<Type> *tree)
{
    int temp;

    return temp;
};

template <class Type>
void destroyTree(binTreeNode<Type> *r)
{
    if (r != NULL)
    {
        destroyTree(r->left);
        destroyTree(r->right);
    }

    delete r;
};

template <class Type>
 void preorderPrint( binTreeNode<Type> * r ) {
           // Print all the items in the tree to which root points.
           // The item in the root is printed first, followed by the
           // items in the left subtree and then the items in the
           // right subtree.
        if ( r != NULL ) {  // (Otherwise, there's nothing to print.)
           cout << "wL: " << r->wL << endl;
           cout << "dL: " << r->dL << endl;
           cout << "wR: " << r ->wR << endl;
           cout << "dR: " << r -> dR << endl;      // Print the root item.
           preorderPrint( r->left );    // Print items in left subtree.
           preorderPrint( r->right );   // Print items in right subtree.
        }
     }; // end preorderPrint()

// if (key < tree->key_value)
//     {
//         if (tree->left != NULL)
//             insert(tree->left, x);
//         else
//         {
//             tree->left = new node;
//             tree->left->key_value = key;
//             tree->left->left = NULL;  //Sets the left child of the child node to null
//             tree->left->right = NULL; //Sets the right child of the child node to null
//         }
//     }
//     else if (key >= tree->key_value)
//     {
//         if (tree->right != NULL)
//             insert(key, tree->right);
//         else
//         {
//             tree->right = new node;
//             tree->right->key_value = key;
//             tree->right->left = NULL;  //Sets the left child of the child node to null
//             tree->right->right = NULL; //Sets the right child of the child node to null
//         }
//     }

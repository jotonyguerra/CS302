/*Jotony Guerra
  CS302 section 1004
  10/22/19
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

/*
Templated Stuc 
Binary Tree Node
*/
template <class Type>
struct binTreeNode
{
    Type wL, dL, wR, dR;
    binTreeNode<Type> *left;
    binTreeNode<Type> *right;
};

/*
Functin to build mobile/binary tree from input file.
Recursive
*/
//template <class Type>
void buildMobile(binTreeNode<int> *&r, ifstream &infile)
{
    int tempWL, tempDL, tempWR, tempDR;
    if (infile.eof())
        return;
    
    r = new binTreeNode<int>;
    //read in from file
    infile >> tempWL >> tempDL >> tempWR >>tempDR;
    //store read in data into node of tree values
    r->wL = tempWL; 
    r->dL = tempDL;
    r->wR = tempWR;
    r->dR = tempDR;
    //set branches left and right null
    r->left = r->right = NULL;
    //recusrive conditions... probably need to fix this
    if (r->wL == 0)
    {
        buildMobile(r->left, infile);
    }
    if (r->wR == 0)
    {
        buildMobile(r->right, infile);
    } 

};

/*
Function returns weight of mobile and returns negative if 
*/
//template <class Type>
int getWeight(binTreeNode<int> *r)
{   
    int leftProduct = 0, rightProduct = 0, leftSide=0, rightSide=0;
    if (r == NULL)
        return 0; //return 
    
    if (r->wL == 0) {
        leftSide += getWeight(r->left);
    } else if (r->wL != 0) {
        leftSide = (r->wL);
    }
    if (r->wR == 0) {
        rightSide += getWeight(r->right);
    } else if (r->wR != 0) {
        rightSide = r->wR;
    }
    
    leftProduct = leftSide * r->dL;
    //cout << "Left side product: " << leftProduct << endl;
    rightProduct = rightSide * r->dR;
   // cout << "Right side product: " << rightProduct << endl;

    if (leftProduct != rightProduct) {
        return -1; 
    } else {
        return (leftSide + rightSide); //return random thing
    }


}
/* 
Function deletes the tree
*/
//template <class Type>
template <class Type>
void destroyTree(binTreeNode<Type> *r)
{
    if (r != NULL)
    {
        destroyTree(r->left);
        destroyTree(r->right);
        delete r;
    }
};
//Print Function
// template <class Type>
//  void preorderPrint( binTreeNode<Type> * r ) {
//            // Print all the items in the tree to which root points.
//            // The item in the root is printed first, followed by the
//            // items in the left subtree and then the items in the
//            // right subtree.
//         if ( r != NULL ) {  // (Otherwise, there's nothing to print.)
//            cout << "wL: " << r->wL << endl;
//            cout << "dL: " << r->dL << endl;
//            cout << "wR: " << r ->wR << endl;
//            cout << "dR: " << r -> dR << endl;      // Print the root item.
//            preorderPrint( r->left);    // Print items in left subtree.
//            preorderPrint( r->right);   // Print items in right subtree.
//         }
//      };
int main()
{
    binTreeNode<int> * r;
    ifstream infile;
    string file;
    int iwL, idL, iwR, idR;
    r = new binTreeNode<int>;

    cout << "Enter input file: ";
    cin >> file;
    infile.open(file.c_str());
    //create blank node
    r->wL = 0;
    r->dL = 0;
    r->wR = 0;
    r->dR = 0;
    r->left = r->right = NULL;
    if (!infile.is_open())
    {
        cout << "Error Opening File" << endl;
        exit(0);
    }
    
    buildMobile(r, infile);
    if (getWeight(r) >= 0) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    
    infile.close();
    destroyTree(r);
    //delete r;
    return 0;
}

/*Jotony Guerra
  CS302 section 1004
  10/22/19
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

template <class Type>
struct binTreeNode
{
    Type wL, dL, wR, dR;
    binTreeNode<Type> *left;
    binTreeNode<Type> *right;
};

//template <class Type>
//binTreeNode<int> *
void buildMobile(binTreeNode<int> *&r, ifstream &infile)
{
    int tempWL, tempDL, tempWR, tempDR;
    if (infile.eof())
        return;
    
    //binTreeNode<int> * temp = 
    r= new binTreeNode<int>;
    //read in from file
    infile >> tempWL >> tempDL >> tempWR >>tempDR;
    //store read in data into node of tree values
    r->wL = tempWL; 
    r->dL = tempDL;
    r->wR = tempWR;
    r->dR = tempDR;
    //set branches left and right null
    r->left = r->right = NULL;

    //output
    cout << r->wL << r->dL << r->wR << r->dR << endl;
    //recusrive conditions... probably need to fix this
    if (r->wL == 0)
    {
        cout << "\nleft\n";
        buildMobile(r->left, infile);
    }
    if (r->wR == 0)
    {
        cout << "\nright\n";
        buildMobile(r->right, infile);
    } 

    //redundant return
    return;
}

//template <class Type>
int getWeight(binTreeNode<int> *r)
{   
    int leftProduct = 0, rightProduct = 0, mathy, leftSide=0, rightSide=0;
    if (r == NULL)
        return 0; //return something..??
    
    //leftSide = getWeight(r->left);
    //rightSide = getWeight(r->right);
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

//template <class Type>
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
           preorderPrint( r->left);    // Print items in left subtree.
           preorderPrint( r->right);   // Print items in right subtree.
        }
     };
int main()
{
    binTreeNode<int> *r = new binTreeNode<int>;
    ifstream infile;
    int iwL, idL, iwR, idR;
    infile.open("MobileInput02.txt");
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
    //preorderPrint(r);
    destroyTree(r);
    infile.close();
    return 0;
}

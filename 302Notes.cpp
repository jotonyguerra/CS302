/* 
selection sort:
5 6 1 2 4.

1. find max element. // 6
2. move max element to the last position in array.
3. find next max in the reduced array // 5
4. and move 5 to the last position. 
//repeat.
*/

//3 iterators necessary for selection sort in LL

LL<int> list;
LL<int>::iterator it1, it2, it3;

it3=list.end(); //points to last node in list
int max = -1;

for (it1=list.begin(); it1 != it3; it1++) {

    if (max < *it1) {
        max = *it1;
        it2 = it1;
    }
}
list.update(it3,...);
it3--;
//need to swap elements. 
/*
9/16

insertion sort
3 6 4 2 1 8 5. 
[3] 6/6 4 2 8 5
(1) i <- 1
    j <- 0
    key <- 6 
[3 6] 4 1 8 5 

[3 6] 4/4 2 1 8 5
//6 is replaced by 4
(2) i <- 2
    j <- 1 
    key <- 4

[3 4 6] 2 1 8 5 

(3) i <-3
    j <-2
    key <- 2 

*/
// 9/25

//Binary Tree

//TREE must be null node terminated. so if node is not seen it is null
template <class Type>
struct binTreeNode {
    Type item;
    binTreeNode<Type> * left;
    binTreeNode<Type> * right;
};

int main() {
    binTreeNode<char> * root; 
    root = new binTreeNode<char>; //new object address is pointed at by root
    root -> item='V'; //stores V in new binTree from above
    root -> left= root->right = NULL; //Always close off precaution
    root -> left = new binTreeNode<char>; 
    root ->left->item ='Z'; 
    root->left->left = NULL;
    root->left->right=NULL; //precaution
    root->right= new binTreeNode<char>;
    root->right->item = 'A';
    root->right->left=NULL;
    root->right->right=NULL;
    binTreeNode<char> * bIter;
    bIter = root; 
    bIter = bIter-> left;
    bIter->left = new binTreeNode<char>;
    bIter =bIter-> left;
}

/* Binary Trees
recursive definition of a binary tree-
-empty binary tree
-a binary tree node whose left pointer points to a binary tree
-a binary tree node whose right pinter points to a binary tree; 
null pointer by default is a binary tree.

each nodes is its own binary tree.
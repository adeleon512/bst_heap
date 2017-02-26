//
// Created by Adam on 2/26/2017.
//

#ifndef BST_HEAP_BST_3358_H
#define BST_HEAP_BST_3358_H

/*
 * 		Filename: bst_3358.h
 *  	Created on: Apr 22, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structures
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 6
 *      Description: This is a header template for a binary search tree. it
 *      contains all of the necessary functions for the BST implementation.
 */

#include <iostream>
#include <cassert>
#include <assert.h>

using namespace std;

template<class ItemType>
class BST_3358 {
public:


    //Constructors and destructor
    BST_3358();

    ~BST_3358();

    /****************************
     makeEmpty

     Function: Removes all the items from the BST.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();


    /****************************
     insertItem

     Function: Adds newItem to the BST.
     Postconditions: newItem is in the proper position for a BST.
     *****************************/
    void insertItem(const ItemType &);


    /****************************
     findItem

     Function: Determines if target is in BST.
     Postconditions: Returns true if the item is in the BST, else false.
     *****************************/
    bool findItem(const ItemType &x);

    /****************************
     findMin

     Function: Finds minimum element in BST.
     Preconditions: BST has at least one node.
     Postconditions: Returns the smallest element in the BST.
     *****************************/
    ItemType findMin();

    /****************************
     findMax

     Function: Finds maximum element in BST.
     Preconditions: BST has at least one node.
     Postconditions: Returns the largest element in the BST.
     *****************************/
    ItemType findMax();

    /****************************
     countNodes

     Function: Counts the number of nodes in the BST
     Postconditions: returns the number of nodes in the BST
     *****************************/
    int countNodes();

    /****************************
     preOrderTraversal

     Function: prints the preOder (Node, Left, Right) traversal to standard output
     Note: this function should print out a "#" to represent empty trees!
     Postconditions: none
     *****************************/
    void preOrderTraversal();

    /****************************
     inOrderTraversal

     Function: prints the inOder (Left, Node, Right) traversal to standard output
     Postconditions: none
     *****************************/
    void inOrderTraversal();


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    //Private functions that are called from the public functions
    bool findItem(TreeNode *t, const ItemType &x);

    ItemType findMin(TreeNode *t);

    ItemType findMax(TreeNode *t);

    void insertItem(TreeNode *&t, const ItemType &newItem);

    void inOrderTraversal(TreeNode *t) const;

    void preOrderTraversal(TreeNode *t) const;

    int countNodes(TreeNode *t) const;

    void makeEmpty(TreeNode *&t);

};

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
BST_3358<ItemType>::BST_3358() {
    root = NULL;
}

template<class ItemType>
BST_3358<ItemType>::~BST_3358() {
    makeEmpty();
}

template<class ItemType>
void BST_3358<ItemType>::makeEmpty(TreeNode *&t) {
    if (t != NULL)        //As long as t is not NULL.
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

template<class ItemType>
void BST_3358<ItemType>::makeEmpty() {
    makeEmpty(root);
}

template<class ItemType>
bool BST_3358<ItemType>::findItem(TreeNode *t, const ItemType &x) {
    if (t == NULL)        //false for empty list or item not found
    {
        return false;
    }

    if (x < t->data)                //for item less than current node
    {
        return findItem(t->left, x);
    }

    if (x > t->data)                //for item greater than current node
    {
        return findItem(t->right, x);
    }

    return true;
}

template<class ItemType>
bool BST_3358<ItemType>::findItem(const ItemType &x) {
    return findItem(root, x);
}

template<class ItemType>
ItemType BST_3358<ItemType>::findMin(TreeNode *t) {

    assert(t != NULL);            //if t is NULL fail.

    if (t->left != NULL)        //findMin on left until it's NULL then return.
    {
        return findMin(t->left);
    }

    return t->data;
}

template<class ItemType>
ItemType BST_3358<ItemType>::findMin() {
    return findMin(root);
}

template<class ItemType>
ItemType BST_3358<ItemType>::findMax(TreeNode *t) {
    assert(t != NULL);        //if t is NULL fail.

    if (t->right != NULL)    //findMax on right until it's NULL then return.
    {
        return findMax(t->right);
    }
    return t->data;

}

template<class ItemType>
ItemType BST_3358<ItemType>::findMax() {
    return findMax(root);
}

template<class ItemType>
void BST_3358<ItemType>::insertItem(TreeNode *&t, const ItemType &newItem) {
    if (t == NULL)         //if t is NULL, t gets new Node and data is inserted.
    {
        t = new TreeNode();
        t->data = newItem;
    } else if (newItem < t->data)        //for newItem less than current node.
    {
        insertItem(t->left, newItem);
    } else if (newItem > t->data)        //For newItem greater than current node.
    {
        insertItem(t->right, newItem);
    } else
        return;                        //duplicate item, do nothing
}

template<class ItemType>
void BST_3358<ItemType>::insertItem(const ItemType &newItem) {
    insertItem(root, newItem);
}

template<class ItemType>
int BST_3358<ItemType>::countNodes(TreeNode *t) const {
    if (t == NULL)    //sum up nodes as long as t is not NULL.
    {
        return 0;
    } else {
        return 1 + countNodes(t->left) + countNodes(t->right);
    }
}

template<class ItemType>
int BST_3358<ItemType>::countNodes() {
    return countNodes(root);
}

template<class ItemType>
void BST_3358<ItemType>::preOrderTraversal(TreeNode *t) const {
    cout << t->data << " ";                //Node
    if (t->left != NULL)                //left
    {
        preOrderTraversal(t->left);
    } else if (t->left == NULL) {
        cout << "#" << " ";
    }
    if (t->right != NULL)                //right
    {
        preOrderTraversal(t->right);
    } else if (t->right == NULL) {
        cout << "#" << " ";
    }
}

template<class ItemType>
void BST_3358<ItemType>::preOrderTraversal() {
    preOrderTraversal(root);
    cout << endl;
}

template<class ItemType>
void BST_3358<ItemType>::inOrderTraversal(TreeNode *t) const {
    if (t->left != NULL)                    //left
    {
        inOrderTraversal(t->left);
    }
    cout << t->data << " ";                    //Node
    if (t->right != NULL)                    //right
    {
        inOrderTraversal(t->right);
    }
}

template<class ItemType>
void BST_3358<ItemType>::inOrderTraversal() {
    inOrderTraversal(root);
    cout << endl;
}

#endif //BST_HEAP_BST_3358_H

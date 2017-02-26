//
// Created by Adam on 2/26/2017.
//

#ifndef BST_HEAP_HEAP_3358_H
#define BST_HEAP_HEAP_3358_H

/*
 *		FileName: heap_3358.h
 *  	Created on: Apr 27, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structures
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 6
 *      Description: This is a header template for a binary heap. it
 *      contains all of the necessary functions for the BST implementation.
 */

#include <cassert>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

template<class ItemType>
class Heap_3358 {
public:

    //Constructor
    Heap_3358();

    /****************************
     makeEmpty

     Function: Removes all the items from the heap.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();

    /****************************
     insertItem

     Function: Adds newItem to the heap.
     Postconditions: newItem is in the proper position for a heap.
     *****************************/
    void insertItem(const ItemType &);

    /****************************
     findMin

     Function: Finds minimum element in heap.
     Preconditions: heap has at least one node.
     Postconditions: Returns the smallest element in the heap.
     *****************************/
    ItemType findMin();

    /****************************
     deleteMin

     Function: Removes minimum element from heap.
     Preconditions: heap has at least one node.
     Postconditions: Smallest element has been removed from heap, and it's
                     still a heap.
     *****************************/
    void deleteMin();

    /****************************
     display

     Function: for diagnostic purposes, displays the tree like this
     (positions in array are shown):
     1
     2 3
     4 5 6 7
     8 9 10 11 12 13 14 15
     etc.
     *****************************/

    void display();


private:
    int size;
    ItemType array[100];

    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);

};

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Heap_3358<ItemType>::Heap_3358 ()
{
    size = 0;		//initialize size and partial initialize array.
    array[0] = 0;
}


template<class ItemType>
void Heap_3358 <ItemType>::makeEmpty()
{
    array[size] = 0;
    size--;
    makeEmpty();
}


template<class ItemType>
ItemType Heap_3358 <ItemType>::findMin()
{
    assert(size > 0);
    return array[1];
}

template<class ItemType>
void Heap_3358 <ItemType>::insertItem(const ItemType& newItem)
{
    // place newItem at end of tree, use percolate up to move to proper place
    array[size+1] = newItem;
    percolateUp(size+1);
    size++;
}

template<class ItemType>
void Heap_3358 <ItemType>::percolateUp(int loc) {

    // if array[loc] is greater than its parent: done
    // else swap array[loc] with parent, repeat on the parent
    // Make this recursive.

    if(array[loc] > array[loc/2])
    {
        return;
    }
    else
    {
        swap(array[loc], array[loc/2]);
        percolateUp(loc/2);
    }
}


template<class ItemType>
void Heap_3358 <ItemType>::deleteMin()
{
    // move last item to top, use percolate down to move it to proper place
    assert(size > 0);
    swap(array[1], array[size]);

    array[size] = 0;
    size--;
    percolateDown(1);
}

template<class ItemType>
void Heap_3358 <ItemType>::percolateDown(int loc) {

    int left = 2 * loc;  //calculate index of left child
    int right = (2 * loc) + 1; //calculate index of right child

    if (left>size)   // no children
        return;

    if (left==size) { //one child
        // compare array[loc] to array[left], swap if needed
        if(array[left] < array[loc])
        {
            swap(array[left], array[loc]);
            return;
        }
        else
            return;
        //done
    }

    //two children:

    // if both children are greater than the parent: done
    // otherwise, swap the smaller of the two children with the
    // parent, repeat

    if((array[left] > array[loc]) && (array[right] > array[loc]))
    {
        return;
    }
    else if((array[left] < array[right]) && (array[left] < array[loc]))
    {
        swap(array[left], array[loc]);
        percolateDown(left);
    }
    else if((array[right] < array[left]) && (array[right] < array[loc]))
    {
        swap(array[right], array[loc]);
        percolateDown(right);
    }
}


// Provided:
template<class ItemType>
void Heap_3358 <ItemType>::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}

#endif //BST_HEAP_HEAP_3358_H

/*
 * bst_heap_driver.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: Adam
 */


#include "heap_3358.h"
#include "bst_3358.h"
#include<iostream>

using namespace std;

int main() {
    BST_3358<int> bst;
    int max;
    int minimum;
    int count;
    bool find1;
    bool find2;

    cout << "This is BST." << endl;

    bst.insertItem(7);
    bst.insertItem(5);
    bst.insertItem(12);
    bst.insertItem(20);
    bst.insertItem(59);
    bst.insertItem(99);
    bst.insertItem(22);
    bst.insertItem(100);

    for (int j = 1; j < 21; j++) {
        bst.insertItem(j);
    }
    bst.preOrderTraversal();

    max = bst.findMax();
    minimum = bst.findMin();

    cout << "max is: " << max << endl;
    cout << "min is: " << minimum << endl;

    bst.inOrderTraversal();

    count = bst.countNodes();
    cout << "count is: " << count << endl;

    find1 = bst.findItem(7);
    if (find1) {
        cout << "Found." << endl;
    } else {
        cout << "Not found." << endl;
    }

    find2 = bst.findItem(98);
    if (find2) {
        cout << "Found." << endl;
    } else {
        cout << "Not found." << endl;
    }

    bst.makeEmpty();
    bst.insertItem(54);
    bst.inOrderTraversal();
    cout << endl;
    cout << endl;

    cout << "This is the heap." << endl;

    Heap_3358<int> heap;
    int min;

    heap.insertItem(7);
    heap.insertItem(12);
    heap.insertItem(5);
    heap.insertItem(15);
    heap.insertItem(22);
    heap.insertItem(109);
    heap.insertItem(8);

    for (int i = 1; i < 20; i++) {
        heap.insertItem(i);
    }

    heap.display();

    min = heap.findMin();

    cout << endl;
    cout << "min is: " << min << endl;

    heap.deleteMin();

    heap.display();

    heap.makeEmpty();
    cout << "made empty" << endl;
//	heap.display();


    return 0;
}

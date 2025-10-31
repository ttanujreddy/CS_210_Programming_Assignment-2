//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        int childNode = weightArr[data[pos]];

        // while pos is not the root
        while (pos > 0) {
            int parentIndex = (pos - 1) / 2;

            int parentNode = weightArr[data[parentIndex]];

            // Compare child node and parent node
            if (childNode < parentNode) {
                // if the child node is less than the parent node, then swap the nodes
                int temp = data[parentIndex];
                data[parentIndex] = data[pos];
                data[pos] = temp;

                // the current parent index becomes the new pos (i.e. pos of child after the swap = parentIndex)
                pos = parentIndex;
            }
            else {
                // if the parent node is less than the child node, then no need for upheap
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif
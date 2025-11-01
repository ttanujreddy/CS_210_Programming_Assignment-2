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
        // insert index at the end of heap
        data[size] = idx;

        // restore order using upheap
        upheap(size, weightArr);

        // increment size by 1 to ensure that the next push() and pop() operations perform correctly
        size++;
    }

    int pop(int weightArr[]) {
        // if heap is empty, then return -1
        if (size == 0) return -1;

        int smallestIndex = data[0];

        // replace root with last element
        data[0] = data[size - 1];

        data[size - 1] = -1;

        // decrement size by 1 to ensure that the next push() and pop() operations perform correctly
        size--;

        // ensure node with the least value is at the root using downheap
        downheap(0, weightArr);

        return smallestIndex;
    }

    void upheap(int pos, int weightArr[]) {
        // child node is not updated every loop because its value is constant
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
        // parent node is not updated every loop because its value is constant
        int parentNode = weightArr[data[pos]];

        int leftChildIndex = (2 * pos) + 1;
        int rightChildIndex = (2 * pos) + 2;

        // while pos is not the last node of the heap and parent node has at least a left child
        while (pos < size && leftChildIndex < size) {
            int leftChildNode = weightArr[data[leftChildIndex]];

            int smallerChildIndex;
            int smallerChildNode;

            // if right child index is not out of bounds
            if (rightChildIndex < size) {
                int rightChildNode = weightArr[data[rightChildIndex]];

                // compare the two children nodes to see which is the smallest
                smallerChildIndex = leftChildNode < rightChildNode ? leftChildIndex : rightChildIndex;
                smallerChildNode = leftChildNode < rightChildNode ? leftChildNode : rightChildNode;
            }
            else {
                // if right child index is out of bounds, then the only child is the left child
                smallerChildIndex = leftChildIndex;
                smallerChildNode = leftChildNode;
            }

            int temp = 0;

            // compare parent node to its smallest child
            if (parentNode > smallerChildNode) {
                // if parent node is greater than its smallest child, then swap
                temp = data[pos];
                data[pos] = data[smallerChildIndex];
                data[smallerChildIndex] = temp;

                // the smallest child's index becomes the new pos (i.e. pos of parent after the swap = smallerChildIndex)
                pos = smallerChildIndex;

                // recompute left and right child indexes for the next iteration of the loop
                leftChildIndex = (2 * pos) + 1;
                rightChildIndex = (2 * pos) + 2;

                continue;
            }

            // if the parent node is less than its smallest node, then end the loop
            break;
        }
    }
};

#endif
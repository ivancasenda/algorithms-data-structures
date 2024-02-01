# C++ Algorithms and Data Structures

This repository contains C++ implementations of various algorithms and data structures. It's intended to be a helpful resource for learning, practicing, and understanding common algorithms and data structures used in computer science.

## Table of Contents

- [Algorithms](#algorithms)
- [Data Structures](#data-structures)
- [Usage](#usage)

## Algorithms

- Merge Sort

  Merge sort is a divide-and-conquer sorting algorithm. It recursively divides an array into halves until each sub-array has only one element. The algorithm then merges these smaller arrays in a sorted manner until the entire array is sorted. It guarantees a stable O(n log n) time complexity,

- Quick Sort

  QuickSort is a sorting algorithm that follows the divide-and-conquer strategy. It works by selecting a "pivot" element from the array and partitioning the other elements into two sub-arrays, those less than the pivot and those greater. The process is then applied recursively to the sub-arrays. QuickSort is efficient on average and has an O(n log n) time complexity.

- Radix Sort

  Radix Sort is a non-comparative sorting algorithm that works by distributing elements into buckets based on their individual digits. It processes the digits from the least significant to the most significant, or vice versa. This process is repeated for each digit, creating a sorted sequence. Radix Sort can be applied to numbers represented in different bases. It has a linear time complexity, O(nk), where n is the number of elements and k is the number of digits in the longest number.

- Counting Sort

  Counting Sort is a non-comparative sorting algorithm that works well when the range of input values is known. It creates an auxiliary array to store the count of each unique element in the input. The algorithm then uses this count information to determine the position of each element in the sorted output. Counting Sort has a linear time complexity of O(n + k), where n is the number of elements and k is the range of input values

- Document Distance

  The Document Distance algorithm calculates the similarity between two documents by analyzing the angle between their vector representations in a multidimensional space. It involves representing each document as a vector where each dimension corresponds to a unique term in the corpus. The algorithm then computes the cosine of the angle between these vectors, with a lower cosine indicating greater similarity.

- Breadth-First Search (BFS)

  Breadth-First Search (BFS) is a graph traversal algorithm used to explore all the vertices of a graph in a breadthward motion. It starts from a selected source vertex and systematically visits all its neighbors before moving on to the next level of neighbors. BFS uses a queue data structure to keep track of the vertices to be visited. It ensures that vertices are visited in the order of their distance from the source, making it suitable for finding the shortest path in unweighted graphs.

- Depth-First Search (DFS)

  Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It starts from a selected source vertex, explores as deeply as possible along one branch, and then backtracks to explore other branches. DFS can be implemented using a stack or recursion to keep track of vertices. It is not necessarily optimal for finding the shortest path but is effective for various applications, such as topological sorting, cycle detection, and maze solving.

## Data Structures

- Binary Search Trees (BST)

  A Binary Search Tree (BST) is a binary tree data structure where each node has at most two child nodes, typically referred to as the left and right children. The key property of a BST is that the value of each node in the left subtree is less than or equal to the node's value, and the value of each node in the right subtree is greater than the node's value. This ordering allows for efficient searching, insertion, and deletion operations.

- AVL Trees

  An AVL tree is a self-balancing binary search tree. In an AVL tree, the balance factor of every node, representing the height difference between its left and right subtrees, is restricted to be at most 1. This ensures that the tree remains balanced, preventing it from becoming skewed and maintaining a height that is logarithmic in the number of nodes. To maintain balance during insertion and deletion, AVL trees use rotations, which are operations that restructure the tree while preserving the ordering property. The balanced nature of AVL trees ensures efficient O(log n) time complexity for search, insertion, and deletion operations.

- Randomized Search Trees (RST)

  Randomized Search Trees (RST) are binary search trees that incorporate randomization during their construction and maintenance. In an RST, the choice of the root and the order in which elements are inserted is randomized, leading to a more balanced structure on average. Randomization helps prevent worst-case scenarios, providing probabilistic guarantees on the tree's height. This randomness also helps achieve average-case time complexities of O(log n) for search, insertion, and deletion operations. RSTs are used to balance the performance of binary search trees in scenarios where the input sequence might be adversarial or lead to skewed trees.

- Min-Heap

  A Min Heap is a binary heap data structure in which the value of each node is less than or equal to the values of its children. The smallest element (minimum) is always at the root. Min Heaps are complete binary trees, often implemented as arrays, and are used to efficiently extract the minimum element. Insertion and extraction of the minimum element have O(log n) time complexity, making Min Heaps suitable for priority queue

- Linked List

  A linked list is a linear data structure where elements, called nodes, are connected using pointers or references. Each node contains data and a reference (or link) to the next node in the sequence. The last node typically points to null, indicating the end of the list. Linked lists can be singly linked (each node points to the next) or doubly linked (each node has references to both the next and previous nodes). They allow dynamic memory allocation and efficient insertion or removal of elements at any position but have slower random access compared to arrays.

- Skip List

  A Skip List is a data structure that allows for efficient search, insertion, and deletion operations with expected O(log n) time complexity, similar to balanced trees. It consists of multiple levels of linked lists, where each level represents a subset of the elements. The bottom level contains all the elements in sorted order. Nodes at higher levels act as express lanes, allowing for faster traversal. The structure incorporates randomization to determine the level of each node, providing a balanced distribution. Skip Lists are a simple alternative to balanced trees, offering logarithmic performance without the need for rebalancing operations.

- Circular Array

  A circular array is a data structure that represents an array where the last element is followed by the first element, creating a circular sequence. It can be implemented using a regular array with the index wrapping around to the beginning when it reaches the end. Circular arrays are useful in scenarios where elements need to be accessed in a circular manner, such as implementing circular buffers or representing cyclical patterns. They provide constant-time access to elements and are particularly efficient for scenarios involving rotations or circular iterations.

## Usage

Each algorithm and data structure implementation is contained in cpp and header file.

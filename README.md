
# Data Structures: Linked Lists, BST, and Graphs

## 📑 Table of Contents
- [1. Linked Lists](#1-linked-lists)
  - [Structure of a Node](#structure-of-a-node-in-linked-list)
  - [Types of Linked Lists](#types-of-linked-lists)
  - [Advantages](#advantages-of-linked-list)
  - [Disadvantages](#disadvantages-of-linked-list)
- [2. Binary Search Tree (BST)](#2-binary-search-tree-bst)
  - [Structure of a Node](#structure-of-a-node-in-bst)
  - [Example BST](#example-bst)
  - [Operations](#operations-in-bst)
  - [Tree Traversals](#tree-traversals)
- [3. Graphs](#3-graphs)
  - [Terminology](#terminology-in-graphs)
  - [Graph Representations](#graph-representations)
  - [Example](#example-graph)
  - [Applications](#applications-of-graphs)

---

------------------------------------------------------------
1. Linked Lists
------------------------------------------------------------

A Linked List is a linear data structure where elements (called nodes) are stored dynamically and connected using pointers.

Structure of a Node (C code):
    struct Node {
        int data;
        struct Node* next;
    };
```
Types of Linked Lists:
1. Singly Linked List  
   Each node points to the next node.  
   [10 | next] -> [20 | next] -> [30 | next] -> NULL

2. Doubly Linked List  
   Each node has two pointers: one to the next node and one to the previous node.  
   NULL <- [10 | prev,next] <-> [20 | prev,next] <-> [30 | prev,next] -> NULL

3. Circular Linked List  
   The last node points back to the first node.  
   [10] -> [20] -> [30] -+
     ^-------------------+
```
Advantages:
- Dynamic size (no fixed capacity).
- Efficient insertions/deletions if pointer is known.

Disadvantages:
- Sequential access (O(n) search).
- Extra memory required for pointers.


------------------------------------------------------------
2. Binary Search Tree (BST)
------------------------------------------------------------

A Binary Search Tree is a hierarchical structure where each node has at most two children, and values are arranged so that:
- Left child < Parent
- Right child > Parent

Structure of a Node (C code):
    struct Node {
        int data;
        struct Node* left;
        struct Node* right;
    };

```
Example BST:
            50
           /  \
         30    70
        / \   / \
      20  40 60  80

```
Operations:
- Search → O(log n) average, O(n) worst case.
- Insert → Place value according to BST rules.
- Delete → Three cases:
    1. Node is a leaf → remove directly.
    2. Node has one child → replace with child.
    3. Node has two children → replace with inorder successor or predecessor.

Tree Traversals:
- Inorder (L → Root → R) → Produces sorted order.
- Preorder (Root → L → R).
- Postorder (L → R → Root).
- Level Order (Breadth-First Search).


------------------------------------------------------------
3. Graphs
------------------------------------------------------------

A Graph is a collection of nodes (vertices) connected by edges.

Terminology:
- Vertex (V): a node in the graph.
- Edge (E): a connection between two vertices.
- Directed Graph: edges have direction (A → B).
- Undirected Graph: edges have no direction (A -- B).

Graph Representations:
1. Adjacency Matrix  
   A 2D array where matrix[i][j] = 1 if there is an edge from i to j.

2. Adjacency List  
   Each vertex stores a list of adjacent vertices.

```
Example (Undirected Graph):
   A -- B
   |    |
   C -- D

```
Applications of Graphs:
- Social networks (users as vertices, friendships as edges).
- Maps and navigation (cities as vertices, roads as edges).
- Computer networks, dependency resolution, pathfinding.

------------------------------------------------------------
End of Document
------------------------------------------------------------

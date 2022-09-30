#include <vector>
#include <list>
#include "planet.h"
#pragma once 

class Node{
    public:
    Node* topLeft;
    Node* topRight;
    Node* bottomRight;
    Node* bottomLeft;
    int minX, maxX, minY, maxY;
    Node* parent;
    
    bool isLeaf;
    double mass;
    std::list<int> planets;
    Node(int minX, int maxX, int minY, int maxY, Node* parent);
};

class quadTree{
    public:
    Node* root;
    std::vector<Planet*> &source;
    int threshold;
    int treeMaxX,treeMinX,treeMaxY,treeMinY;
    quadTree();
    quadTree(int maxX, int minX, int maxY, int minY, std::vector<Planet*> *source_vec);
    void makeTree(int threshold);
    void cleanup();
    void delete_elem();
    
    void move(int index);

    private:
    void insert(Node* node, int index);
    void divide_node(Node* node);
};
#include "quadtree.h"

void quadTree::divide_node(Node* node){

    if(node->isLeaf){
        int middleX = (node->maxX + node->minX)/2; // inclusive for left
        int middleY = (node->maxY + node->minY)/2; // inclusive for top
        node->topLeft = new Node(node->minX,middleX,node->minY,middleY, node);
        node->topRight = new Node(middleX+1,node->maxX,node->minY,middleY,node);
        node->bottomRight = new Node(middleX+1,node->maxX,middleY+1,node->maxY, node);
        node->bottomLeft = new Node(node->minX, middleX, middleY+1, node->maxY, node);
        node->isLeaf = false;
        for(auto elem : node->planets){
            if(source[elem]->x <= middleX && source[elem]->y <= middleY){
                node->topLeft->planets.push_back(elem);
                continue;
            }
            if(source[elem]->x > middleX && source[elem]->y <= middleY){
                node->topRight->planets.push_back(elem);
                continue;
            }
            if(source[elem]->x > middleX && source[elem]->y > middleY){
                node->bottomRight->planets.push_back(elem);
                continue;
            }
            if(source[elem]->x <= middleX && source[elem]->y > middleY){
                node->bottomLeft->planets.push_back(elem);
                continue;
            }
        }
        node->planets.clear();
        if(node->bottomLeft->planets.size() > threshold) divide_node(node->bottomLeft);
        if(node->bottomRight->planets.size() > threshold) divide_node(node->bottomRight);
        if(node->topLeft->planets.size() > threshold) divide_node(node->topLeft);
        if(node->topRight->planets.size() > threshold) divide_node(node->topRight);
    }
    else{
        return;
    }
}

void quadTree::insert(Node* node, int index){
    if(node->isLeaf && node->planets.size() < threshold){
        node->planets.emplace_back(index);
        return;
    }
    if(node->planets.size() >= threshold){
        divide_node(node);
    }
    int middleX = (node->maxX + node->minX)/2; // inclusive for left
    int middleY = (node->maxY + node->minY)/2; // inclusive for top
    if(source[index]->x <= middleX && source[index]->y <= middleY){
        insert(node->topLeft, index);
    }
    if(source[index]->x > middleX && source[index]->y <= middleY){
        insert(node->topRight, index);
    }
    if(source[index]->x > middleX && source[index]->y > middleY){
        insert(node->bottomRight, index);
    }
    if(source[index]->x <= middleX && source[index]->y > middleY){
        insert(node->bottomLeft, index);
    }

    
}

void quadTree::makeTree(int threshold){

    this->threshold = threshold;
    for(int i = 0 ; i < source.size(); i++){
        insert(root, i);
    }
}

quadTree::quadTree(int maxX, int minX, int maxY, int minY, std::vector<Planet*> *source_vec)
    : treeMaxX(maxX)
    , treeMinX(minX)
    , treeMaxY(maxY)
    , treeMinY(minY)
    , source(*source_vec)
    {
        root = new Node(minX,maxX,minY,maxY,NULL);
    }

Node::Node(int minX, int maxX, int minY, int maxY, Node* parent)
    : maxX(maxX)
    , minX(minX)
    , maxY(maxY)
    , minY(minY)
    , parent(parent)
    , topLeft(NULL)
    , topRight(NULL)
    , bottomLeft(NULL)
    , bottomRight(NULL)
    , isLeaf(true)
{

}
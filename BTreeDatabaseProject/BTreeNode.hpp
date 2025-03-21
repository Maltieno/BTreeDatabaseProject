#ifndef BTREE_NODE_HPP
#define BTREE_NODE_HPP

#include <iostream>
#include <vector>

class BTreeNode
{
public:
    int minKeys;      //Minimum amount of keys Per Node
    int curNumKeys;   //Current Number of Keys In the Node
    bool leaf;        //True only if the node is leaf of tree

    //!Using Vectors, we're going to dynamically allocate memory for some Vars.
    std::vector<int> keys;                     //Vector to store our Keys
    std::vector<BTreeNode*> childNodeLocation; //Vector to Store our Pointers to ChildNodeLocations.
    //!End Vector Use

    //!Constructor Tiem
    BTreeNode(int tempMinKeys, bool Templeaf)
    {
        minKeys = tempMinKeys; //When Creating new Nodes, specify minKeys & if it is a leaf.
        leaf = Templeaf;
        curNumKeys = 0;

        //!Reserve Space In Vectors for Max Possible Amounts.
        keys.reserve(2 * minKeys - 1);          //Max Amount of Keys is 1 Less than the Max Amount Of childNodes
        childNodeLocation.reserve(2 * minKeys); //Max Amount of Child Nodes is Double that of The minKeys
    }
};

#endif
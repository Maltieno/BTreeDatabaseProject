#ifndef BTREE_NODE_HPP
#define BTREE_NODE_HPP

#include <iostream>
#include <vector>

#include "BTreeKeys.hpp"
#include "json.hpp"

class BTreeNode
{
public:
    int minKeys;      //Minimum amount of keys Per Node
    int curNumKeys;   //Current Number of Keys In the Node
    bool leaf;        //True only if the node is leaf of tree

    //!Using Vectors, we're going to dynamically allocate memory for some Vars.
    std::vector<BTreeKey> keys;                //Vector to store our Keys
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

    //!End Of Constructor

    //! Insertion Function
    void Insert(BTreeKey newKey)
    {

        int i = curNumKeys - 1; //Start at the end of the keys

        if (leaf) //If this is a leaf node
        {
            keys.push_back(newKey); //Push the new key onto the end of the keys
            while (i >= 0 && keys[i].keyID > newKey.keyID) //whilst the keyID is greater than the new keyID
            {
                keys[i + 1] = keys[i]; //Shift the keys to the right
                i--;                   //Shift left to check next if lower id int than next key
            }

            //Insert the new key at the correct position
            keys[i + 1] = newKey; //Insert the new key at the correct position

            curNumKeys++;         //Increment the number of keys in the node
        }
        else //If this is not a leaf node
        {
            while (i >= 0 && keys[i].keyID > newKey.keyID) //whilst the keyID is greater than the new keyID
            {
                i--; //Shift left to check next if lower id int than next key
            }
            if (childNodeLocation[i + 1]->curNumKeys == 2 * minKeys - 1) //If the child node is full, working with pointers, use ->
            {
                splitChild(i + 1, childNodeLocation[i + 1]); //Split the child node
                if (keys[i + 1].keyID < newKey.keyID) //If the new key ID is greater than the next key ID
                {
                    i++; //Shift right to check next if higher id int than next key
                }
            }
            childNodeLocation[i + 1]->Insert(newKey); //Insert the new key into the child node
        }
	}
	

	//!End Insertion Function

	//! Split Function
    void splitChild(int i, BTreeNode* fullNode)
    {

    } 
 
};
#endif


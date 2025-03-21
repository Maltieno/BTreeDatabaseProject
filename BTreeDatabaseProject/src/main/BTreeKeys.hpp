#ifndef BTREE_Key_HPP
#define BTREE_Key_HPP

#include <iostream>

//! This Header Defines individual keys inside our B-Tree
class BTreeKey
{
public:
	int keyID; //ID To Identify and Locate/Create/Deallocate

	//! Below is the DATA Stored in the key, this can be changed and modified to suit different Programs.
	//! All Data stored here should NOT Be used in making of Lib BTREE PROJECT
	int data; //Example of Basic Int Data Var, for storing one Int.

	//! End Data Storage.
	
	//! Constructor
	BTreeKey(int tempKeyID) //Parameters Must be Modified to fit Program.
	{
		keyID = tempKeyID; //ID to be Specified by External Program's Organizational Methods

	    //All Additional Data's must be init's on case Basis.
		data = 0; //Example Var Data, type Int, Init to 0
	}

};
#endif
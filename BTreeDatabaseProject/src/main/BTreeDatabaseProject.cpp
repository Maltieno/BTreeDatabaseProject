//todo Read Input from a console input.
//todo Setup Parameters for the B-Tree Database, Such as amount of Keys per Node
//todo Setup Node to dynamically store an amount of keys
//todo Add Pushing Key onto tree
//todo Add Deleting Key From tree
//todo Add Searching for keys
//todo Add Data attached to each key
//

//leaving it off here, Have to finish essay, Working on Config reading

#include <iostream>
#include <vector>
#include <fstream>

#include "BTreeKeys.hpp"
#include "BTreeNode.hpp"

#include "json.hpp"

int main()
{
    std::string testing;

    std::cin >> testing;
    std::cout << testing << "\n";


    //!Read Config for BTree, set Vars from config
    std::ifstream cfgFile("C:/Users/Jay/source/repos/Maltieno/BTreeDatabaseProject/BTreeDatabaseProject/cfg/cfg.json"); // Read Our CFG file
    if (!cfgFile) //if file is missing, throw an error
    {
        std::cerr << "Error: Could not open " << "cfg.json" << std::endl;
        return 1;  // Exit early if the file is missing
    }

    json config;                       //Create a Json var
    cfgFile >> config;                 //parse info from config file into our new var

    //!Set and declare our Config Vars
    int minKeys = config["BTree"]["minKeys"];
    bool allowDuplicates = config["BTree"]["allowDuplicates"];
    std::string storagePath = config["BTree"]["storagePath"];
    //!End Config Vars
    
    //! TESTING TESTING TESTING, Print our Config Values
    std::cout << "Min Keys: " << minKeys << "\n";
    std::cout << "Allow Duplicates: " << allowDuplicates << "\n";
    std::cout << "Storage Path: " << storagePath << "\n";
    //!END TESTING
    
    //! End Config for BTree
    
    return 0;
}



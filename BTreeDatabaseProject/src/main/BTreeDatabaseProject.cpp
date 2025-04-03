//todo Add Pushing Key onto tree
//todo Add Deleting Key From tree
//todo Add Searching for keys
//todo Add Data attached to each key
//

//leaving it off here, Have to finish essay, Working on Config reading

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "BTreeKeys.hpp"
#include "BTreeNode.hpp"

#include "json.hpp"

int main()
{
    //!Read Config for BTree, set Vars from config
    std::string projectDir = std::filesystem::current_path().string(); //Get Project Directory
	std::string cfgFileDir = projectDir + "/cfg/cfg.json";             //Get Config File Directory
    std::ifstream cfgFile(cfgFileDir);                                 // Read Our CFG file

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



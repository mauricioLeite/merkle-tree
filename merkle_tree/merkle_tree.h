#pragma once

#include <vector>
#include <string>
#include "merkle_node.h"

/**
 * Represents all nodes at a level of Merkle Tree
*/
typedef std::vector<MerkleNode *> TreeLevel;

class MerkleTree {
public:
    void FromHashList(std::vector<std::string> leaves);

    void PrintTree();
    void PrintSubTree(MerkleNode *node, uint level);

private:
    std::vector<MerkleNode *> leaves_;
    
    MerkleNode *merkle_root_;

    void GenerateTreeLevels(TreeLevel level);
    
};


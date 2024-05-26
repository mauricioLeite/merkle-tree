#pragma once

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

#include "merkle_node.h"

/**
 * Represents all nodes at a level of Merkle Tree
*/
typedef std::vector<MerkleNode *> TreeLevel;

class MerkleTree {
public:
    void FromHashList(std::vector<std::string> leaves);

    std::vector<std::string> GenerateMerkleProof(std::string hash);

    void PrintTree();
    void PrintSubTree(MerkleNode *node, uint level);
    void PrintByLevels();

private:
    std::vector<MerkleNode *> leaves_;
    
    MerkleNode *merkle_root_;
    std::vector<TreeLevel> tree_levels_;

    void GenerateTreeLevels(TreeLevel level);
    int HashIndexInLevel(std::string hash, TreeLevel level);
    
};


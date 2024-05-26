#pragma once

#include <string>
#include <cassert>

#include "sha256.h"

class MerkleNode {
public:
    
    MerkleNode();
    MerkleNode(const std::string hash);

    void SetChildren(MerkleNode *left, MerkleNode *right);
    MerkleNode *Left();
    MerkleNode *Right();

    void ComputeNodeHash();
    std::string NodeHash();

private:
    MerkleNode *left_, *right_;
    std::string hash_;
};
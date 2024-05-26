#include "merkle_tree.h"

void MerkleTree::FromHashList(std::vector<std::string> leaves) {
    for(std::string leaf : leaves) {
        MerkleNode *node = new MerkleNode(leaf);
        leaves_.push_back(node);
    }

    GenerateTreeLevels(leaves_);
}

void MerkleTree::GenerateTreeLevels(TreeLevel level){
    if(level.size() == 1) {
        merkle_root_ = level.front();
        return;
    } 

    while(level.size() % 2 != 0) level.push_back(level.back());

    TreeLevel generated_level = std::vector<MerkleNode *>();
    for(int i = 0; i < level.size(); i += 2) {
        MerkleNode *node = new MerkleNode();
        node->SetChildren(level[i], level[i+1]);
        node->ComputeNodeHash();
        generated_level.push_back(node);
    }

    GenerateTreeLevels(generated_level);
}


void MerkleTree::PrintTree() {
    PrintSubTree(merkle_root_, 0);
}

void MerkleTree::PrintSubTree(MerkleNode *node, uint level) {
    if(node == nullptr) return;

    std:: string buff;
    buff = std::string(level*2, ' ');
    buff += level + '0';
    buff += " - ";

    std::cout << buff << node->NodeHash() << std::endl;
    PrintSubTree(node->Left(), level + 1);
    PrintSubTree(node->Right(), level + 1);
}


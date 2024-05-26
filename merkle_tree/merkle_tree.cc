#include "merkle_tree.h"

void MerkleTree::FromHashList(std::vector<std::string> leaves) {
    for(std::string leaf : leaves) {
        MerkleNode *node = new MerkleNode(leaf);
        leaves_.push_back(node);
    }

    GenerateTreeLevels(leaves_);
}

void MerkleTree::GenerateTreeLevels(TreeLevel level){
    tree_levels_.push_back(level);
    if(level.size() == 1) {
        merkle_root_ = level.front();
        std::reverse(tree_levels_.begin(), tree_levels_.end());
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

std::vector<std::string> MerkleTree::GenerateMerkleProof(std::string hash) {
    assert(hash != "");
    assert(hash.length() != 0);

    int depth = tree_levels_.size() - 1;
    std::vector<std::string> proof({hash});

    for(int level = depth; level > 0; level--) {
        int index = HashIndexInLevel(hash, tree_levels_[level]);

        bool left_node = (index % 2 == 0);
        int pair_index =  left_node ? index + 1 : index - 1;

        MerkleNode *base, *pair;
        base = tree_levels_[level][index];
        pair = tree_levels_[level][pair_index];
        proof.push_back(pair->NodeHash());

        if(!left_node) std::swap(base, pair);

        MerkleNode *node = new MerkleNode();
        node->SetChildren(base, pair);
        node->ComputeNodeHash();
        hash = node->NodeHash();
        delete node;
    }
    return proof;
}

int MerkleTree::HashIndexInLevel(std::string hash, TreeLevel level) {
    MerkleNode* target = nullptr;
    for(MerkleNode* node : level) {
        if(node->NodeHash() == hash) target = node;
    }
    assert(target != nullptr);

    auto it = std::find(level.begin(), level.end(), target);
    assert(it != level.end());

    return std::distance(level.begin(), it);
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

void MerkleTree::PrintByLevels() {
    for(int i = 0 ; i < tree_levels_.size(); i++) {
        std:: string buff;
        buff = "level: " + std::to_string(i) + "\n";
        for(MerkleNode* node: tree_levels_[i]) {
            buff += node->NodeHash() + "\n";
        } 
        std::cout << buff << std::endl;
    }
}

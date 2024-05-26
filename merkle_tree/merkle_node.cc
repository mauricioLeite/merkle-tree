#include "merkle_node.h"

MerkleNode::MerkleNode() {
    left_ = right_ = nullptr;
}

MerkleNode::MerkleNode(const std::string reference) {
    left_ = right_ = nullptr;
    hash_ = reference;
}

void MerkleNode::SetChildren(MerkleNode* l, MerkleNode* r){
    left_ = l;
    right_ = r;
}

MerkleNode *MerkleNode::Left() {
    return left_;
}

MerkleNode *MerkleNode::Right() {
    return right_;
}

void MerkleNode::ComputeNodeHash() {
    std::string aux = left_->NodeHash() + right_->NodeHash();
    hash_ = sha256(aux);
}

std::string MerkleNode::NodeHash() {
    assert(hash_ != "");
    return hash_;
}
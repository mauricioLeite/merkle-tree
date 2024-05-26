#include <bits/stdc++.h>

#include "merkle_tree/merkle_tree.h"

using namespace std;

int main() {
    vector<string> hash_list{
        "17c1532ca6cff8f6a3a8200028af6c2580bf37f39e10cb0966e8a573e3b24a1f", //professor
        "5fc90ab335783816990ffd960cbad0afd64510a53f895b4d02b9f8b279c0ed08", //usa
        "a75d067fa44bca815126dbf606a73907c9e68f1cd892d413424edfa84a0d4058", //IA
        "a1453f380fa9f1a08e84d4703e9c168fda1fb9a36976c41a03c8af842aa04ce5", //para
        "a9548df8134a9ffbd22aea3ec97488969f455113be568351ea6a8db8bfe6b663", //jogar
        "21209597f685c8bef83dfa0b7cb389453074695a4f0ed6d6b6bca574a2d5d77f" //dados
    };

    MerkleTree tree = MerkleTree();
    tree.FromHashList(hash_list);
    tree.PrintTree();

    exit(EXIT_SUCCESS);
}

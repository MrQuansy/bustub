#include "primer/p0_trie.h"
using bustub::TrieNode;
// This is a placeholder file for clang-tidy check.
//
// With this file, we can fire run_clang_tidy.py to check `p0_trie.h`,
// as it will filter out all header files and won't check header-only code.
//
// This file is not part of the submission. All of the modifications should
// be done in `src/include/primer/p0_trie.h`.

std::unique_ptr<TrieNode> * TrieNode::InsertChildNode(char key_char, std::unique_ptr<TrieNode> &&child) {
  if(HasChild(key_char) || key_char != child->key_char_){
    return nullptr;
  }
  children_[key_char] = std::forward<std::unique_ptr<TrieNode>>(child);
  return &children_[key_char];
}

std::unique_ptr<TrieNode> * TrieNode::GetChildNode(char key_char){
  if(!HasChild(key_char)){
    return nullptr;
  }
  return &children_[key_char];
}

void TrieNode::RemoveChildNode(char key_char){
  auto node = children_.find(key_char);
  if(node != children_.end()){
    children_.erase(node);
  }
}

//
//bool Trie::Remove(const std::string &key) {
//  return true;
//}
//
//template <typename T>
//T Trie::GetValue(const std::string &key, bool *success) {
//  *success = false;
//  return {};
//}


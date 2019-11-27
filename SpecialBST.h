#include <iostream>

using namespace std;

// Special BST class for Student and Faculty trees that need to be serialized
template <class T>
class SpecialBST : public BST<T>{
  public:
    SpecialBST(); // constructor

    // runs serialize for each node in the tree
    void serializeTree(ostream& o);
    void recSerialize(TreeNode<T>* node, ostream& o);
};

template <class T>
SpecialBST<T>::SpecialBST() : BST<T>(){}

// Starts recursive serialize at the root of tree
template <class T>
void SpecialBST<T>::serializeTree(ostream& o){
  recSerialize(this->getRoot(), o);
  o << "done" << endl; // adds marker at the end so deserializer knows when to stop input
  //silly JT with his couts 
  cout << "tree HAS BEEN EPICLY serialized" << endl;
}

template <class T>
void SpecialBST<T>::recSerialize(TreeNode<T>* node, ostream& o){
  if (node == NULL){
    return;
  }
  node->getObject()->serialize(o); // Gets the object of the node (student or faculty) and then serializes the data to the file via ostream& o
  recSerialize(node->left, o);
  recSerialize(node->right, o);
}

#include <iostream>
#include "TreeNode.h"
#include "Person.h"

using namespace std;

template <class T>
class BST{
  private:
    TreeNode<T> *root;
  public:
    BST();
    ~BST();

    T find(int num);
    bool search(T elem);
    void insert(T elem);
    bool deleteNode(T elem);
    void printTree();

    //getter
    TreeNode<T>* getRoot();
    // helper functions
    TreeNode<T>* getSuccessor(TreeNode<T> *d);
    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();
    //T recPrint(TreeNode<T> *node); // recursive print
    void recDelete(TreeNode<T> *node);
    void recPrintFaculty(TreeNode<T> *node);
    void recPrintStudent(TreeNode<T> *node);
};

template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){
  recDelete(root);
}

template <class T>
void BST<T>::recPrintFaculty(TreeNode<T> *node){
  if (node == NULL){
    return;
  }
  else
  {
    recPrintFaculty(node->left);
    node->obj->printFaculty();
    recPrintFaculty(node->right);
  }
}

template <class T>
void BST<T>::recPrintStudent(TreeNode<T> *node){
  if (node == NULL){
    return;
  }
  else
  {
    recPrintStudent(node->left);
    node->obj->printStudent();
    recPrintStudent(node->right);
  }
}

template <class T>
TreeNode<T>* BST<T>::getRoot()
{
  return root;
}

template <class T>
void BST<T>::recDelete(TreeNode<T> *node){
  if (node){
    recDelete(node->left);
    recDelete(node->right);
    delete node;
  }
}

// template <class T>
// void BST<T>::printTree(){
//   cout << "Printing tree where root = " << root << endl;
//   recPrint(root);
// }

template <class T>
TreeNode<T>* BST<T>::getMax(){

  TreeNode<T> *curr = root;

  if (root == NULL){
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right; // keep going down to the right
  }

  return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr = root;

  if (root == NULL){
    return NULL;
  }
  while(curr->left != NULL){
    curr = curr->left; // keep going down to the left
  }

  return curr;
}

template <class T>
void BST<T>::insert(T elem){
  cout << "inserting " << *elem << endl;
  // check if value exists in tree already before proceding
  // every key is unique, so if it is already in the tree, we cannot insert

  TreeNode<T> *node = new TreeNode<T>(elem, elem->getId());
  cout << "new node= " << node->getKey() << endl;
//cout << "new node= " << **node->key << endl; // Bro this changes after the first cout like how the heck
  // int value = node->key; do i need this

  if (root == NULL){ // empty tree
    root = node;
    cout << "first node entered as root" << endl;
    cout << "root= "<< *node->getObject() << endl; //not printing correct value
  }
  else{
    // tree is not empty
    // let's find the insertion point
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;
    cout << "current/root= "<< *root->getObject() << endl; //not printing correct value

    int deez = 0;
    int nuts = 0;
    // traverse tree
    while(deez == nuts){
      parent = current;
      cout << "about to compare..." << endl;
      cout << "Elem ID: " << elem->getId() << endl;
      cout << "Curr ID: " << current->getKey() << endl;
      // Compare objects --> for assignment_5, we make comparison operators in the object class itself
      if (elem->getId() < current->getKey()){
        // go left
        current = current->left;
        cout << "goin left" << endl;
        if (current == NULL){ // found insertion point
          parent->left = node;
          break;
        }
      }
      else{
        // go right
        current = current->right;
        cout << "goin right" << endl;
        if (current == NULL){ // found the insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
T BST<T>::find(int num)
{
  if(root == NULL)
  {
    cout << "BST Empty!" << endl;
    return NULL;
  }
  TreeNode<T>* current = root;
  int temp = current->getKey();
  //cout << "Entering loop" << endl;
  while (temp!= num)
  {
  //  cout << "Temp: " << temp << endl;
    //cout << "Num: " << num << endl;
    if (num < temp)
    {
      //cout << "going left" << endl;
      current = current->left;
    }
    else if(num > temp)
    {
      //cout << "current key: " << current->getKey() << endl;
      //cout << "going right" << endl;
      current = current->right;
    //  cout << "current key: " << current->getKey() << endl;
    }
    else if(current == NULL)
    {
      return NULL;
    }
    temp = current->getKey();
    //cout << "The number of new root: " << temp << endl;
  }
  //exit loop with correct object
  return current->getObject();
}
// this function may change to return a TreeNode<T>* for assignment_5
template <class T>
bool BST<T>::search(T elem){

  // if the tree is empty
  if (root == NULL){
    return false;
  }

  // made it here? the tree is for shizzle not empty
  TreeNode<T> *current = root;
  while ((T)current != (T)elem){
    if ((T)elem < (T)current){
      current = current->left;
    }
    else{
      current = current->right;
    }

    if (current == NULL){ //  value not in tree
      return false;
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteNode(T elem){

  if (root == NULL) // tree is empty
    return false;

  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeft = true;

  // let's attempt to find the node to be deleted
  while (current != elem)
  {
    parent = current;

    if (elem < current){
      // go left
      isLeft = true;
      current = current->left;
    }
    else{
      // go right
      isLeft = false;
      current = current->right;
    }

    if (current == NULL){
      // value doesn't exist
      return false;
    }
  }

  // if we make it here, then we have found the node to be deleted

  // if node is external / has 0 children / is a leaf
  if (current->left == NULL && current->right == NULL){

    if (current == root){
      root = NULL;
    }
    else if (isLeft){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
  }
  // if node has 1 child; and it's a left (no right child)
  else if (current->right == NULL){

    if (current == root){
      root = current->left;
    }
    else if (isLeft){
      parent->left = current->left;
    }
    else{
      parent->right = current->left;
    }
  }
  // if node has 1 child; and it's a right (no left child)
  else if (current->left == NULL){

    if (current == root){
      root = current->right;
    }
    else if (isLeft){
      parent->left = current->right;
    }
    else{
      parent->right = current->right;
    }
  }
  // if the node has 2 children --> uh oh lmao
  // get ready to rumble
  else{

    TreeNode<T> *successor = getSuccessor(current);

    if (current == root){
      root = successor;
    }
    else if (isLeft){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }

    successor->left = current->left;
  }
  return true;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ // d is the node to be deleted
  // the successor can either be the largest number less than d
  // or the smallest number greater than d.
  // Either of these work --> it doesn't matter which route you take --> it's personal preference
  // in this case, we will be choosing the latter --> right once than all the way left
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d; // Successor's Parent
  TreeNode<T> *successor = d;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  // we made it here, that means we found our successor
  if (successor != d->right){
    // if our successor is NOT just the node right of our deleted node
    // i.e. the tree is complicated and we have some work to do
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;

}

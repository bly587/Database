#include <iostream>

using namespace std;

template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T object); //k = key, which in this example is also the value(data)
    ~TreeNode(); // when creating a template class, destructor must be virtual

    //int key;
    T* obj;
    TreeNode *left;
    TreeNode *right;
};

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T object){
  obj = &object;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  //delete obj;
}

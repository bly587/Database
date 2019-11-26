#include <iostream>

using namespace std;

template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T object, int k); //k = key, which in this example is also the value(data)
    ~TreeNode(); // when creating a template class, destructor must be virtual
    int getKey();
    T getObject();

    int key;
    T obj;
    TreeNode *left;
    TreeNode *right;
};

template <class T>
TreeNode<T>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T object, int k){
  key = k;
  obj = object;
  left = NULL;
  right = NULL;
}

template <class T>
int TreeNode<T>::getKey()
{
  return key;
}

template <class T>
T TreeNode<T>::getObject()
{
  return obj;
}

template <class T>
TreeNode<T>::~TreeNode(){
  //delete obj;
}

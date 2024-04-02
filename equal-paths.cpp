#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <algorithm>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool equalPaths(Node * root)
{
    // Add your code below
  if(root == NULL){
    return true;
  }

  if(root->left == NULL && root->right != NULL){
    return equalPaths(root->right);
  } else if(root-> right == NULL && root->left != NULL){
     return equalPaths(root->left);
  }
  
  int leftHeight = height(root->left); 
  int rightHeight = height(root->right);

  return equalPaths(root->left) && equalPaths(root->right) && (leftHeight == rightHeight);
}

int height(Node * curr){
  if(curr == NULL){
    return 0;
  }

  int leftHeight = height(curr->left); 
  int rightHeight = height(curr->right);

  return 1 + max(leftHeight,rightHeight);
}



/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"

Bst create_newNode(int value);

 struct Node{
  int value;
  Node* right_subtree;
  Node* left_subtree;
};

Bst new_bst()
{
  Bst bst = 0;
  return bst;
}

void delete_bst(Bst bst)
{
  if (bst != 0) {
    delete_bst(bst->left_subtree);
    delete_bst(bst->right_subtree);
    sfree(bst);
  }
}


int get_depth(Bst bst)
{
  if (bst == 0) {
    return 0;
  }
  if (bst->left_subtree == 0 && bst->right_subtree == 0) {
    return 1;
  }
  if(get_depth(left_subtree(bst)) >  get_depth(right_subtree(bst))){
    return 1 + get_depth(left_subtree(bst));
  }

  return 1 +get_depth(right_subtree(bst));
}

Bst create_newNode(int value){
  Bst newNode = (Bst)malloc(sizeof(Node));
  newNode->value=value;
  newNode->right_subtree=0;
  newNode->left_subtree=0;
  return newNode;
}

void add(Bst* bst, int value){

  if (*bst==0)
  {
    *bst=create_newNode(value);
  }
  else if(value<=(*bst)->value)
  {
    if((*bst)->left_subtree == 0){
    (*bst)->left_subtree=create_newNode(value);
    }else{
      add(&(*bst)->left_subtree, value);
    }
  }
  else if(value>(*bst)->value)
  {
    if((*bst)->right_subtree == 0){
      (*bst)->right_subtree=create_newNode(value);
    }else{
      add(&(*bst)->right_subtree, value);
    }
  }
}


int root_value(Bst bst)
{
  return bst->value;
}


Bst left_subtree(Bst root)
{
  if (root==0)
  {
    return 0;
  }
  return root->left_subtree;
}

Bst right_subtree(Bst root)
{
  if (root==0)
  {
    return 0;
  }
  return root->right_subtree;
}


int traverse_pre_order(Bst bst, int *elements, int start)
{
  if (bst != 0) {
    elements[start] = bst->value;
    start++;
    start = traverse_pre_order(bst->left_subtree, elements, start);
    start = traverse_pre_order(bst->right_subtree, elements, start);
  }
  return start;
}


int traverse_in_order(Bst bst, int *elements, int start)
{
  if (bst != 0) {
    start = traverse_in_order(bst->left_subtree, elements, start);
    elements[start] = bst->value;
    start++;
    start = traverse_in_order(bst->right_subtree, elements, start);
  }
  return start;
}


int traverse_post_order(Bst bst, int *elements, int start)
{
  if (bst != 0) {
    start = traverse_post_order(bst->left_subtree, elements, start);
    start = traverse_post_order(bst->right_subtree, elements, start);
    elements[start] = bst->value;
    start++;
  }
  return start;
}

bool are_equal(Bst bst1, Bst bst2)
{
  if (bst1 == bst2) {
    return true;
  }
  else if (bst1->value == bst2->value) {
    return true;
  }
  else if (bst1 != bst2) {
    return false;
  }
  else{
    return false;
  }
}


void most_left_longest_branch(Bst bst, Bst* branch)
{

}

int get_number_of_subtrees(Bst bst)
{
  return 0;
}

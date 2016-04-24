/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int heightofbst(struct node *root, int *nodes){
	int left_height = 0;
	int right_height = 0;
	if (root == NULL)
		 return 0;
	(*nodes)++;
	left_height = heightofbst(root->left, nodes) + 1;
	(*nodes)++;
	right_height = heightofbst(root->right, nodes) + 1;
	if (left_height > right_height)
		 return left_height;
	else
		 return right_height;
	
}

void storegivenbst(struct node* root, int level, int* result, int *index)
 {
	if (root == NULL)
		 return;
	if (level == 1){
		result[*index] = root->data;
		(*index)++;
		
	}
	else
		 {
		storegivenbst(root->right, level - 1, result, index);
		storegivenbst(root->left, level - 1, result, index);
		}
	}


int* bsttorows(struct node* root)
 {
	int nodes = 0;
	int h = heightofbst(root, &nodes);
	int *result = (int *)malloc(sizeof(int) * nodes);
	int i;
	int index = 0;
	for (i = 1; i <= h; i++)
		 storegivenbst(root, i, result, &index);
	return result;
	}

int* BSTRighttoLeftRows(struct node *root)
{
	{
		if (root == NULL)
			return NULL;	
		return bsttorows(root);
	}
}
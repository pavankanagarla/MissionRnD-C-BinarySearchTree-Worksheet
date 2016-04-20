/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void in_order(struct node *temp, int *result, int *i){
	if (temp == NULL){
		return;
	}
	in_order(temp->left, result, i);
		result[*i] = temp->data;
		(*i)++;
	in_order(temp->right, result, i);
}
void pre_order(struct node *temp, int *result, int *i){
	if (temp == NULL){
		return;
	}
	result[*i] = temp->data;
	(*i)++;
	pre_order(temp->left, result, i);
	pre_order(temp->right, result, i);
}
void post_order(struct node *temp, int *result, int *i){
	if (temp == NULL){
		return;
	}
	post_order(temp->left, result, i);
	post_order(temp->right, result, i);
	result[*i] = temp->data;
	(*i)++;
}

void inorder(struct node *root, int *arr){
	int i = 0;
	if (root == NULL || arr == NULL)
		return;
	in_order(root, arr, &i);
	
}
void preorder(struct node *root, int *arr){
	int i = 0;
	if (root == NULL || arr == NULL)
		return;
	pre_order(root, arr, &i);
}
void postorder(struct node *root, int *arr){
	int i = 0;
	if (root == NULL || arr == NULL)
		return;
	post_order(root, arr, &i);
}


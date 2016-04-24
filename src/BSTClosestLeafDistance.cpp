/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int height(struct node *root){
	int lheight;
	int rheight;
	if (root == NULL)
		return 0;
	lheight = height(root->left);
	rheight = height(root->right);
	if (lheight == 0 && rheight != 0)
		return rheight + 1;
	else if (lheight != 0 && rheight == 0)
		return lheight + 1;
	else if (lheight < rheight)
		return lheight + 1;
	else
		return rheight + 1;
}
void getdistance(struct node *root,struct node *temp, int *h,int *node_count){
	int t;
	if (root){
		if (root == temp){
			*h = height(root);
			*node_count = 1;;
		} else {
			if (root->data > temp->data) {
				getdistance(root->left, temp, h, node_count);
				if (*node_count != 0) {
					t = height(root);
					if (*h > t + *node_count)
						*h = t + *node_count;
				}
			} else {
				getdistance(root->right, temp, h, node_count);
				if (*node_count != 0){
					t = height(root);
					if (t + *node_count < *h)
						*h = t + *node_count;
				}
			}
		}
	}
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	int h = 0;
	int node_count = 0;
	if (root == NULL || temp == NULL)
		return -1;
    getdistance(root, temp, &h, &node_count);
	return h - 1;
}
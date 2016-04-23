/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void checkbst(struct node* root, struct node** one,struct node** two, struct node** three,struct node** temp)
{
	if (root == NULL)
		return;
	checkbst(root->left, one, two, three, temp);
	if (*temp && root->data < (*temp)->data)
	{
		if (*one == NULL)
		{
			*one = *temp;
			*two = root;
		}
	else
			*three = root;
	}
	*temp = root;
	checkbst(root->right, one, two, three, temp);
}
void bst(struct node* root)
{
	int t;
	struct node *one = NULL;
	struct node *two = NULL;
	struct node *three = NULL;
	struct node *temp =  NULL;
	checkbst(root, &one, &two, &three, &temp);
	if (three == NULL)
		three = two;
	t			= one->data;
	one->data	= three->data;
	three->data = t;
}

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	bst(root);
}

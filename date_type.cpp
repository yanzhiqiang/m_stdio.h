#include "date_type.h"

int reset_TreeNode(struct TreeNode* tree_node)
{
	tree_node->num = NULL ;
	tree_node->left_length = 0;
	tree_node->right_length = 0;
	tree_node->left_son = NULL;
	tree_node->right_son = NULL;
	tree_node->parent = NULL;
}
#ifndef __DATE_TYPE_H
#define __DATE_TYPE_H

struct TreeNode 
{
	double* num;
	int left_length;
	int right_length;
	strcut TreeNode* left_son;
	struct TreeNode* right_son;
	struct TreeNode* parent;	
};

int reset_TreeNode(struct TreeNode* tree_node);

#endif

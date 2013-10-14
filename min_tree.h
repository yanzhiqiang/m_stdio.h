#ifndef __MIN_TREE_H
#define __MIN_TREE_H

//to do : template to support float,char
class Min_Tree
{
public:
	Min_Tree();
	Min_Tree(double* num);
	int add_tree(double* num);
	double* pop_tree();
	double* top_tree();
	int delete_tree_node(struct TreeNode* node);
	~Min_Tree();	

private:
	struct TreeNode* Min_Tree_Root;
};


#endif

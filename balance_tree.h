#ifndef __BALANCE_TREE_H
#define __BALANCE_TREE_H

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

//to do : template to support float,char
class Balance_Tree
{
public:
	Balance_Tree();
	Balance_Tree(double* num);
	int add_tree(double* num);
	double* pop_tree();
	double* top_tree();
	int delete_tree_node(struct TreeNode* node);
	~Balance_Tree();	

private:
	struct TreeNode* Balance_Tree_Root;
}


#endif
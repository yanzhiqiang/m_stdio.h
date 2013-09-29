/*
	最小生成树算法
	1:指针
	左节点<根节点 右节点<根节点
	2:最小生成树，根节点小于子树节点。双向链表+标记左右子树的长度+数值
		申请空间增删过程中不要删除，到了最后再删除。
	
	平衡树：
	1:平衡树--每次与根比较，这样左右子树的长度差就交给刚开始确定的根节点来确定。
	左节点<根节点<右节点
	双向链表，标记左右子树的长度+数值
	申请空间增删过程中要删除。
	预申请20个struct Node 空间
*/

#include "Min_Tree.h"
#include "date_type.h"


Min_Tree::Min_Tree()
{
	Min_Tree_Root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	reset_TreeNode(Min_Tree_Root);
	Min_Tree_Root->parent = Min_Tree_Root;
}

Min_Tree::Min_Tree(double* num)
{
	Min_Tree_Root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	reset_TreeNode(Min_Tree_Root);
	Min_Tree_Root->num =  num;
	Min_Tree_Root->parent = Min_Tree_Root;
}

int Min_Tree::add_tree(double* p_num)
{ 
	struct TreeNode* d_TreeNode = Min_Tree_Root;		//target position
	struct TreeNode* t_TreeNode = d_TreeNode ;
	//find position to insert 
	
}

double* Min_Tree::pop_tree()
{
	double* t_root_value = Min_Tree_Root->num;
	delete_tree_node(Min_Tree_Root);
	return t_root_value;
}

double* Min_Tree::top_tree()
{
	return Min_Tree_Root->num;	
}

//just delete root
int delete_tree_node(struct TreeNode* p_node)
{
	if(p_node->left_son == NULL && p_node->right_son == NULL)
	{
		free(p_node);
		p_node=NULL;
	}
	
	struct TreeNode* p1 = p_node;
	struct TreeNode* p2 = p_node;
	
}

Min_Tree::~Min_Tree()
{
	while(Min_Tree_Root)
	{
		delete_tree_node(Min_Tree_Root);
	}
	Min_Tree_Root = NULL;
}

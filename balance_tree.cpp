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

#include "balance_tree.h"

int reset_TreeNode(struct TreeNode* tree_node)
{
	tree_node->num = NULL ;
	tree_node->left_length = 0;
	tree_node->right_length = 0;4
	tree_node->left_son = NULL;
	tree_node->right_son = NULL;
	tree_node->parent = NULL;
}

Balance_Tree::Balance_Tree()
{
	Balance_Tree_Root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	reset_TreeNode(Balance_Tree_Root);
	Balance_Tree_Root->parent = Balance_Tree_Root;
}

Balance_Tree::Balance_Tree(double* num)
{
	Balance_Tree_Root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	reset_TreeNode(Balance_Tree_Root);
	Balance_Tree_Root->num =  num;
	Balance_Tree_Root->parent = Balance_Tree_Root;
}

int Balance_Tree::add_tree(double* p_num)
{ 
	struct TreeNode* d_TreeNode = Balance_Tree_Root;		//target position
	struct TreeNode* t_TreeNode = d_TreeNode ;
	//find position to insert 
	while(d_TreeNode)
	{
		t_TreeNode =  d_TreeNode;
		if((*d_TreeNode->num)<*p_num)
		{
			d_TreeNode=d_TreeNode->left_son;
		}
		else
		{
			d_TreeNode=d_TreeNode->right_son;
		}
	}
	
	//node is NULL
	if(!d_TreeNode)
	{
		d_TreeNode =  (struct TreeNode*) malloc(sizeof(struct TreeNode));
		reset_TreeNode(d_TreeNode);
		d_TreeNode->parent = t_TreeNode;
		d_TreeNode->num = p_num;
		if((*d_TreeNode->num)<(*t_TreeNode->num))
		{
			t_TreeNode->left_son =  d_TreeNode;
			t_TreeNode->left_length++;
		}
		else
		{
			t_TreeNode->right_length =  d_TreeNode;
			t_TreeNode->right_length++;
		}
	}
}

double* Balance_Tree::pop_tree()
{
	double* t_root_value = Balance_Tree_Root->num;
	delete_tree_node(Balance_Tree_Root);
	return t_root_value;
}

double* Balance_Tree::top_tree()
{
	return Balance_Tree_Root->num;	
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
	if(p1->left_son != NULL)
	{
		while(p1->left_son)
		{
			p2=p1;
			p1=p1->left_son;
			while(p1->right_son != NULL)
			{
				p1=p1->right_son;
			}
			p2->num=p1->num;
			p1->num=NULL;
		}
		free(p1)
		p1=NULL;
	}
	else
	{
		while(p1->right_son)
		{
			p2=p1;
			p1=p1->right_son;
			while(p1->left_son != NULL)
			{
				p1 = p1->left_son;
			}
			p2->num=p1->num;
			p1->num=NULL;
		}
		free(p1);
		p1=NULL;
	}
}

Balance_Tree::~Balance_Tree()
{
	while(Balance_Tree_Root)
	{
		delete_tree_node(Balance_Tree_Root);
	}
	Balance_Tree_Root = NULL;
}
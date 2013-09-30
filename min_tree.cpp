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
	if(Min_Tree_Root->num  == NULL)
	{
		Min_Tree_Root->num = p_num;
		return 0;
	}
	
	struct TreeNode* d_TreeNode = Min_Tree_Root;		//target position
	struct TreeNode* t_TreeNode = d_TreeNode ;
	//find position to insert 
	while(t_TreeNode)
	{
		d_TreeNode = t_TreeNode;
		if(t_TreeNode->left_length <= t_TreeNode->right_length)
		{
			t_TreeNode = t_TreeNode->left_length;
			if(t_TreeNode == NULL)
			{
				t_TreeNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				reset_TreeNode(t_TreeNode);
				t_TreeNode->num = p_num;
				t_TreeNode->parent = d_TreeNode;
				d_TreeNode->left_son = t_TreeNode;
				d_TreeNode->left_length++;
				break;
			}	
		}
		else
		{
			t_TreeNode = t_TreeNode->right_length;
			if(t_TreeNode == NULL)
			{
				t_TreeNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				reset_TreeNode(t_TreeNode);
				t_TreeNode->num = p_num;
				t_TreeNode->parent = d_TreeNode;
				d_TreeNode->right_son = t_TreeNode;
				d_TreeNode->right_length++;
				break;
			}
		}
	}
	
	//t_TreeNode make it ordered
	struct TreeNode* t1 = t_TreeNode;
	while(t1->num < t1->parent->num)
	{
		double* temp =  t1->parent->num;
		t1->parent->num = t1->num;
		t1->num = temp;
	}
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
	if(!p_node)	return -1;
	if(p_node->left_son == NULL && p_node->right_son == NULL)
	{
		free(p_node);
		p_node=NULL;
		return 0;
	}
	
	struct TreeNode* p1 = p_node;
	struct TreeNode* p2 = p_node;
	//parents length--
	while(p1 != Min_Tree_Root)
	{
		p2 = p1->parent;
		if(p2->left_son == p1)
		{
			p2->left_length--;
		}
		else
		{
			p2->right_length--;
		}
	}
	
	while(p1->left_son != NULL || p1->right_son != NULL)
	{
		double* t1 = NULL;
		if(p1->left_son != NULL)
		{
			t1 = p1->left_son->num;
		}
		
		if(p1->right_son != NULL && (t1==NULL || p1->right_son->num < t1))
		{
			t1 = p1->right_son->num;
		}
		
		if(t1 == p1->left_son->num)
		{
			p1->left_length--;
			p1->num=p1->left_son->num;
			p1 = p1->left_son;
		}
		else
		{
			p1->right_length--;
			p1->num=p1->right_son->num;
			p1 = p1->right_son;

		}
	}
	free(p1);
	p1=NULL;
	return 0;
}

Min_Tree::~Min_Tree()
{
	while(Min_Tree_Root)
	{
		delete_tree_node(Min_Tree_Root);
	}
	Min_Tree_Root = NULL;
}

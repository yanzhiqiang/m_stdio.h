/*
	��С�������㷨
	1:ָ��
	��ڵ�<���ڵ� �ҽڵ�<���ڵ�
	2:��С�����������ڵ�С�������ڵ㡣˫������+������������ĳ���+��ֵ
		����ռ���ɾ�����в�Ҫɾ�������������ɾ����
	
	ƽ������
	1:ƽ����--ÿ������Ƚϣ��������������ĳ��Ȳ�ͽ����տ�ʼȷ���ĸ��ڵ���ȷ����
	��ڵ�<���ڵ�<�ҽڵ�
	˫������������������ĳ���+��ֵ
	����ռ���ɾ������Ҫɾ����
	Ԥ����20��struct Node �ռ�
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
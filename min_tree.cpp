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

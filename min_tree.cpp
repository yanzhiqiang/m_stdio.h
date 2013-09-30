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

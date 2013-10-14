#include "display_tree.h"
#include <stack.h>
#include <queue.h>
#include <stdio.h>
#include "date_type.h"

//stack
//recuri   if(NULL) return; a(r->left);visit(r->num);a(r->right);
int left_depth_display(struct TreeNode* root)
{
	if(!root) return 0;
	stack<struct TreeNode*> s_stack;
	struct TreeNode	*p1,*p2;
	p1=root;
	p2=root;
	while(p1 || s_stack.empty())
	{
		while(p1)
		{
			s_stack.push(p1);
			p1=p1->left_son;
		}
		
		if(!s_stack.empty())
		{
			p1=s_stack.top();
			printf("%lf\t",p1->num);
			s_stack.pop();
		}
		
		p1=p1->right_son;
	}
	return 0;
}

//
int right_depth_display(struct TreeNode* root)
{
	if(!root)	return 0;
	struct TreeNode	*p1,*p2;
	p1=root;
	p2=NULL;
	stack<struct TreeNode*> s_stack;
	while(p1 || s_stack.empty())
	{
		while(p1)
		{
			s_stack.push(p1);
			p1=p1->left_son;
		}
		
		p1=s_stack.top();
		while(p1->right_son == NULL || p1->right_son == p2)
		{
			p1=s_stack.top();
			s_stack.pop();
			p2=p1;
			printf("%lf\t",p1->num);
		}
		
		p1=p1->right_son;
	}
	return 0;
}

int root_depth_display(struct TreeNode* root)
{
	if(!root)	return 0;
	struct TreeNode	*p1,*p2;
	p1=root;
	p2=root;
	stack<struct TreeNode*> s_stack;
	while(p1 || s_stack.empty())
	{
		while(p1)
		{
			s_stack.push(p1);
			printf("%lf\t",p1->num);
			p1=p1->left_son;
		}
		
		if(!s_stack.empty())
		{
			p1=s_stack.top();
			s_stack.pop();
		}
		
		p1=p1->right_son;
	}
	return 0;
}


int root_wide_display(struct TreeNode* root)
{


}

#include <iostream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <vector>
using namespace std;
vector<string> check(BTNode * root);
BTNode * createBTNode (string data) {
	BTNode * newNode;

	newNode = new BTNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	return newNode;

}


void visitNode (BTNode * btNode) {
	cout << btNode->data << " ";
}
int max_int(int a , int b)
{
	if(a>b)
	return a;
	return b;
}

int height (BTNode * root) {
     if (root == NULL)
        return 0;
    int height_ =0;
    if (root ->left == NULL && root->right == NULL )
        return 0 ;
    if(root->left != NULL)
        height_ = height(root->left) +1;
    if (root ->right != NULL)
        height_ = max_int(height_ , height(root->right)+1);

	return height_;
}


void inOrderIterative(BTNode * root) {
     if (root == NULL)
        return ;
        Stack *my_stack = initStack ();
        BTNode *my_node =  root ;

      while( my_node != NULL ||isEmptyStack(my_stack) == 0 )
      {
          while(my_node != NULL)
          {
              push(my_stack, my_node);
              my_node = my_node->left;
          }
          my_node = pop(my_stack);
          cout << my_node ->data << "\n";
          my_node = my_node->right;
      }

}


bool isEmptyTree (BTNode * root) {

	return (root->left == NULL && root->right == NULL);
}



bool isEqual (BTNode * root1, BTNode * root2) {
	std::vector<string> tree1 , tree2;
	tree1 = check(root1), tree2 = check(root2);
	return (tree1 == tree2); // return true if both trees are identical
}


void levelOrder (BTNode * root) {
     if (root == NULL)
        return ;
			Queue* my_queue = initQueue();
			enqueue(my_queue, root);
			BTNode *  my_node = root;
			while(sizeQueue(my_queue))
			{
				my_node = dequeue(my_queue);
				cout<< my_node->data << "\n";
				if(my_node->left != NULL)
					enqueue(my_queue , my_node-> left);
				if(my_node->right != NULL)
				enqueue(my_queue , my_node-> right);
			}
}
vector<string> check(BTNode * root) {
        vector<string> v ;
       if (root == NULL)
        return v ;
			Queue* my_queue = initQueue();
			enqueue(my_queue, root);
			BTNode *  my_node = root;
			while(sizeQueue(my_queue))
			{
				my_node = dequeue(my_queue);
				v.push_back(my_node->data) ;
				if(my_node->left != NULL)
					enqueue(my_queue , my_node-> left);
				if(my_node->right != NULL)
				enqueue(my_queue , my_node-> right);
			}
return v;
}

int moment(BTNode * root) {
	std::vector<string> v = check(root);
	return v.size();
}


int numLevels(BTNode * root) {
     if (root == NULL)
        return 0;
	Queue *my_queue = initQueue();
	enqueue(my_queue, root);
	BTNode *  my_node = root;
	int cnt = 1;
	while(sizeQueue(my_queue))
	{
		my_node = dequeue(my_queue);
		//cout<< my_node->data << "\n";
		if(my_node->left != NULL)
			enqueue(my_queue , my_node-> left), cnt++;
		if(my_node->right != NULL)
		enqueue(my_queue , my_node-> right), cnt++;
	}
	return cnt;
}


void preOrderIterative (BTNode * root) {
    if (root == NULL)
        return ;
	Stack *my_stack = initStack ();
	BTNode *my_node = root ;
	push(my_stack, my_node);

	while(isEmptyStack(my_stack)!= 1)
	{
			my_node = my_stack->top -> data;
			cout<<pop(my_stack) ->data<< "\n" ;
			if(my_node ->right != NULL)
				push(my_stack, my_node -> right);
			if(my_node->left != NULL)
			push(my_stack,my_node->left);
	}
}


void postOrderIterative (BTNode * root) {
    if (root == NULL)
        return;
    Stack * s1 = initStack();
    Stack * s2 = initStack();
    BTNode * my_node= root ;
    push(s1, my_node);
    while (isEmptyStack(s1)==0)
    {
        my_node = pop(s1);
        push(s2, my_node);
        if (my_node->left)
            push(s1, my_node->left);
        if (my_node->right)
            push(s1, my_node->right);
    }
    while (isEmptyStack(s2)==0)
    {
        my_node = pop(s2);
        cout<< (my_node->data)<< "\n";
    }
}


int weight(BTNode * root) {
	Queue *my_queue = initQueue();
	enqueue(my_queue, root);
	BTNode *  my_node = root;
	int cnt = 0;
	while(sizeQueue(my_queue))
	{
		my_node = dequeue(my_queue);
		bool isleave = 1;
		//cnt+=((my_node->left == NULL) && (my_node->right == NUll));

		if(my_node->left != NULL)
			enqueue(my_queue , my_node-> left), isleave=0;
		if(my_node->right != NULL)
		enqueue(my_queue , my_node-> right), isleave=0;
		cnt+= isleave ;
	}
	return cnt;
}


int width(BTNode * root) {
	Queue *my_queue = initQueue();
	enqueue(my_queue, root);
	BTNode *  my_node = root;
	int _width =0;
	while(sizeQueue(my_queue))
	{
		my_node = dequeue(my_queue);
		if(my_node->left != NULL)
			enqueue(my_queue , my_node-> left);
		if(my_node->right != NULL)
		enqueue(my_queue , my_node-> right);
		_width = max(_width ,sizeQueue(my_queue));
	}
	return _width;
}

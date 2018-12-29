#include <iostream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include<vector>
using namespace std;
BTNode * inOrderPredecessor (BTNode * node);
BTNode * inOrderSuccessor (BTNode * node) ;
BTNode * ceiling(BTNode * root, string key) {

	if(root-> data == key)
		return root;
		if(key > root ->data )
			{
				if (root-> right == NULL)
					return NULL;
				ceiling(root->right, key);
			}
			else{

				if(root-> left == NULL)
					return root;
				BTNode * my_node  = ceiling(root-> left, key);
				if (my_node != NULL && my_node-> data > root->data )
				return my_node;
				return root;
			}
}


BTNode * contains(BTNode * root, string key) {
    if (root == NULL)
        return NULL ;
	if (root-> data == key)
		return root ;
	if(root-> data < key && root-> right != NULL)
        return	contains(root-> right , key);
	if(root-> data >key && root ->left != NULL)
        return	contains(root->left , key);

	return NULL;
}
BTNode * getRoot(BTNode * root)
{
	if(root-> parent == NULL)
		return root ;
	getRoot(root-> parent);
}
BTNode * delete_node(BTNode * root  , string key)
{

    if (root->data == key)
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left == NULL || root->right == NULL)
            {
                if (root-> left)
                    root->data = root->left->data ,  root->left = NULL;
                else
                    root->data = root->right->data ,  root->right = NULL;
                return root;
            }
        BTNode * my_node = inOrderSuccessor(root);
        root->data = my_node->data ;
        my_node->parent ->left = NULL;
        return root ;
    }
    if (root->data > key)
        root->left= delete_node( root->left , key);
    if (root ->data < key)
        root->right = delete_node(root->right , key);
    return root ;
}
BTNode * deleteNode(BTNode * root, string key) {
	if (contains(root , key)== NULL)
		return root ;


	return delete_node(root, key);
}


BTNode * floor(BTNode * root, string key) {
	if (root-> data == key)
		return root;
	if (root->data > key && root-> left != NULL)
		return floor (root->left , key);
		if(root->data < key)
		{
			if(root-> right == NULL)
			return root ;
			BTNode * my_node =  floor(root->right, key);
			if (my_node->data <=key)
				return my_node;
				return root;
		}

	return NULL;
}


BTNode * inOrderPredecessor (BTNode * node) {
    if(node->left == NULL)
        return NULL;
    node = node ->left ;
    while(node->right != NULL)
        node = node->right;
	return node;
}


BTNode * inOrderSuccessor (BTNode * node) {
	if (node->right == NULL)
        return NULL;
    node = node->right;
    while(node->left != NULL)
        node = node->left;
    return node ;
}


BTNode * insert(BTNode * root, string key) {
    if (root == NULL)
    {
        root =createBTNode(key);
        return root;
    }

  if (key < root-> data )
		{
			if(root-> left == NULL)
					{
						root->left = createBTNode(key);
						root->left->parent = root ;
						return root ;
					}
				else{
						root-> left = insert(root-> left ,  key);
						return root;

				}
		}
				else if (key > root-> data)
				{
					if(root-> right == NULL)
							{
								root->right = createBTNode(key);
								root->right ->parent = root;
								return root ;
							}
						else{
								root-> right = insert(root-> right ,  key);
								return root;
				}

		}
	return root;
}


BTNode * max(BTNode * root) {
	if(root-> right == NULL)
		return root;
	max(root->right);
}


BTNode * min(BTNode * root) {
	if(root->left ==NULL)
	return root;
	min(root->left);
}

string findPredecessor (BTNode * root , string key)
{
    vector<string> v  = check(root);
    string s = "";
    for(int i =0;i<v.size();i++)
        if (v[i] <= key && (v[i] > s|| s.empty()))
            s =v[i];
    return s ;
}
string findSuccessor(BTNode * root , string key)
{
    vector<string> v  = check(root);
    string s = "";
    for(int i = 0 ; i<v.size();i++)
        if(v[i]>=key && (s.empty() || v[i] < s))
    {
        s=v[i];

    }
    return s;
}

int range(BTNode * root, string low, string high) {
	return 0;
}


int rank(BTNode * root, string key) {
	return 0;
}

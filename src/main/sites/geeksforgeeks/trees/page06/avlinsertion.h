/****************************************************************************************************************************************************
 *  File Name   		: avlinsertion.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\avlinsertion.h
 *  Created on			: Jun 9, 2014 :: 10:21:21 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef AVLINSERTION_H_
#define AVLINSERTION_H_

struct iavltNode{
	int value;
	unsigned int height;
	iavltNode *left;
	iavltNode *parent;
	iavltNode *right;

	iavltNode(){

	}

	iavltNode(int value){
		this->value = value;
		height = 1;
		left = null;
		parent = null;
		right = null;
	}
};


/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

iavltNode *insertNodeAtRightPlace(iavltNode **root,iavltNode *currentNode,int userInput){
	if(*root == null){
		(*root) = new iavltNode(userInput);
		return (*root);
	}else{
		if(currentNode->value == userInput){
			return null;
		}
		if(currentNode->value > userInput){
			if(currentNode->left == null){
				currentNode->left = new iavltNode(userInput);
				currentNode->left->parent = currentNode;
				return currentNode->left;
			}else{
				return insertNodeAtRightPlace(root,currentNode->left,userInput);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new iavltNode(userInput);
				currentNode->right->parent = currentNode;
				return currentNode->right;
			}else{
				return insertNodeAtRightPlace(root,currentNode->right,userInput);
			}
		}
	}
}

void rotateNodes(iavltNode *parent,iavltNode *child){
	iavltNode *grandParent = parent->parent;
	if(grandParent != null){
		child->parent = grandParent;
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		child->parent = null;
	}
	parent->parent = child;
	iavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = child;
		if(temp != null){
			temp->parent = parent;
		}
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = child;
		if(temp != null){
			temp->parent = parent;
		}
	}
}

void insertNodeIntoAvlTree(iavltNode **root,int userInput){
	iavltNode *ptrToInsertedNode = insertNodeAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	iavltNode *z,*y,*x;
	z = ptrToInsertedNode;
	unsigned int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			if(z->value > userInput){
				y = z->left;
			}else{
				y = z->right;
			}
			if(y->value > userInput){
				x = y->left;
			}else{
				x = y->right;
			}
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				if(z->parent == null){
					(*root) = y;
				}
				rotateNodes(z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				rotateNodes(y,x);
				rotateNodes(z,x);
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height)+1;
			}
		}
		z->height = max(leftHeight,rightHeight)+1;
		z = z->parent;
	}
}

#endif /* AVLINSERTION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

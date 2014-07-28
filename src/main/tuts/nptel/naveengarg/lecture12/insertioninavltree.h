/****************************************************************************************************************************************************
 *  File Name   		: insertioninavltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture12\insertioninavltree.h
 *  Created on			: Jun 8, 2014 :: 9:31:49 AM
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

#ifndef INSERTIONINAVLTREE_H_
#define INSERTIONINAVLTREE_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
iavltNode *insertNode(iavltNode **ptr,iavltNode *currentNode,int userInput){
	if(ptr == null){
		(*ptr) = new iavltNode(userInput);
		return (*ptr);
	}
	if(ptr->value == userInput){
		return null;
	}
	if(ptr->value > userInput){
		if(ptr->left == null){
			ptr->left = new iavltNode(userInput);
			ptr->left->parent = ptr;
			return ptr->left;
		}else{
			return getParentPtrForInsertion(ptr,currentNode->left,userInput);
		}
	}else{
		if(ptr->right == null){
			ptr->right = new iavltNode(userInput);
			ptr->right->parent = ptr;
			return ptr->right;
		}else{
			return getParentPtrForInsertion(ptr,currentNode->right,userInput);
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
		parent->left = temp;
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
}

void insertNodeIntoAvlTree(iavltNode **ptr,int userInput){
	iavltNode *ptrToInsertedNode = insertNode(ptr,*ptr,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	iavltNode *z,*y,*x;
	z = ptrToInsertedNode->parent;
	unsigned int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				if(z->parent == null){
					(*ptr) = y;
				}
				rotateNodes(z,y);
				z->height = max(z->left==null?0:z->left->height,z->right==null?0:z->right->height)+1;
				y->height = max(y->left==null?0:y->left->height,y->right==null?0:y->right->height)+1;
			}else{
				if(z->parent == null){
					(*root) = x;
				}
				rotateNodes(y,x);
				rotateNodes(x,z);
				y->height = max(y->left==null?0:y->left->height,y->right==null?0:y->right->height)+1;
				z->height = max(z->left==null?0:z->left->height,z->right==null?0:z->right->height)+1;
				x->height = max(x->left==null?0:x->left->height,x->right==null?0:x->right->height)+1;
			}
			break;
		}
		z->height = max(leftHeight,rightHeight)+1;
		z = z->parent;
	}
}

#endif /* INSERTIONINAVLTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

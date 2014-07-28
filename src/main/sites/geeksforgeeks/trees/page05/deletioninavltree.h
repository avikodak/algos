/****************************************************************************************************************************************************
 *  File Name   		: deletioninavltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\deletioninavltree.h
 *  Created on			: Jun 10, 2014 :: 12:47:15 PM
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

#ifndef DELETIONINAVLTREE_H_
#define DELETIONINAVLTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(LOGN) Algorithm 																*/
/****************************************************************************************************************************************************/
iavltNode *deleteALeafOrOneChildNode(iavltNode **root,iavltNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left !=  null && ptr->right != null){
		return null;
	}
	iavltNode *parent = ptr->parent;
	if(ptr->left == null && ptr->right == null){
		if(parent == null){
			(*root) = null;
			return null;
		}
		if(parent->left == ptr){
			parent->left = null;
		}else{
			parent->right = null;
		}
		free(ptr);
		return parent;
	}
	if(ptr->left == null || ptr->right == null){
		if(parent == null){
			(*root) = ptr->left != null?ptr->left:ptr->right;
			return null;
		}
		if(parent->left == ptr){
			parent->left = ptr->left != null?ptr->left:ptr->right;
			if(parent->left != null){
				parent->left->parent = parent;
			}
		}else{
			parent->right = ptr->left != null?ptr->left:ptr->right;
			if(parent->right != null){
				parent->right->parent = parent;
			}
		}
		free(ptr);
		return parent;
	}
}

iavltNode *searchForNodeAvlTree(iavltNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	if(ptr->value > value){
		return searchForNodeAvlTree(ptr->left,value);
	}else{
		return searchForNodeAvlTree(ptr->right,value);
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
		parent->left = temp;
		child->right = parent;
		if(temp != null){
			temp->parent = parent;
		}
	}else{
		temp = child->left;
		parent->right = temp;
		child->left = parent;
		if(temp != null){
			temp->parent = parent;
		}
	}
}

void deleteNodeAvlTree(iavltNode **root,int value){
	if(*root == null){
		return;
	}
	iavltNode *ptrToNodeBeDeleted = searchForNodeAvlTree(*root,value);
	if(ptrToNodeBeDeleted == null){
		return;
	}
	iavltNode *z,*y,*x;
	if(ptrToNodeBeDeleted->left == null || ptrToNodeBeDeleted->right == null){
		z = deleteALeafOrOneChildNode(root,ptrToNodeBeDeleted);
	}else{
		z = ptrToNodeBeDeleted;
		ptrToNodeBeDeleted = ptrToNodeBeDeleted->left;
		while(ptrToNodeBeDeleted->right != null){
			ptrToNodeBeDeleted = ptrToNodeBeDeleted->right;
		}
		z->value = ptrToNodeBeDeleted->value;
		z = deleteALeafOrOneChildNode(root,ptrToNodeBeDeleted);
	}
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1){
			y = (z->left == null?0:z->left->height) >= (z->right == null?0:z->right->height)?z->left:z->right;
			x = (y->left == null?0:y->left->height) >= (y->right == null?0:y->right->height)?y->left:y->right;
			if((z->left == y && y->left == x) || (z->right == y || y->right == x)){
				rotateNodes(z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
				z = y->parent;
			}else{
				rotateNodes(y,x);
				rotateNodes(z,x);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height)+1;
				z = x->parent;
			}
		}else{
			z->height = max(leftHeight,rightHeight) + 1;
			z = z->parent;
		}
	}
}

#endif /* DELETIONINAVLTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

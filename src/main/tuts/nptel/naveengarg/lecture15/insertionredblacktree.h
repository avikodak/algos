/****************************************************************************************************************************************************
 *  File Name   		: insertionredblacktree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture15\insertionredblacktree.h
 *  Created on			: Jun 17, 2014 :: 8:36:42 PM
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

#ifndef INSERTIONREDBLACKTREE_H_
#define INSERTIONREDBLACKTREE_H_

struct iRedBlackNode{
	int value;
	bool isRedNode;
	iRedBlackNode *left;
	iRedBlackNode *right;
	iRedBlackNode *parent;

	iRedBlackNode(){

	}

	iRedBlackNode(int value){
		this->value = value;
		isRedNode = true;
		left = null;
		right = null;
		parent = null;
	}
};

iRedBlackNode *insertAtRightPlace(iRedBlackNode **ptr,iRedBlackNode *currentNode,int value){
	if(*ptr == null){
		(*ptr) = new iRedBlackNode(value);
		(*ptr)->isRedNode = false;
		return null;
	}else{
		if(currentNode->value == value){
			return null;
		}
		if(currentNode->value > currentNode){
			if(currentNode->left == null){
				currentNode->left = new iRedBlackNode(value);
				currentNode->left->parent = currentNode;
				return currentNode->left;
			}else{
				return insertAtRightPlace(ptr,currentNode->left,value);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new iRedBlackNode(value);
				currentNode->right->parent = currentNode;
				return currentNode->right;
			}else{
				return insertAtRightPlace(ptr,currentNode->right,value);
			}
		}
	}
}

void rotateNodes(iRedBlackNode **root,iRedBlackNode *parent,iRedBlackNode *child){
	if(parent == null || child == null){
		return;
	}
	iRedBlackNode *grandParent = parent->parent;
	if(grandParent != null){
		child->parent = parent;
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		(*root) = child;
		child->parent = null;
	}
	parent->parent = child;
	iRedBlackNode *temp;
	if(parent->left == child){
		temp = child->right;
		parent->left = temp;
		child->right = parent;
	}else{
		temp = child->left;
		parent->right = temp;
		child->left = parent;
	}
	if(temp != null){
		temp->parent = parent;
	}
}

void rearrangeRedblackTree(iRedBlackNode **root,iRedBlackNode *currentNode){
	iRedBlackNode *grandParent = currentNode->parent->parent;
	iRedBlackNode *sibling = grandParent->left == currentNode?grandParent->right:grandParent->left;
	if(sibling->isRedNode){
		grandParent->isRedNode = !grandParent->isRedNode;
		sibling->isRedNode = !sibling->isRedNode;
		rearrangeRedblackTree(root,grandParent);
	}else{
		rotateNodes(root,grandParent,currentNode->parent);
		grandParent->isRedNode = !grandParent->isRedNode;
		currentNode->parent->isRedNode = !currentNode->parent->isRedNode;
		if(grandParent->parent == null){
			grandParent->isRedNode = false;
		}
	}

}

void insertIntoRedBlackTree(iRedBlackNode **root,int value){
	iRedBlackNode *ptrToInsertedNode = insertAtRightPlace(root,*root,value);
	if(ptrToInsertedNode == null || !ptrToInsertedNode->isRedNode){
		return;
	}
	if(!ptrToInsertedNode->parent->isRedNode){
		return;
	}
	rearrangeRedblackTree(root,ptrToInsertedNode);
}

#endif /* INSERTIONREDBLACKTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

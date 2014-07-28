/****************************************************************************************************************************************************
 *  File Name   		: redblacktree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture14\redblacktree.h
 *  Created on			: Jun 17, 2014 :: 8:37:19 PM
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

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

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

class redblacktreeutils {
private:
	iRedBlackNode *root;

	void rotateNodes(iRedBlackNode *parent,iRedBlackNode *child){
		if(parent == null || child == null){
			return;
		}
		iRedBlackNode *grandParent = parent->parent;
		if(grandParent != null){
			child->parent = grandParent;
			if(grandParent->left == parent){
				grandParent->left = child;
			}else{
				grandParent->right = child;
			}
		}else{
			this->root = child;
			child->parent = null;
		}
		parent->parent = child;
		iRedBlackNode *temp;
		if(parent->left == child){
			temp = child->left;
			parent->right = temp;
			child->left = parent;
			if(temp != null){
				temp->parent = parent;
			}
		}else{
			temp = child->right;
			parent->left = temp;
			child->right = parent;
			if(temp != null){
				temp->parent = parent;
			}
		}
	}

	void rearrangeRedBlackTree(iRedBlackNode *ptr){
		if(!ptr->parent->isRedNode){
			return;
		}
		iRedBlackNode *parent = ptr->parent;
		iRedBlackNode *grandParent = ptr->parent->parent;
		iRedBlackNode *sibling;
		sibling = grandParent->left == parent?grandParent->right:grandParent->left;
		if(sibling->isRedNode){
			parent->isRedNode = false;
			sibling->isRedNode = false;
			grandParent->isRedNode = true;
			rearrangeRedBlackTree(grandParent);
		}else{
			rotateNodes(grandParent,parent);
			parent->isRedNode = true;
			grandParent->isRedNode = false;
			if(grandParent->parent == null){
				grandParent->isRedNode = false;
			}
		}
	}

	iRedBlackNode *insertAtRightPlace(iRedBlackNode *traversalNode,int value){
		if(this->root == null){
			this->root = new iRedBlackNode(value);
			this->root->isRedNode = false;
			return null;
		}
		if(traversalNode->value == value){
			return null;
		}
		if(traversalNode->value < value){
			if(traversalNode->left == null){
				traversalNode->left = new iRedBlackNode(value);
				traversalNode->left->parent = traversalNode;
				return traversalNode->left;
			}else{
				return insertAtRightPlace(traversalNode->left,value);
			}
		}else{
			if(traversalNode->right == null){
				traversalNode->right = new iRedBlackNode(value);
				traversalNode->right->parent = traversalNode;
				return traversalNode->right;
			}else{
				return insertAtRightPlace(traversalNode->right,value);
			}
		}
	}

public:
	redblacktreeutils(){
		this->root = null;
	}

	void insert(int value){
		iRedBlackNode *ptrToInsertedNode = insertAtRightPlace(this->root,value);
		if(ptrToInsertedNode == null){
			return;
		}
		rearrangeRedBlackTree(ptrToInsertedNode);
	}
};

#endif /* REDBLACKTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: deletefrombst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture09\deletefrombst.h
 *  Created on			: Jun 4, 2014 :: 7:39:03 PM
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

#ifndef DELETEFROMBST_H_
#define DELETEFROMBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getParentForValue(itNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	itNode *traversalNode = ptr,*parentPtr = null;
	while(traversalNode != null){
		if(traversalNode->value == value){
			return parentPtr;
		}
		parentPtr = traversalNode;
		if(traversalNode->value > value){
			traversalNode = traversalNode->left;
		}else{
			traversalNode = traversalNode->right;
		}
	}
	return parentPtr;
}

itNode *getPredecessorParentBST(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *parentPtr = ptr;
	itNode *traversing = ptr->left;
	while(traversing->right != null){
		parentPtr = traversing;
		traversing = traversing->right;
	}
	return parentPtr;
}

void deleteValueFromBST(itNode **ptr,int value){
	if(*ptr == null){
		return;
	}
	itNode *ptrToParent = getParentForValue(*ptr,value);
	if(ptrToParent == null){

	}
	itNode *nodeToBeDeleted;
	if(ptrToParent->value > value){
		nodeToBeDeleted = ptrToParent->left;
	}else{
		nodeToBeDeleted = ptrToParent->right;
	}
	if(nodeToBeDeleted == null){
		return;
	}
	if(nodeToBeDeleted->left == null && nodeToBeDeleted->right == null){
		if(ptrToParent->left == nodeToBeDeleted){
			ptrToParent->left = null;
		}else{
			ptrToParent->right = null;
		}
		free(nodeToBeDeleted);
	}else if(nodeToBeDeleted->left == null || nodeToBeDeleted->right == null){
		if(ptrToParent->left == nodeToBeDeleted){
			ptrToParent->left = nodeToBeDeleted->left != null?nodeToBeDeleted->left:nodeToBeDeleted->right;
		}else{
			ptrToParent->left = nodeToBeDeleted->left != null?nodeToBeDeleted->left:nodeToBeDeleted->right;
		}
		free(nodeToBeDeleted);
	}else{
		ptrToParent = getPredecessorParentBST(nodeToBeDeleted);
		nodeToBeDeleted->value = ptrToParent->right->value;
		free(ptrToParent->right);
		ptrToParent->right = null;
	}
}

iptNode *searchPBST(iptNode *ptr,int value){
	if(ptr == null){
		return null;
	}
	if(ptr->value == value){
		return ptr;
	}
	if(ptr->value > value){
		return searchPBST(ptr->left,value);
	}else{
		return searchPBST(ptr->right,value);
	}
}

void deleteLeafNode(iptNode *ptr){
	if(ptr == null || ptr->parent == null){
		return;
	}
	if(nodeToBeDeleted->parent->left == nodeToBeDeleted){
		nodeToBeDeleted->parent->left = null;
	}else{
		nodeToBeDeleted->parent->right = null;
	}
	free(nodeToBeDeleted);
}

void deleteNodeWithOneChild(iptNode *ptr){
	if(ptr == null || ptr->parent == null){
		return;
	}
	if(nodeToBeDeleted->parent->left == nodeToBeDeleted){
		nodeToBeDeleted->parent->left = nodeToBeDeleted->left == null?nodeToBeDeleted->right:nodeToBeDeleted->left;
	}else{
		nodeToBeDeleted->parent->right = nodeToBeDeleted->left == null?nodeToBeDeleted->right:nodeToBeDeleted->left;
	}
	free(nodeToBeDeleted);
}

void deleteNodePBST(iptNode **ptr,int value){
	if(*ptr == null){
		return;
	}
	iptNode *nodeToBeDeleted = searchPBST(*ptr,value);
	if(nodeToBeDeleted->left == null && nodeToBeDeleted->right == null){
		if(nodeToBeDeleted->parent == null){
			(*ptr) = null;
			free(nodeToBeDeleted);
			return;
		}
		deleteLeafNode(nodeToBeDeleted);
	}else if(nodeToBeDeleted->left == null || nodeToBeDeleted->right == null){
		if(nodeToBeDeleted->parent == null){
			(*ptr) = nodeToBeDeleted->left != null?nodeToBeDeleted->left:nodeToBeDeleted->right;
			free(nodeToBeDeleted);
			return;
		}
		deleteNodeWithOneChild(nodeToBeDeleted);
	}else{
		iptNode *predecessor = nodeToBeDeleted->left;
		while(predecessor->right != null){
			predecessor = predecessor->right;
		}
		nodeToBeDeleted->value = predecessor->value;
		if(nodeToBeDeleted->left == null && nodeToBeDeleted->right == null){
			deleteLeafNode(predecessor);
		}else if(nodeToBeDeleted->le == null || nodeToBeDeleted->right == null){
			deleteNodeWithOneChild(predecessor);
		}
	}
}

#endif /* DELETEFROMBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

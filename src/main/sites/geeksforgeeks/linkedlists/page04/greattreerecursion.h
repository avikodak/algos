/****************************************************************************************************************************************************
 *  File Name   		: greattreerecustion.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\greattreerecustion.h
 *  Created on			: Apr 28, 2014 :: 12:35:52 PM
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
#ifndef GREATTREERECURSION_H_
#define GREATTREERECURSION_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void lFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	lFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	lFixLeftPtr(ptr->right);
}

void lFixRightPtr(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = *ptr;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	itNode *prevNode = null;
	while(traversalNode != null){
		traversalNode->right = prevNode;
		prevNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = prevNode;
}

void lConvertTreeToDLLON(itNode *ptr){
	if(ptr == null){
		return;
	}
	lFixLeftPtr(ptr);
	lFixRightPtr(&ptr);
	itNode *traversalNode = ptr;
	while(traversalNode->left != null){
		traversalNode = traversalNode->left;
	}
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode = traversalNode->right;
	}
}

void lConvertTreeToDLLInOrderONMain(itNode **root,itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	lConvertTreeToDLLInOrderONMain(root,ptr->left);
	if(prevNode == null){
		*root = prevNode;
	}else{
		prevNode->right = ptr;
		ptr->left = prevNode;
	}
	prevNode = ptr;
	lConvertTreeToDLLInOrderONMain(root,ptr->right);
}

void lConvertTreeToDLLInOrderONDriver(itNode *ptr){
	if(ptr == null){
		return;
	}
	lConvertTreeToDLLInOrderONMain(&ptr,ptr);
	itNode *traversalNode = ptr;
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode = traversalNode->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *lConvertTreeToDLLON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = lConvertTreeToDLLON2(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = lConvertTreeToDLLON2(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

#endif /* GREATTREERECURSION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

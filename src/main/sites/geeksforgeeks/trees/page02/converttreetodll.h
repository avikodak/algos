/****************************************************************************************************************************************************
 *  File Name   		: converttreetodll.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page02\converttreetodll.h
 *  Created on			: Jun 30, 2014 :: 7:26:55 PM
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

#ifndef CONVERTTREETODLL_H_
#define CONVERTTREETODLL_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void fixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	fixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	fixLeftPtr(ptr->right);
}

void fixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *currentNode = *ptr;
	while(currentNode->right != null){
		currentNode = currentNode->right;
	}
	itNode *prevNode = null;
	while(currentNode != null){
		currentNode->right = prevNode;
		prevNode = currentNode;
		currentNode = currentNode->left;
	}
	*ptr = prevNode;
}

void convertTreeToDll(itNode **ptr){
	if(*ptr == null){
		return;
	}
	fixLeftPtr(ptr);
	fixRightPtr(&ptr);
}

void convertTreeToDllONDriver(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	convertTreeToDllONDriver(ptr->left);
	if(prevNode == null){
		ptr->left = prevNode;
	}else{
		prevNode->right = ptr;
		ptr->left = prevNode;
	}
	prevNode = ptr;
	convertTreeToDllONDriver(ptr->right);
}

void convertTreeToDllON(itNode **ptr){
	if(*ptr == null){
		return;
	}
	convertTreeToDllONDriver(ptr);
	while((*ptr)->left != null){
		(*ptr) = (*ptr)->left;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *convertTreeToDllON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = convertTreeToDllON2(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = convertTreeToDllON2(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

#endif /* CONVERTTREETODLL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

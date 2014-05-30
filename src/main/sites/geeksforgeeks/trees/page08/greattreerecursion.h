/****************************************************************************************************************************************************
 *  File Name   		: greattreerecursion.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\greattreerecursion.h
 *  Created on			: Apr 23, 2014 :: 11:40:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem/
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
//Tested
void fixLeftPtrGTR(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	fixLeftPtrGTR(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	fixLeftPtrGTR(ptr->right);
}

//Tested
void fixRightPtrGTR(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = *ptr;
	itNode *prevNode = null;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	while(traversalNode != null){
		traversalNode->right = prevNode;
		prevNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = prevNode;
}

//Tested
void treeToDLL(itNode **ptr){
	if(*ptr == null){
		return;
	}
	fixLeftPtrGTR(*ptr);
	fixRightPtrGTR(ptr);
	itNode *traversalNode = *ptr;
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode = traversalNode->right;
	}
}

//Tested
void treeToDLLONMain(itNode **ptr,itNode *traversalNode){
	if(traversalNode == null){
		return;
	}
	static itNode *prevNode = NULL;
	treeToDLLONMain(ptr,traversalNode->left);
	if(prevNode == null){
		(*ptr)->left = prevNode;
		(*ptr) = traversalNode;
	}else{
		traversalNode->left = prevNode;
		prevNode->right = traversalNode;
	}
	prevNode = traversalNode;
	treeToDLLONMain(ptr,traversalNode->right);
}

//Tested
void treeToDLLON(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeToDLLONMain(&ptr,ptr);
	itNode *traversalNode = ptr;
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode = traversalNode->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *treeToDLLON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubtree = treeToDLLON2Main(ptr->left);
		while(leftSubtree->right != null){
			leftSubtree = leftSubtree->right;
		}
		leftSubtree->right = ptr;
		ptr->left = leftSubtree;
	}
	if(ptr->right != null){
		itNode *rightSubtree = treeToDLLON2Main(ptr->right);
		while(rightSubtree->left != null){
			rightSubtree = rightSubtree->left;
		}
		rightSubtree->left = ptr;
		ptr->right = rightSubtree;
	}
	return ptr;
}

//Tested
void treeToDLLON2(itNode **ptr){
	if(*ptr == null){
		return;
	}
	treeToDLLON2Main(*ptr);
	itNode *traversalNode = *ptr;
	while(traversalNode->left != null){
		traversalNode = traversalNode->left;
	}
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode = traversalNode->right;
	}
}

#endif /* GREATTREERECURSION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: inorderwithoutrecursion.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\inorderwithoutrecursion.h
 *  Created on			: Apr 28, 2014 :: 2:08:31 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
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

#ifndef INORDERWITHOUTRECURSION_H_
#define INORDERWITHOUTRECURSION_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void inOrderIterativeON(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

//Tested
void ioiFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	ioiFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	ioiFixLeftPtr(ptr->right);
}

//Tested
void ioiFixRightPtr(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = *ptr;
	static itNode *prevNode = null;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	while(traversalNode != null){
		traversalNode->right = prevNode;
		prevNode = traversalNode;
		traversalNode= traversalNode->left;
	}
	(*ptr) = prevNode;
}

//Tested
void ioiInOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	ioiFixLeftPtr(ptr);
	ioiFixRightPtr(&ptr);
	itNode *traversalNode = ptr;
	while(traversalNode != null){
		printf("%d\t",traversalNode->value);
		traversalNode  = traversalNode->right;
	}
}

//Tested
void morrisInOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = ptr,*temp;
	while(traversalNode != null){
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				printf("%d\t",traversalNode->value);
				traversalNode = traversalNode->right;
			}
		}else{
			printf("%d\t",traversalNode->value);
			traversalNode = traversalNode->right;
		}
	}
}

#endif /* INORDERWITHOUTRECURSION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

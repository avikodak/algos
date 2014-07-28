/****************************************************************************************************************************************************
 *  File Name   		: inorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture07\inorder.h
 *  Created on			: Jun 3, 2014 :: 9:07:07 PM
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

#ifndef INORDER_H_
#define INORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void inorderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	inorderTraversal(ptr->left);
	printf("%d\t",ptr->value);
	inorderTraversal(ptr->right);
}

void inorderTraversalIterative(itNode *ptr){
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

void morrisInOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

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
	itNode *traversingNode = *ptr;
	itNode *prevNode = null;
	while(traversingNode->right != null){
		traversingNode = traversingNode->right;
	}
	while(traversingNode != null){
		traversingNode->right = prevNode;
		prevNode = traversingNode;
		traversingNode = traversingNode->left;
	}
	*ptr = prevNode;
}

void inorderTraversalDllConversionByFixingPtrs(itNode *ptr){
	if(ptr == null){
		return;
	}
	fixLeftPtr(ptr);
	fixRightPtr(&ptr);
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

void inorderTraversalByTreeToDllConversionON(itNode **root,itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	inorderTraversalByTreeToDllConversionON(root,ptr->left);
	if(prevNode == null){
		*root = ptr;
	}else{
		prevNode->right = ptr;
		ptr->left = prevNode;
	}
	prevNode = ptr;
	inorderTraversalByTreeToDllConversionON(root,ptr->right);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void inorderTraversalByTreeToDllConversionON2Main(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left != null){
		itNode *leftSubTree = inOrderTraversalByTreeToDLLON2Main(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = inOrderTraversalByTreeToDLLON2Main(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

void inorderTraversalByTreeToDllConversionON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	inorderTraversalByTreeToDllConversionON2Main(ptr);
	while(ptr->left !=  null){
		ptr = ptr->left;
	}
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

#endif /* INORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

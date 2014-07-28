/****************************************************************************************************************************************************
 *  File Name   		: mergetwobalancedbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\mergetwobalancedbst.h
 *  Created on			: May 25, 2014 :: 10:50:18 AM
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

#ifndef MERGETWOBALANCEDBST_H_
#define MERGETWOBALANCEDBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

itNode *constructBalancedTreeFromSortedVector(vector<int> sortedVector,unsigned int counter){
	if(counter >= sortedVector.size()){
		return null;
	}
	itNode *root = new itNode(sortedVector[counter]);
	root->left = constructBalancedTreeFromSortedVector(sortedVector,2*counter+1);
	root->right = constructBalancedTreeFromSortedVector(sortedVector,2*counter+2);
	return root;
}

itNode *mergeTwoBalancedBSTON(itNode *firstBST,itNode *secondBST){
	if(firstBST == null && secondBST == null){
		return null;
	}
	if(firstBST == null || secondBST == null){
		return firstBST == null?secondBST:firstBST;
	}
	vector<int> inOrderFirstBST,inOrderSecondBST;
	treeutils *utils = new treeutils();
	utils->setVectorWithInOrderValues(firstBST,inOrderFirstBST);
	utils->setVectorWithInOrderValues(secondBST,inOrderSecondBST);
	vector<int> mergedSortArray;
	unsigned int firstCounter = 0,secondCounter = 0;
	while(firstCounter < inOrderFirstBST.size() && secondCounter < inOrderSecondBST.size()){
		if(inOrderFirstBST[firstCounter] == inOrderSecondBST[secondCounter]){
			mergedSortArray.push_back(inOrderFirstBST[firstCounter++]);
			mergedSortArray.push_back(inOrderSecondBST[secondCounter++]);
		}else{
			if(inOrderFirstBST[firstCounter] < inOrderSecondBST[secondCounter]){
				mergedSortArray.push_back(inOrderFirstBST[firstCounter++]);
			}else{
				mergedSortArray.push_back(inOrderSecondBST[secondCounter++]);
			}
		}
	}
	return constructBalancedTreeFromSortedVector(mergedSortArray,0);
}

void mbstFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevPtr = null;
	fixLeftPtr(ptr->left);
	ptr->left = prevPtr;
	prevPtr = ptr;
	fixLeftPtr(ptr->right);
}

void mbstFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *traversingNode = *ptr;
	while(traversingNode->right != null){
		traversingNode = traversingNode->right;
	}
	itNode *prevNode = NULL;
	while(traversingNode != null){
		traversingNode->right = prevNode;
		prevNode = traversingNode;
		traversingNode = traversingNode->left;
	}
	(*ptr) =  prevNode;
}

void convertTreeToDLL(itNode **ptr){
	if(ptr == null){
		return;
	}
	mbstFixLeftPtr(*ptr);
	mbstFixRightPtr(ptr);
}

itNode *mergeTwoBalancedBST(itNode *firstBSTPtr,itNode *secondBSTPtr){
	if(firstBSTPtr == null && secondBSTPtr == null){
		return null;
	}
	if(firstBSTPtr == null || secondBSTPtr == null){
		return firstBSTPtr == null?secondBSTPtr:firstBSTPtr;
	}
	convertTreeToDLL(&firstBSTPtr);
	convertTreeToDLL(&secondBSTPtr);
}

void mergeTwoBalancedBSTInOrderON(itNode **root,itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = NULL;
	mergeTwoBalancedBSTInOrderON(root,ptr->left);
	if(prevNode == null){
		*root = ptr;
	}else{
		prevNode->right = ptr;
		ptr->left = prevNode;
	}
	prevNode = ptr;
	mergeTwoBalancedBSTInOrderON(root,ptr->right);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void mergeTwoBalancedBST(itNode **firstBST,itNode *secondBST){
	if(*firstBST == null && secondBST == null){
		return;
	}
	if(*firstBST == null || secondBST == null){
		if(*firstBST == null){
			*firstBST =  secondBST;
		}
	}
	itNode *currentNode = *firstBST;
	while(currentNode != null){
		if(currentNode->value >= secondBST->value){
			if(currentNode->left == null){
				currentNode->left = new itNode(secondBST->value);
				break;
			}else{
				currentNode = currentNode->left;
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new itNode(secondBST->value);
				break;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
	mergeTwoBalancedBST(firstBST,secondBST->left);
	mergeTwoBalancedBST(firstBST,secondBST->right);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *mergeTwoBalancedByDLLConversionBSTON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = mergeTwoBalancedByDLLConversionBSTON2(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		ptr->left = leftSubTree;
		leftSubTree->right = ptr;
	}
	if(ptr->right != null){
		itNode *rightSubTree = mergeTwoBalancedByDLLConversionBSTON2(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		ptr->right = rightSubTree;
		rightSubTree->left = ptr;
	}
	return ptr;
}

#endif /* MERGETWOBALANCEDBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

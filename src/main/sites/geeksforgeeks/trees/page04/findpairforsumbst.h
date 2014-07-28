/****************************************************************************************************************************************************
 *  File Name   		: findpairforsumbst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\findpairforsumbst.h
 *  Created on			: May 28, 2014 :: 12:47:24 PM
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

#ifndef FINDPAIRFORSUMBST_H_
#define FINDPAIRFORSUMBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

int *findPairForSumBSTOptimisedON(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	stack<itNode *> inorderAuxSpace,revInorderAuxSpace;
	itNode *currentInorderNode,*currentRevInorderNode,*inorderNode,*revInorderNode;
	bool flagInorder = true,flagRevInorder = true;
	while(!inorderAuxSpace.empty() || !revInorderAuxSpace.empty() || currentInorderNode != null || currentRevInorderNode != null){
		inorderNode = null;
		revInorderNode = null;
		while(flagInorder && (!inorderAuxSpace.empty() || currentInorderNode != null)){
			if(currentInorderNode != null){
				inorderAuxSpace.push(currentInorderNode);
				currentInorderNode = currentInorderNode->left;
			}else{
				currentInorderNode = inorderAuxSpace.top();
				inorderNode = currentInorderNode;
				inorderAuxSpace.pop();
				currentInorderNode = currentInorderNode->right;
				flagInorder = false;
				break;
			}
		}
		while(flagRevInorder && (!revInorderAuxSpace.empty() || currentRevInorderNode != null)){
			if(currentRevInorderNode != null){
				inorderAuxSpace.push(currentRevInorderNode);
				currentRevInorderNode = currentRevInorderNode->right;
			}else{
				currentRevInorderNode = revInorderAuxSpace.top();
				revInorderNode = currentRevInorderNode;
				revInorderAuxSpace.pop();
				currentRevInorderNode = currentRevInorderNode->left;
				flagRevInorder = false;
				break;
			}
		}
		if(inorderNode == null || revInorderNode == null || inorderNode ==  revInorderNode){
			return false;
		}
		if(inorderNode->value + revInorderNode->value == sum){
			return true;
		}
		if(inorderNode->value + revInorderNode->value < sum){
			flagInorder = true;
		}else{
			flagRevInorder = true;
		}
	}
	return false;
}

int *findPairForSumBSTON(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	vector<int> inorderValues;
	treeutils *utils  = new treeutils();
	utils->setVectorWithInOrderValues(ptr,inorderValues);
	unsigned int startIndex=0,endIndex = inorderValues.size();
	int currentSum;
	while(startIndex < endIndex){
		currentSum = inorderValues[startIndex] + inorderValues[endIndex];
		if(currentSum == sum){
			int *requiredPair = (int *)calloc(2,sizeof(int));
			requiredPair[0] = inorderValues[startIndex];
			requiredPair[1] = inorderValues[endIndex];
			return requiredPair;
		}
		if(currentSum > sum){
			endIndex--;
		}else{
			startIndex++;
		}
	}
	return null;

}

int *findPairForSumDLL(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	itNode *frontCrawler = ptr,*rearCrawler = ptr;
	while(rearCrawler->right != null){
		rearCrawler = rearCrawler->right;
	}
	int currentSum;
	while(frontCrawler != rearCrawler){
		currentSum = frontCrawler->value + rearCrawler->value;
		if(currentSum == sum){
			int *result = (int *)calloc(2,sizeof(int));
			result[0] = frontCrawler->value;
			result[1] = rearCrawler->value;
			return result;
		}
		if(currentSum > sum){
			rearCrawler = rearCrawler->left;
		}else{
			frontCrawler = frontCrawler->right;
		}
	}
	return null;
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
	itNode *traversingNode = *ptr,*prevNode = null;
	while(traversingNode->right != null){
		traversingNode = traversingNode->right;
	}
	while(traversingNode != null){
		traversingNode->right = prevNode;
		prevNode = traversingNode;
		traversingNode = traversingNode->left;
	}
}

int *findPairByTreeToDllON(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	fixLeftPtr(ptr);
	fixRightPtr(&ptr);
	return findPairForSumDLL(ptr,sum);
}

void convertTreeToDLLMainON(itNode **root,itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	convertTreeToDLLMainON(root,ptr->left);
	if(prevNode == null){
		*root = ptr;
		root->left = null;
	}else{
		ptr->left = prevNode;
		prevNode->right = ptr;
	}
	prevNode = ptr;
	convertTreeToDLLMainON(root,ptr->right);
}

int *findPairForSummTreeToDLLON(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	convertTreeToDLLMainON(&ptr,ptr);
	return findPairForSumDLL(ptr,sum);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findPairForSumBSTONLOGN(itNode *ptr,int sum){
	if(ptr == null){
		return;
	}
	vector<int> preorderValues;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderValues(ptr,preorderValues);
	for(unsigned int counter = 0;counter < preorderValues.size();counter++){
		if(utils->searchForNodeBST(ptr,sum-preorderValues[counter])){
			int *result = (int *)calloc(2,sizeof(int));
			result[0] = preorderValues[counter];
			result[1] = sum - preorderValues[counter];
			return result;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *convertTreeToDLLON2(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = convertTreeToDLLON2(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = convertTreeToDLLON2(ptr->right);
		while(rightSubTree != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

int *findPairTreeDllConversionON2(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	convertTreeToDLLON2(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	return findPairForSumDLL(ptr,sum);
}

int *findPairForSumBSTON2(itNode *ptr,int sum){
	if(ptr == null){
		return null;
	}
	vector<int> preOrderValues;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderValues(ptr,preOrderValues);
	for(unsigned int outerCounter = 0;outerCounter < preOrderValues.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < preOrderValues.size();innerCounter++){
			if(preOrderValues[outerCounter] + preOrderValues[innerCounter] == sum){
				int *result = (int *)calloc(2,sizeof(int));
				result[0] = preOrderValues[outerCounter];
				result[1] = preOrderValues[innerCounter];
				return result;
			}
		}
	}
	return null;
}

#endif /* FINDPAIRFORSUMBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

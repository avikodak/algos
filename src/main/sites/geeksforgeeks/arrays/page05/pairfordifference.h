
/****************************************************************************************************************************************************
 *  File Name   		: pairfordifference.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\pairfordifference.h
 *  Created on			: Jun 30, 2014 :: 11:34:13 PM
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

#ifndef PAIRFORDIFFERENCE_H_
#define PAIRFORDIFFERENCE_H_

/****************************************************************************************************************************************************/
/* 																O(N) Algorithm 																    	*/
/****************************************************************************************************************************************************/
int *findPairON(vector<int> userInput,int difference){
	if(userInput.size() == 0){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			frequencyMap[userInput[counter]] = 1;
		}else{
			frequencyMap[userInput[counter]] += 1;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(difference - userInput[counter])) != frequencyMap.end()){
			int *result = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = itToFrequencyMap->first;
			return result;
		}
		if((itToFrequencyMap = frequencyMap.find(userInput[counter] - difference)) != frequencyMap.end()){
			int *result  = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = itToFrequencyMap->first;
			return result;
		}
	}
	return null;
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findAPairForDifference(vector<int> userInput,int difference){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 1,rearCrawler = 0;
	int currentDifference;
	while(rearCrawler < userInput.size() && frontCrawler < userInput.size()){
		if(rearCrawler == frontCrawler){
			frontCrawler += 1;
		}else{
			currentDifference = userInput[frontCrawler] - userInput[rearCrawler];
			if(currentDifference == difference){
				int *result = (int *)calloc(2,sizeof(int));
				result[0] = userInput[frontCrawler];
				result[1] = userInput[rearCrawler];
				return result;
			}
			if(currentDifference > difference){
				rearCrawler++;
			}else{
				frontCrawler++;
			}
		}
	}
}

void getFBSTFromVector(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int counter){
	if(userInput.size() == 0 || counter >= userInput.size()){
		return;
	}
	if(*root == null){
		*root = new iftNode(userInput[counter]);
		getFBSTFromVector(root,*root,userInput,counter+1);
	}else{
		if(currentNode->value == userInput[counter]){
			currentNode->frequency += 1;
			getFBSTFromVector(root,*root,userInput,counter+1);
		}else{
			if(currentNode->value > userInput[counter]){
				if(currentNode->left == null){
					currentNode->left = new iftNode(userInput[counter]);
					getFBSTFromVector(root,*root,userInput,counter+1);
				}else{
					getFBSTFromVector(root,currentNode->left,userInput,counter);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new iftNode(userInput[counter]);
					getFBSTFromVector(root,*root,userInput,counter+1);
				}else{
					getFBSTFromVector(root,currentNode->right,userInput,counter+1);
				}
			}
		}
	}
}

iftNode *searchInBST(iftNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	if(ptr->value == key){
		return ptr;
	}
	if(ptr->value > key){
		return searchInBST(ptr->left,key);
	}else{
		return searchInBST(ptr->right,key);
	}
}

int *getPairBSTONLOGN(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return null;
	}
	iftNode *root = null,*ptrToKey;
	getFBSTFromVector(&root,root,userInput,0);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		ptrToKey = searchInBST(root,key+userInput[counter]);
		if(ptrToKey != null){
			int *result[2] = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = ptrToKey->value;
			return result;
		}
		ptrToKey = searchInBST(root,userInput[counter]-key);
		if(ptrToKey != null){
			int *result[2] = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = ptrToKey->value;
			return result;
		}
	}
	return null;
}

ifavltNode *searchForValueFAVL(ifavltNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	if(ptr->value == key){
		return ptr;
	}
	if(ptr->value > key){
		return searchForValue(ptr->left,key);
	}else{
		return searchForValue(ptr->right,key);
	}
}

void rotateIfAvlNodes(ifavltNode **root,ifavltNode *parent,ifavltNode *child){
	if(parent == null || child == null){
		return;
	}
	ifavltNode *grandParent = parent->parent;
	if(grandParent != null){
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		(*root) = child;
	}
	parent->parent = child;
	child->parent = grandParent;
	ifavltNode *temp = null;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = temp;
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
	if(temp != null){
		temp->parent = parent;
	}
}

ifavltNode *insertAtRightPlace(ifavltNode **root,ifavltNode *currentNode,int userInput){
	if(*root == null){
		*root = new ifavltNode(userInput);
		return null;
	}
	if(currentNode->value == userInput){
		currentNode->frequency += 1;
		return null;
	}
	if(currentNode->value > userInput){
		if(currentNode->left == null){
			currentNode->left = new ifavltNode(userInput);
			return currentNode->left;
		}else{
			return insertAtRightPlace(root,currentNode->left,userInput);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifavltNode(userInput);
			return currentNode->right;
		}else{
			return insertAtRightPlace(root,currentNode->right,userInput);
		}
	}
}

void insertIntoAvlTree(ifavltNode **root,int userInput){
	ifavltNode *ptrToInsertedNode = insertAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	unsigned int leftHeight,rightHeight;
	ifavltNode *z = ptrToInsertedNode,*y,*x;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateIfAvlNodes(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
			}else{
				rotateIfAvlNodes(root,y,x);
				rotateIfAvlNodes(root,z,x);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height) + 1;
			}
			return;
		}
		z->height = max(leftHeight,rightHeight) + 1;
		z = z->parent;
	}
}

int *getPairAVLONLOGN(vector<int> userInput,int key){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	ifavltNode *root = null,ptrToKey;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertIntoAvlTree(&root,userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		ptrToKey = searchForValueFAVL(root,key+userInput[counter]);
		if(ptrToKey != null){
			int *result[2] = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = ptrToKey->value;
			return result;
		}
		ptrToKey = searchForValueFAVL(root,userInput[counter]-key);
		if(ptrToKey != null){
			int *result[2] = (int *)calloc(2,sizeof(int));
			result[0] = userInput[counter];
			result[1] = ptrToKey->value;
			return result;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findPairForDifferenceON2(vector<int> userInput,int difference){
	if(userInput.size() == 0){
		return null;
	}
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler-1;innerCrawler< userInput.size();innerCrawler++){
			if(abs(userInput[innerCrawler] - userInput[outerCrawler]) == difference){
				int *result = (int *)calloc(2,sizeof(int));
				result[0] = userInput[outerCrawler];
				result[1] = userInput[innerCrawler];
				return result;
			}
		}
	}
	return null;
}

#endif /* PAIRFORDIFFERENCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

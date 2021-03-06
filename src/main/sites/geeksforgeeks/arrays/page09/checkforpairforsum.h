/****************************************************************************************************************************************************
 *  File Name   		: checkforpairforsum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\checkforpairforsum.h
 *  Created on			: Apr 13, 2014 :: 10:36:44 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef CHECKFORPAIRFORSUM_H_
#define CHECKFORPAIRFORSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *getPairOfNodesForGivenSumON(vector<int> userInput,int requiredSum){
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
		if((itToFrequencyMap = frequencyMap.find(requiredSum - userInput[counter])) != frequencyMap.end()){
			int *requiredPair = (int *)calloc(2,sizeof(int));
			requiredPair[0] = userInput[counter];
			requiredPair[1] = requiredSum-userInput[counter];
			return requiredPair;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *getPairOfNodesForGivenSumONLOGN(vector<int> userInput,int requiredSum){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int currentSum;
	while(frontCrawler != rearCrawler){
		currentSum = userInput[frontCrawler] + userInput[rearCrawler];
		if(currentSum == requiredSum){
			int *requiredPair = (int *)calloc(2,sizeof(int));
			requiredPair[0] = userInput[frontCrawler];
			requiredPair[1] = userInput[rearCrawler];
			return requiredPair;
		}
		if(currentSum > requiredSum){
			rearCrawler--;
		}else{
			frontCrawler++;
		}
	}
	return null;
}

//Tested
bool isNodePresentInTree(iftNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	if(ptr->value > value){
		return isNodePresentInTree(ptr->left,value);
	}else{
		return isNodePresentInTree(ptr->right,value);
	}
}

//Tested
int *getPairOfNodesForGivenSumONLOGNBST(vector<int> userInput,int requiredSum){
	if(userInput.size() == 0){
		return null;
	}
	treeutils *utils = new treeutils();
	iftNode *rootFBST = utils->getFBSTreeFromVector(userInput);
	hash_map<int,bool> flags;
	hash_map<int,bool>::iterator itToFlags;
	int key;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFlags = flags.find(userInput[counter])) == flags.end()){
			key = requiredSum - userInput[counter];
			if(isNodePresentInTree(rootFBST,key)){
				int *requiredPair = (int *)calloc(2,sizeof(int));
				requiredPair[0] = userInput[counter];
				requiredPair[1] = key;
				return requiredPair;
			}
			flags.insert(pair<int,bool>(userInput[counter],true));
		}
	}
	return null;
}

void rotateIFAvlTNode(ifavltNode **root,ifavltNode *parent,ifavltNode *child){
	if(parent == null || child == null){
		return;
	}
	ifavltNode *grandParent = parent->parent;
	if(grandParent != null){
		if(grandParent->left == parent){
			if(grandParent->left == parent){
				grandParent->left = child;
			}else{
				grandParent->right = child;
			}
		}else{
			(*root) = child;
		}
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
		(*root) = new ifavltNode(userInput);
		return null;
	}else{
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
}

void insertIntoFAVLTree(ifavltNode **root,int userInput){
	ifavltNode *ptrToInsertedNode = insertAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	ifavltNode *z = ptrToInsertedNode,*y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateIFAvlTNode(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
			}else{
				rotateIFAvlTNode(root,y,x);
				rotateIFAvlTNode(root,z,x);
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

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *getPairOfNodesForGivenSumON2(vector<int> userInput,int requiredSum){
	if(userInput.size() == 0){
		return null;
	}
	unsigned int outerCrawler,innerCrawler;
	for(outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler]+userInput[innerCrawler] == requiredSum){
				int *requiredPair = (int *)calloc(2,sizeof(int));
				requiredPair[0] = userInput[outerCrawler];
				requiredPair[1] = userInput[innerCrawler];
				return requiredPair;
			}
		}
	}
	return null;
}

#endif /* CHECKFORPAIRFORSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

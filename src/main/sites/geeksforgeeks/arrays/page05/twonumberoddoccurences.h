/****************************************************************************************************************************************************
 *  File Name   		: twonumberoddoccurences.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\twonumberoddoccurences.h
 *  Created on			: Jul 1, 2014 :: 12:15:49 AM
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
#define BIT_STATUS(number,position) (number & 1 << position)

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWONUMBERODDOCCURENCES_H_
#define TWONUMBERODDOCCURENCES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int *getTwoOddFrequencyNumberXOR(vector<int> userInput){
	if(userInput.size() < 3){
		return null;
	}
	int XORResult = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		XORResult ^= userInput[counter];
	}
	unsigned int rightMostBitSet =  log(XORResult & -XORResult) + 1;
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int tempForSwap;
	while(frontCrawler < rearCrawler){
		while(!(userInput[frontCrawler] & 1 << rightMostBitSet)){
			frontCrawler++;
		}
		while(userInput[rearCrawler] & 1 << rightMostBitSet){
			rearCrawler--;
		}
		if(frontCrawler < rearCrawler){
			tempForSwap = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[rearCrawler];
			userInput[rearCrawler] = temp;
		}
	}
	int *result = (int *)calloc(2,sizeof(int));
	XORResult = 0;
	for(unsigned int counter = 0;counter <= rearCrawler;counter++){
		XORResult ^= userInput[counter];
	}
	result[0] = XORResult;
	XORResult = 0;
	for(unsigned int counter = frontCrawler;counter<userInput.size();counter++){
		XORResult ^= userInput[counter];
	}
	result[1] = XORResult;
	return result;
}

int *getTwoOddFrequencyNumbers(vector<int> userInput){
	if(userInput.size() < 3){
		return null;
	}
	hash_map<int,unsigned int> frequencyTable;
	hash_map<int,unsigned int>::iterator itToFrequencyTable;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyTable = frequencyTable.find(userInput[counter])) == frequencyTable.end()){
			frequencyTable[userInput[counter]] = 1;
		}else{
			frequencyTable[userInput[counter]] += 1;
		}
	}
	int *result = (int *)calloc(2,sizeof(int));
	int fillCounter = 0;
	for(itToFrequencyTable = frequencyTable.begin();itToFrequencyTable < frequencyTable.end();itToFrequencyTable++){
		if(itToFrequencyTable->second & 1){
			result[fillCounter++] = itToFrequencyTable->first;
			if(fillCounter == 2){
				return result;
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

void getFBSTFromVectorMain(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int counter){
	if(userInput.size() == 0 || counter >= userInput.size()){
		return;
	}
	if(*root == null){
		(*root) = new iftNode(userInput[counter]);
		getFBSTFromVectorMain(root,*root,userInput,counter+1);
	}else{
		if(currentNode->value == userInput[counter]){
			currentNode->frequency += 1;
			getFBSTFromVectorMain(root,*root,userInput,counter);
		}
		if(currentNode->value > userInput[counter]){
			if(currentNode->left == null){
				currentNode->left = new iftNode(userInput[counter]);
				getFBSTFromVectorMain(root,*root,userInput,counter+1);
			}else{
				getFBSTFromVectorMain(root,currentNode->left,userInput,counter);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new iftNode(userInput[counter]);
				getFBSTFromVectorMain(root,*root,userInput,counter+1);
			}else{
				getFBSTFromVectorMain(root,currentNode->right,userInput,counter);
			}
		}
	}
}

void rotateNodeFAVLTree(ifavltNode **root,ifavltNode *parent,ifavltNode *child){
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
	child->parent = grandParent;
	parent->parent = child;
	ifavltNode *temp;
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
			currentNode->left->parent = currentNode;
			return currentNode->left;
		}else{
			return insertAtRightPlace(root,currentNode->left,userInput);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifavltNode(userInput);
			currentNode->right->parent = currentNode;
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
	ifavltNode *z = ptrToInsertedNode,*y,*x;
	unsigned int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateNodeFAVLTree(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
			}else{
				rotateNodeFAVLTree(root,y,x);
				rotateNodeFAVLTree(root,z,x);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height)+1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height)+1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height)+1;
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
int *getTwoOddFrequencyNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	unsigned int frequency,fillCounter = 0;
	int *result = (int *)calloc(2,sizeof(int));
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequency = 0;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequency += 1;
			}
		}
		if(frequency&1){
			if(fillCounter == 0){
				result[fillCounter++] = userInput[outerCrawler];
			}else{
				if(result[0] == userInput[outerCrawler]){
					continue;
				}
				result[fillCounter++] = userInput[outerCrawler];
				return result;
			}
		}
	}
	return null;
}
#endif /* TWONUMBERODDOCCURENCES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: removeallduplicates.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page04\removeallduplicates.h
 *  Created on			: Jun 27, 2014 :: 8:35:01 PM
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

#ifndef REMOVEALLDUPLICATES_H_
#define REMOVEALLDUPLICATES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void removeDuplicateChar(char **userInput){
	if(userInput == null){
		return;
	}
	hash_map<char,unsigned int> charFrequency;
	hash_map<char,unsigned int>::iterator itToCharFrequency;
	char *traversingPtr = *userInput;
	while(traversingPtr != null){
		if((itToCharFrequency = charFrequency.find((char)(*traversingPtr))) != charFrequency.end()){
			charFrequency[(char)(*traversingPtr)] += 1;
		}else{
			charFrequency[(char)(*traversingPtr)] = 1;
		}
	}
	traversingPtr = *userInput;
	bool firstNonRepeatingFound = false;
	while(traversingPtr+1 != null){
		itToCharFrequency =  charFrequency.find((char)(*traversingPtr));
		if(itToCharFrequency->second > 1){
			if(!firstNonRepeatingFound){

			}
		}else{
			firstNonRepeatingFound = true;
		}
		traversingPtr = traversingPtr++;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void getCfbstFromChar(cftNode **root,cftNode *currentNode,char *ptrToUserInput){
	if(ptrToUserInput == null){
		return;
	}
	char currentChar = *ptrToUserInput;
	if(*root == null){
		(*root) = new cftNode(currentChar);
		getCfbstFromChar(root,*root,ptrToUserInput+1);
	}else{
		if(currentNode->ch == currentChar){
			currentNode->frequency += 1;
			getCfbstFromChar(root,*root,ptrToUserInput+1);
		}else{
			if(currentNode->ch > currentChar){
				if(currentNode->left == null){
					currentNode->left = new cftNode(currentChar);
					getCfbstFromChar(root,*root,ptrToUserInput+1);
				}else{
					getCfbstFromChar(root,currentNode->left,ptrToUserInput+1);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new cftNode(currentChar);
					getCfbstFromChar(root,*root,ptrToUserInput+1);
				}else{
					getCfbstFromChar(root,currentNode->right,ptrToUserInput+1);
				}
			}
		}
	}
}

cftNode *searchForCharCfbst(cftNode *ptr,char userInput){
	if(ptr == null){
		return null;
	}
	if(ptr->ch == userInput){
		return ptr;
	}
	if(ptr->ch > userInput){
		return searchForCharCfbst(ptr->left,userInput);
	}else{
		return searchForCharCfbst(ptr->right,userInput);
	}
}

struct cfavltNode{
	char ch;
	unsigned int frequency;
	unsigned int height;
	cfavltNode *parent;
	cfavltNode *left;
	cfavltNode *right;

	cfavltNode(){

	}

	cfavltNode(char userInput){
		ch = userInput;
		frequency = 1;
		height = 1;
		parent = null;
		left = null;
		right = null;
	}
};

cfavltNode *insertAtRightPlaceCfavl(cfavltNode **root,cfavltNode *currentNode,char userInput){
	if(userInput == '\0'){
		return null;
	}
	if(*root == null){
		(*root) = new cfavltNode(userInput);
		return null;
	}else{
		if(currentNode->ch == userInput){
			currentNode->frequency += 1;
			return null;
		}else{
			if(currentNode->ch > userInput){
				if(currentNode->left == null){
					currentNode->left = new cfavltNode(userInput);
					return currentNode;
				}else{
					return insertAtRightPlaceCfavl(root,currentNode->left,userInput);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new cfavltNode(userInput);
					return currentNode;
				}else{
					return insertAtRightPlaceCfavl(root,currentNode->right,userInput);
				}
			}
		}
	}
}

void rotateCftNodes(cfavltNode **root,cfavltNode *parent,cfavltNode *child){
	cfavltNode *grandParent = parent->parent;
	if(grandParent != null){

	}else{
		*root = grandParent;
	}
	parent->parent = child;
	child->parent = grandParent;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* REMOVEALLDUPLICATES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: oddnumberoftimes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\oddnumberoftimes.h
 *  Created on			: Apr 15, 2014 :: 2:24:40 AM
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

#ifndef ODDNUMBEROFTIMES_H_
#define ODDNUMBEROFTIMES_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getNumberOccuringOddNumberOfTimesXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int xorResult = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		xorResult ^= userInput[counter];
	}
	return xorResult;
}

//Tested
int getNumberOccuringOddNumberOfTimesHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second&1){
			return itToFrequencyMap->first;
		}
	}
	return INT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getNumberOccuringOddNumberTimesONLOGNSorting(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0,frequency;
	while(counter < userInput.size()){
		frequency = 1;
		while(counter+1 < userInput.size() && userInput[counter] == userInput[counter+1]){
			frequency += 1;
			counter++;
		}
		if(frequency&1){
			return userInput[counter];
		}
		counter++;
	}
	return INT_MAX;
}

//Tested
int getNumberOccuringOddNumberOfTimesONLOGNBinarySearch(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	vector<int>::iterator lowerIndex,upperIndex;
	unsigned int lowerIndexVal,upperIndexVal;
	for(unsigned int counter = 0;counter < userInput.size();){
		lowerIndex = lower_bound(userInput.begin(),userInput.end(),userInput[counter]);
		upperIndex = upper_bound(userInput.begin(),userInput.end(),userInput[counter]);
		lowerIndexVal = lowerIndex - userInput.begin();
		upperIndexVal = upperIndex - userInput.begin();
		if((upperIndexVal-lowerIndexVal)&1){
			return userInput[counter];
		}
		counter += upperIndexVal - lowerIndexVal;
	}
	return INT_MAX;
}

//Tested
iftNode *getANodeWhoseFrequencyFBSTInOrder(iftNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->frequency&1){
		return ptr;
	}
	iftNode *leftSubTreeResult = getANodeWhoseFrequencyFBSTInOrder(ptr->left);
	if(leftSubTreeResult != null){
		return leftSubTreeResult;
	}
	return getANodeWhoseFrequencyFBSTInOrder(ptr->right);
}

//Tested
int getNumberOccuringOddNumberOfTimesONLOGNBST(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	treeutils *utils = new treeutils();
	iftNode *rootBST = utils->getFBSTreeFromVector(userInput);
	iftNode *result = getANodeWhoseFrequencyFBSTInOrder(rootBST);
	return result == null?INT_MAX:result->value;
}

void oRotateNodes(ifavltNode *parent,ifavltNode *child){
	if(parent == null || child == null){
		return;
	}
	ifavltNode *grandParent = parent->parent;
	child->parent = grandParent;
	if(grandParent != null){
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}
	parent->parent = child;
	ifavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		parent->left = temp;
		child->right = parent;
		if(temp != null){
			temp->parent = parent;
		}
	}else{
		temp = child->left;
		parent->right = temp;
		child->left = parent;
		if(temp != null){
			temp->parent = parent;
		}
	}
}

ifavltNode *insertAtRightPlaceOdd(ifavltNode **root,ifavltNode *currentNode,int userInput){
	if(*root == null){
		*root = new ifavltNode(userInput);
		return null;
	}else{
		if(currentNode->value == userInput){
			currentNode->frequency += 1;
			return null;
		}
		if(currentNode->value > userInput){
			if(currentNode->left == null){
				currentNode->left = new ifavltNode(userInput);
				currentNode->left->parent = currentNode;
				return currentNode;
			}else{
				return insertAtRightPlaceOdd(root,currentNode->left,userInput);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new ifavltNode(userInput);
				currentNode->right->parent  = currentNode;
				return currentNode;
			}else{
				return insertAtRightPlaceOdd(root,currentNode->right,userInput);
			}
		}
	}
}

void insertNodeIntoAvlTree(ifavltNode **root,int userInput){
	ifavltNode *ptrToInsertedNode = insertAtRightPlaceOdd(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	ifavltNode *z,*y,*x;
	z = ptrToInsertedNode;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1	){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)|| (z->right == y && y->right == x)){
				oRotateNodes(z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
			}else{
				oRotateNodes(y,x);
				oRotateNodes(z,x);
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height) + 1;
			}
			return;
		}
		z->height = max(leftHeight,rightHeight)+1;
		z = z->parent;
	}
}

int getOddManOutInorder(ifavltNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	int leftResult = getOddManOutInorder(ptr->left);
	if(leftResult != INT_MIN){
		return leftResult;
	}
	return getOddManOutInorder(ptr->right);
}

int oddNumberTimesAVLTree(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	ifavltNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertNodeIntoAvlTree(&root,userInput[counter]);
	}
	return getOddManOutInorder(root);
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getNummberOccuringOddNumberOfTimesON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	unsigned int frequecy;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		frequecy = 0;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				frequecy++;
			}
		}
		if(frequecy&1){
			return userInput[outerCrawler];
		}
	}
	return INT_MAX;
}

#endif /* ODDNUMBEROFTIMES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: majoritysortedarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\majoritysortedarray.h
 *  Created on			: May 1, 2014 :: 6:28:54 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
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

#ifndef MAJORITYSORTEDARRAY_H_
#define MAJORITYSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int lowerIndexBinarySearch(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 >= startIndex && userInput[middleIndex-1] == key){
			return lowerIndexBinarySearch(userInput,key,startIndex,middleIndex-1);
		}
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return lowerIndexBinarySearch(userInput,key,startIndex,middleIndex-1);
	}else{
		return lowerIndexBinarySearch(userInput,key,middleIndex+1,endIndex);
	}
}

//Tested
bool isGivenValueMajorityElementOLOGN(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	unsigned int index = lowerIndexBinarySearch(userInput,key,0,userInput.size()-1);
	if(index == UINT_MAX){
		return false;
	}
	if(index + userInput.size()/2 > userInput.size()){
		return false;
	}
	if(userInput[index + userInput.size()/2] == key){
		return true;
	}else{
		return false;
	}
}

//Tested
iftNode *searchForNodeInFBST(iftNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	if(ptr->value){
		return ptr;
	}
	if(ptr->value > key){
		return searchForNodeInFBST(ptr->left,key);
	}else{
		return searchForNodeInFBST(ptr->right,key);
	}
}

//Tested
bool isGivenValueMajorityElementONLONGBST(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	iftNode *rootBST;
	treeutils *utils = new treeutils();
	rootBST = utils->getFBSTreeFromVector(userInput);
	iftNode *nodeForKey = searchForNodeInFBST(rootBST,key);
	if(nodeForKey == null){
		return false;
	}
	return nodeForKey->frequency >= userInput.size()/2?true:false;
}

void rotateNodes(ifavltNode **root,ifavltNode *parent,ifavltNode *child){
	if(parent == null  || child == null){
		return;
	}
	ifavltNode *grandParent = parent->parent;
	if(grandParent != null){
		child->parent = grandParent;
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		child->parent = null;
		(*root) = child;
	}
	parent->parent = child;
	ifavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = child;
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
	if(temp != null){
		temp->parent = parent;
	}
}

ifavltNode *cinsertAtRightPlace(ifavltNode **root,ifavltNode *currentNode,int value){
	if(*root == null){
		(*root) = new ifavltNode(value);
		return null;
	}
	if(currentNode->value == value){
		currentNode->frequency += 1;
		return null;
	}
	if(currentNode->value > value){
		if(currentNode->left == null){
			currentNode->left = new ifavltNode(value);
			currentNode->left->parent = currentNode;
			return currentNode->left;
		}else{
			return insertAtRightPlace(root,currentNode->left,value);
		}
	}else{
		if(currentNode->right == null){
			currentNode->right = new ifavltNode(value);
			currentNode->right->parent = currentNode;
			return currentNode->right;
		}else{
			return insertAtRightPlace(root,currentNode->right,value);
		}
	}
}

void insertNodeIntoFrequencyAVLTree(ifavltNode **root,int value){
	ifavltNode *ptrToInsertedNode = insertAtRightPlace(root,*root,value);
	if(ptrToInsertedNode == null){
		return;
	}
	unsigned int leftHeight,rightHeight;
	while(ptrToInsertedNode != null){
		leftHeight = ptrToInsertedNode->left == null?0:ptrToInsertedNode->left->height;
		rightHeight = ptrToInsertedNode->right == null?0:ptrToInsertedNode->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			ifavltNode *parent,*child,*grandParent =ptrToInsertedNode;
			parent = ptrToInsertedNode->value > value?ptrToInsertedNode->left:ptrToInsertedNode->right;
			child = parent->value > value?parent->left:parent->right;
			if((grandParent->left == parent && parent->left == child) || (grandParent->right == parent && parent->right == child)){
				rotateNodes(root,grandParent,parent);
				grandParent->height = max(grandParent->left== null?0:grandParent->left->height,grandParent->right == null?0:grandParent->right->height)+1;
				parent->height = max(parent->left == null?0:parent->left->height,parent->right == null?0:parent->right->height)+1;
			}else{
				rotateNodes(root,parent,child);
				rotateNodes(root,grandParent,child);
				grandParent->height = max(grandParent->left== null?0:grandParent->left->height,grandParent->right == null?0:grandParent->right->height)+1;
				parent->height = max(parent->left == null?0:parent->left->height,parent->right == null?0:parent->right->height)+1;
				child->height = max(child->left == null?0:child->left->height,child->right == null?0:child->right->height)+1;
			}
			return;
		}
		ptrToInsertedNode->height = max(ptrToInsertedNode->left->height,ptrToInsertedNode->right->height) + 1;
		ptrToInsertedNode = ptrToInsertedNode->parent;
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isGivenValueMajorityElementON(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	unsigned int frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			frequency += 1;
		}
	}
	if(frequency >= userInput.size()/2){
		return true;
	}else{
		return false;
	}
}

#endif /* MAJORITYSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

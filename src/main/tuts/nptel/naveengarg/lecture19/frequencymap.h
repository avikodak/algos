/****************************************************************************************************************************************************
 *  File Name   		: frequencymap.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture19\frequencymap.h
 *  Created on			: Jun 25, 2014 :: 12:22:17 PM
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

#ifndef FREQUENCYMAP_H_
#define FREQUENCYMAP_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
hash_map<int,unsigned int> getFrequencyMapON(vector<int> userInput){
	hash_map<int,unsigned int> frequencyMap;
	if(userInput.size() == 0){
		return frequencyMap;
	}
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	return frequencyMap;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void rotateNodes(ifavltNode **root,ifavltNode *parent,ifavltNode *child){
	if(parent == null || child == null){
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
		*root = child;
	}
	parent->parent = child;
	ifavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = temp;
		if(temp != null){
			temp->parent = parent;
		}
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
		if(temp != null){
			temp->parent = parent;
		}
	}
}

ifavltNode *insertValueAtRightPlace(ifavltNode **root,ifavltNode *currentNode,int userInput){
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
}

void insertIntoAVLTree(ifavltNode **root,int userInput){
	ifavltNode *ptrToInsertedNode = insertValueAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return null;
	}
	ifavltNode *z = ptrToInsertedNode,*y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->value > userInput?z->left:z->right;
			x = y->value > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateNodes(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
				return;
			}else{
				rotateNodes(root,y,x);
				rotateNodes(root,z,x);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
				x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height) + 1;
				return;
			}
		}
		z->height = max(leftHeight,rightHeight) + 1;
	}
}

void setFrequencyInorder(ifavltNode *ptr,hash_map<int,unsigned int> &frequencyMap){
	if(ptr == null){
		return;
	}
	setFrequencyInorder(ptr->left,frequencyMap);
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	if((itToFrequencyMap = frequencyMap.find(ptr->value)) != frequencyMap.end()){
		frequencyMap[ptr->value] += 1;
	}else{
		frequencyMap[ptr->value] = 1;
	}
	setFrequencyInorder(ptr->right,frequencyMap);
}

hash_map<int,unsigned int> getFrequencyMapAVLTreeInOrderIterative(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	stack<ifavltNode *> auxSpace;
	ifavltNode *traversingNode = ptr;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	while(!auxSpace.empty() || traversingNode != null){
		if(traversingNode != null){
			auxSpace.push(traversingNode);
			traversingNode = traversingNode->left;
		}else{
			traversingNode = auxSpace.top();
			auxSpace.pop();
			if((itToFrequencyMap = frequencyMap.find(traversingNode->value)) == frequencyMap.end()){
				frequencyMap[traversingNode->value] = 1;
			}else{
				frequencyMap[traversingNode->value] += 1;
			}
			traversingNode = traversingNode->right;
		}
	}
	return frequencyMap;
}

hash_map<int,unsigned int> getFrequenciesFromAVLPreOrderIterative(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	stack<ifavltNode *> auxSpace;
	ifavltNode *traversingNode;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		traversingNode = auxSpace.top();
		auxSpace.pop();
		if((itToFrequencyMap = frequencyMap.find(traversingNode->value)) == frequencyMap.end()){
			frequencyMap[traversingNode->value] = 1;
		}else{
			frequencyMap[traversingNode->value] += 1;
		}
		if(traversingNode->right == null){
			auxSpace.push(traversingNode->right);
		}
		if(traversingNode->left == null){
			auxSpace.push(traversingNode->left);
		}
	}
	return frequencyMap;
}

hash_map<int,unsigned int> getFrequenciesFromAVLTreePostOrderIterativeTwoStacks(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	stack<ifavltNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	ifavltNode *currentNode;
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
		}
	}
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		if((itToFrequencyMap = frequencyMap.find(currentNode->value)) == frequencyMap.end()){
			frequencyMap[currentNode->value] = 1;
		}else{
			frequencyMap[currentNode->value] += 1;
		}
	}
	return frequencyMap;
}

hash_map<int,unsigned int> getFrequencyMapFromAVLTreePostOrderIterative(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	stack<ifavltNode *> auxSpace;
	ifavltNode *traversingNode = ptr;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	while(!auxSpace.empty() || traversingNode != null){
		if(traversingNode != null){
			if(traversingNode->right != null){
				auxSpace.push(traversingNode->right);
			}
			auxSpace.push(traversingNode->left);
		}else{
			traversingNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && auxSpace.top() == traversingNode->right){
				auxSpace.pop();
				auxSpace.push(traversingNode);
				traversingNode = traversingNode->right;
			}else{
				if((itToFrequencyMap = frequencyMap.find(traversingNode->value)) == frequencyMap.end()){
					frequencyMap[traversingNode->value] = 1;
				}else{
					frequencyMap[traversingNode->value] += 1;
				}
				traversingNode = null;
			}
		}
	}
	return frequencyMap;
}

hash_map<int,unsigned int> getFrequencyMapFromAvlTreePostOrderIterativeV2(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	stack<ifavltNode *> auxSpace;
	ifavltNode *currentNode = ptr;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if((itToFrequencyMap = frequencyMap.find(currentNode->value)) == frequencyMap.end()){
				frequencyMap[currentNode->value] = 1;
			}else{
				frequencyMap[currentNode->value] += 1;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode  = auxSpace.top();
				auxSpace.pop();
				if((itToFrequencyMap = frequencyMap.find(currentNode->value)) == frequencyMap.end()){
					frequencyMap[currentNode->value] = 1;
				}else{
					frequencyMap[currentNode->value] += 1;
				}
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return frequencyMap;
}

hash_map<int,unsigned int> frequencyMapMorrisPreTraversal(ifavltNode *ptr){
	hash_map<int,unsigned int> frequencyMap;
	if(ptr == null){
		return frequencyMap;
	}
	ifavltNode *currentNode = ptr,*temp;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	while(currentNode != null){
		if(currentNode->left == null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				if((itToFrequencyMap = frequencyMap.find(currentNode->value)) == frequencyMap.end()){
					frequencyMap[currentNode->value] = 1;
				}else{
					frequencyMap[currentNode->value] += 1;
				}
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				currentNode = currentNode->right;
			}
		}else{
			if((itToFrequencyMap = frequencyMap.find(currentNode->value)) == frequencyMap.end()){
				frequencyMap[currentNode->value] = 1;
			}else{
				frequencyMap[currentNode->value] += 1;
			}
			currentNode = currentNode->right;
		}
	}
	return frequencyMap;
}

hash_map<int,unsigned int> getFrequencyMapAVLTree(vector<int> userInput){
	hash_map<int,unsigned int> frequencyMap;
	if(userInput.size() == 0){
		return frequencyMap;
	}
	ifavltNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertIntoAVLTree(&root,userInput[counter]);
	}
	setFrequencyInorder(root,frequencyMap);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

void buildFrequencyBSTFromVector(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || currentIndex >= userInput.size()){
		return;
	}
	if(*root == null){
		*root = new iftNode(userInput[currentIndex]);
		buildFrequencyBSTFromVector(root,*root,userInput,currentIndex+1);
	}else{
		if(currentNode->value == userInput[currentIndex]){
			currentNode->frequency += 1;
			buildFrequencyBSTFromVector(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->value > userInput[currentIndex]){
				if(currentNode->left == null){
					currentNode->left = new iftNode(userInput[currentIndex]);
					buildFrequencyBSTFromVector(root,*root,userInput,currentIndex+1);
				}else{
					buildFrequencyBSTFromVector(root,currentNode->left,userInput,currentIndex);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new iftNode(userInput[currentIndex]);
					buildFrequencyBSTFromVector(root,*root,userInput,currentIndex+1);
				}else{
					buildFrequencyBSTFromVector(root,currentNode->right,userInput,currentIndex);
				}
			}
		}
	}
}

void setFrequenciesFromBST(iftNode *ptr,hash_map<int,unsigned int> &frequencyMap){
	if(ptr == null){
		return;
	}
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	setFrequenciesFromBST(ptr->left,frequencyMap);
	if((itToFrequencyMap = frequencyMap.find(ptr->value)) == frequencyMap.end()){
		frequencyMap[ptr->value] = 1;
	}else{
		frequencyMap[ptr->value] += 1;
	}
	setFrequenciesFromBST(ptr->right,frequencyMap);
}

hash_map<int,unsigned int> getFrequencyMapFromBST(vector<int> userInput){
	hash_map<int,unsigned int> frequencyMap;
	if(userInput.size() == 0){
		return frequencyMap;
	}
	iftNode *root = null;
	buildFrequencyBSTFromVector(&root,*root,userInput,0);
	setFrequenciesFromBST(root,frequencyMap);
	return frequencyMap;
}

//To be completed
struct frequency{
	int value;
	unsigned int frequency;
};

set<frequency> getFrequenciesON2(vector<int> userInput){
	set<frequency> frequencies;
	if(userInput.size() == 0){
		return frequencies;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){

	}
}

#endif /* FREQUENCYMAP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

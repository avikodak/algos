/****************************************************************************************************************************************************
 *  File Name   		: firstnonrepeatingchar.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page03\firstnonrepeatingchar.h
 *  Created on			: Jun 26, 2014 :: 4:09:38 PM
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
#define ALPHABETS_SIZE 256
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FIRSTNONREPEATINGCHAR_H_
#define FIRSTNONREPEATINGCHAR_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
char getFirstNonRepeatingCharacter(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	hash_map<char,unsigned int> charFrequencyMap;
	hash_map<char,unsigned int>::iterator itToCharFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToCharFrequencyMap = charFrequencyMap.find(userInput[counter])) != charFrequencyMap.end()){
			charFrequencyMap[userInput[counter]] += 1;
		}else{
			charFrequencyMap[userInput[counter]] = 1;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		itToCharFrequencyMap = charFrequencyMap.find(userInput[counter]);
		if(itToCharFrequencyMap->second == 1){
			return userInput[counter];
		}
	}
	return '\0';
}

char getFirstNonRepeatingCharacterAuxspace(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	unsigned int frequencies[ALPHABETS_SIZE] = {0};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequencies[userInput[counter]] += 1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequencies[userInput[counter]] == 1){
			return userInput[counter];
		}
	}
	return '\0';
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void getCFBSTFromString(cftNode **root,cftNode *currentNode,string userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || currentIndex >= userInput.size()){
		return;
	}
	if(*root == null){
		*root = new cftNode(userInput[currentIndex]);
		getCFBSTFromString(root,*root,userInput,currentIndex+1);
	}else{
		if(currentNode->ch == userInput[currentIndex]){
			currentNode->frequency += 1;
			getCFBSTFromString(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->ch > userInput[currentIndex]){
				if(currentNode->left == null){
					currentNode->left = new cftNode(userInput[currentIndex]);
					getCFBSTFromString(root,*root,userInput,currentIndex+1);
				}else{
					getCFBSTFromString(root,currentNode->left,userInput,currentIndex);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new cftNode(userInput[currentIndex]);
					getCFBSTFromString(root,*root,userInput,currentIndex+1);
				}else{
					getCFBSTFromString(root,currentNode->right,userInput,currentIndex);
				}
			}
		}
	}
}

cftNode *searchForCharCFBST(cftNode *ptr,char ch){
	if(ptr == null){
		return null;
	}
	if(ptr->ch == ch){
		return ptr;
	}
	if(ptr->ch > ch){
		return searchForCharCFBST(ptr->left,ch);
	}else{
		return searchForCharCFBST(ptr->right,ch);
	}
}

char getFirstNonRepeatingChar(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	cftNode *root = null,*ptrToKey;
	getCFBSTFromString(&root,root,userInput,0);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		ptrToKey = searchForCharCFBST(root,userInput[counter]);
		if(ptrToKey->frequency == 1){
			return ptrToKey->ch;
		}
	}
	return '\0';
}

cfavltNode *insertAtRightPlace(cfavltNode **root,cfavltNode *currentNode,char userInput){
	if(*root == null){
		*root = new cfavltNode(userInput);
		return null;
	}else{
		if(currentNode->ch == userInput){
			currentNode->frequency += 1;
			return null;
		}
		if(currentNode->ch > userInput){
			if(currentNode->left == null){
				currentNode->left = new cfavltNode(userInput);
				currentNode->left->parent = currentNode;
				return currentNode->left;
			}else{
				return insertAtRightPlace(root,currentNode->left,userInput);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new cfavltNode(userInput);
				currentNode->right->parent = currentNode;
				return currentNode->right;
			}else{
				return insertAtRightPlace(root,currentNode->right,userInput);
			}
		}
	}
}

void rotateCTNodes(cfavltNode **root,cfavltNode *parent,cfavltNode *child){
	if(parent == null || child == null){
		return;
	}
	cfavltNode *grandParent = parent->parent;
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
	cfavltNode *temp;
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = temp;
	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
	if(temp == null){
		temp->parent = parent;
	}
}

void insertCharIntoCfavlTree(cfavltNode **root,char userInput){
	cfavltNode *ptrToInsertedNode = insertAtRightPlace(root,*root,userInput);
	if(ptrToInsertedNode == null){
		return;
	}
	unsigned int leftHeight,rightHeight;
	cfavltNode *z,*y,*x;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight - rightHeight) > 1){
			y = z->ch > userInput?z->left:z->right;
			x = y->ch > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateCTNodes(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
			}else{
				rotateCTNodes(root,y,x);
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

cfavltNode *searchForNodeCFAVLTree(cfavltNode *ptr,char ch){
	if(ptr == null){
		return null;
	}
	if(ptr->ch == ch){
		return ptr;
	}
	if(ptr->ch > ch){
		return searchForNodeCFAVLTree(ptr->left,ch);
	}else{
		return searchForNodeCFAVLTree(ptr->right,ch);
	}
}

char getFirstNonRepeatingCharAvlTree(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	cfavltNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertCharIntoCfavlTree(&root,userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		cfavltNode *node = searchForNodeCFAVLTree(root,userInput[counter]);
		if(node->frequency == 1){
			return node->ch;
		}
	}
	return '\0';
}

unsigned int *getFrequenciesONLOGN(string userInput){
	if(userInput.size() == 0){
		return null;
	}
	unsigned int frequencies[ALPHABETS_SIZE] = {0};
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0,currentCharFrequency ;
	while(counter < userInput.size()){
		currentCharFrequency = 1;
		while(counter +1< userInput.size() && userInput[counter] == userInput[counter+1]){
			currentCharFrequency++;
		}
		frequencies[userInput[counter]] = currentCharFrequency;
		counter++;
	}
	return frequencies;
}

char getFirstNonRepeatingCharONLOGN(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	char *frequencies =getFrequenciesONLOGN(userInput);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(frequencies[userInput[counter]] == 1){
			return userInput[counter];
		}
	}
	return '\0';
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
char getFirstNonrepeatingCharON2(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	bool isDuplicate;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		isDuplicate = false;
		for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(innerCrawler == outerCrawler){
				continue;
			}
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				isDuplicate = true;
				break;
			}
		}
		if(!isDuplicate){
			return userInput[outerCrawler];
		}
	}
	return '\0';
}

#endif /* FIRSTNONREPEATINGCHAR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

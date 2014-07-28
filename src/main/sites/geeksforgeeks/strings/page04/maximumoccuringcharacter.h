/****************************************************************************************************************************************************
 *  File Name   		: maximumoccuringcharacter.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page04\maximumoccuringcharacter.h
 *  Created on			: Jun 26, 2014 :: 2:44:18 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/
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
#define ALPHABET_SIZE 256

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
#ifndef MAXIMUMOCCURINGCHARACTER_H_
#define MAXIMUMOCCURINGCHARACTER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
char getMaximumOccuringChar(char *userInput){
	if(userInput == null){
		return '\0';
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	char currentCh;
	while(userInput != null){
		currentCh = *userInput;
		if((itToFrequencyMap = frequencyMap.find(currentCh)) == frequencyMap.end()){
			frequencyMap[currentCh] = 1;
		}else{
			frequencyMap[currentCh] += 1;
		}
		userInput++;
	}
	unsigned int maxFrequency = 0;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(maxFrequency < itToFrequencyMap->second){
			maxFrequency = itToFrequencyMap->second;
			currentCh = itToFrequencyMap->first;
		}
	}
	return currentCh;
}

char getMaximumOccuringCharAuxspace(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	unsigned int frequencies[ALPHABET_SIZE] = {0};
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		frequencies[userInput[counter]] += 1;
	}
	unsigned int maxFrequency  = 0;
	char maxFrequentChar = '\0';
	for(unsigned int counter = 0;counter < ALPHABET_SIZE;counter++){
		if(maxFrequency < frequencies[counter]){
			maxFrequency = frequencies[counter];
			maxFrequentChar = (char)counter;
		}
	}
	return maxFrequentChar;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
char getMaximumOccuringChar(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	sort(userInput.begin(),userInput.end());
	unsigned int crawler = 0,maxFrequency = 0,frequency;
	char maxOccuringChar;
	while(crawler < userInput.size()){
		frequency=1;
		while(crawler+1< userInput.size() && userInput[crawler] == userInput[crawler+1]){
			crawler++;
			frequency++;
		}
		if(maxFrequency < frequency){
			maxFrequency = frequency;
			maxOccuringChar = userInput[crawler];
		}
		crawler++;
	}
	return maxOccuringChar;
}

void insertIntoCFBST(cftNode **root,cftNode *currentNode,char *userInput){
	if(userInput == null){
		return;
	}
	char currentChar = *userInput;
	if(*root == null){
		(*root) = new cftNode(currentChar);
		insertIntoCFBST(root,*root,userInput++);
	}else{
		if(currentNode->ch == currentChar){
			currentNode->frequency++;
			insertIntoCFBST(root,*root,userInput++);
		}else{
			if(currentNode->ch > currentChar){
				if(currentNode->left == null){
					currentNode->left = new cftNode(currentChar);
					insertIntoCFBST(root,*root,userInput++);
				}else{
					insertIntoCFBST(root,currentNode->left,userInput);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new cftNode(currentChar);
					insertIntoCFBST(root,*root,userInput++);
				}else{
					insertIntoCFBST(root,currentNode->right,userInput);
				}
			}
		}
	}
}

cftNode *getMaxOccuringCharCFBST(cftNode *ptr){
	if(ptr  == null){
		return null;
	}
	cftNode *leftResult = getMaxOccuringCharCFBST(ptr->left);
	cftNode *rightResult = getMaxOccuringCharCFBST(ptr->right);
	unsigned int maxFrequency = 0;
	cftNode *result = null;
	if(leftResult != null){
		maxFrequency = leftResult->frequency;
		result = leftResult;
	}
	if(rightResult != null){
		if(rightResult->frequency > maxFrequency){
			result = rightResult;
			maxFrequency = rightResult->frequency;
		}
	}
	if(maxFrequency < ptr->frequency){
		result = ptr;
	}
	return result;
}

cftNode *getCFBST(char *userInput){
	cftNode *root;
	insertIntoCFBST(&root,*root,userInput);
	return getMaxOccuringCharCFBST(root);
}

cfavltNode *insertCharAtRightPlace(cfavltNode **root,cfavltNode *currentNode,char ch){
	if(*root == null){
		*root = new cfavltNode(ch);
		return null;
	}else{
		if(currentNode->ch == ch){
			currentNode->frequency += 1;
			return null;
		}else{
			if(currentNode->ch > ch){
				if(currentNode->left == null){
					currentNode->left = new cfavltNode(ch);
					currentNode->left->parent = currentNode;
					return currentNode->left;
				}else{
					return insertCharAtRightPlace(root,currentNode->left,ch);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new cfavltNode(ch);
					currentNode->right->parent = currentNode;
					return currentNode->right;
				}else{
					return insertCharAtRightPlace(root,currentNode->right,ch);
				}
			}
		}
	}
}

void rotateNodes(cfavltNode **root,cfavltNode *parent,cfavltNode *child){
	cfavltNode *grandParent = parent->parent;
	if(grandParent != null){
		if(grandParent->left == parent){
			grandParent->left = child;
		}else{
			grandParent->right = child;
		}
	}else{
		*root = child;
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
	if(temp != null){
		temp->parent = parent;
	}
}

void insertCharIntoCFAVLTree(cfavltNode **root,char userInput){
	cfavltNode *ptrToInsertedChar = insertCharAtRightPlace(root,*root,userInput);
	if(ptrToInsertedChar == null){
		return;
	}
	cfavltNode *z = ptrToInsertedChar,*y,*x;
	int leftHeight,rightHeight;
	while(z != null){
		leftHeight = z->left == null?0:z->left->height;
		rightHeight = z->right == null?0:z->right->height;
		if(abs(leftHeight-rightHeight) > 1){
			y = z->ch > userInput?z->left:z->right;
			x = y->ch > userInput?y->left:y->right;
			if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
				rotateNodes(root,z,y);
				z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
				y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
			}else{
				rotateNodes(root,y,x);
				rotateNodes(root,z,x);
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

char getMaximumCharPostOrderCFAVL(cfavltNode *root){
	if(root == null){
		return '\0';
	}
	stack<cfavltNode *> auxSpace;
	cfavltNode *currentNode = root;
	unsigned int maxFrequency;
	char maxOccuringChar = '\0';
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(maxFrequency < currentNode->frequency){
				maxOccuringChar = currentNode->ch;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(maxFrequency < currentNode->frequency){
					maxFrequency = currentNode->frequency;
					maxOccuringChar = currentNode->ch;
				}
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return maxOccuringChar;
}

char getMaximumOccuringCharCFAVL(string userInput){
	if(userInput.size() == 0){
		return '\0';
	}
	cfavltNode *root = null;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		insertCharAtRightPlace(&root,userInput[counter]);
	}
	return getMaximumCharPostOrderCFAVL(root);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
char getMaximumOccuringChar(char *userInput){
	if(userInput == null){
		return '\0';
	}
	char *outerCrawler = userInput,*innerCrawler;
	unsigned int maxFrequency=0,counter;
	char maxOccuringChar,outerCharacter,innerCharacter;
	while(outerCrawler != null){
		innerCrawler = userInput;
		outerCharacter = *outerCrawler;
		counter = 0;
		while(innerCrawler != null){
			innerCharacter = *innerCrawler;
			if(innerCharacter == outerCharacter){
				counter;
			}
		}
		if(maxFrequency < counter){
			maxFrequency = counter;
			maxOccuringChar = *outerCharacter;
		}
	}
	return maxFrequency;
}

#endif /* MAXIMUMOCCURINGCHARACTER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

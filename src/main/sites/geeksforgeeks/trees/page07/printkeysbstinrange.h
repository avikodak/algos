/****************************************************************************************************************************************************
 *  File Name   		: printkeysbstinrange.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\printkeysbstinrange.h
 *  Created on			: May 8, 2014 :: 10:39:00 PM
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

#ifndef PRINTKEYSBSTINRANGE_H_
#define PRINTKEYSBSTINRANGE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printKeysBSTInRange(itNode *ptr,int &minValue,int &maxValue){
	if(ptr == null){
		return;
	}
	if(ptr->value > minValue){
		printKeysBSTInRange(ptr->left,minValue,maxValue);
	}
	if(ptr->value >= minValue &&  ptr->value <= maxValue){
		printf("%d\t",ptr->value);
	}
	if(ptr->value < maxValue){
		printKeysBSTInRange(ptr->right,minValue,maxValue);
	}
}

void printKeysBSTInRangeIterative(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value >= minValue && currentNode->value <= maxValue){
				printf("%d\t",currentNode->value);
			}
			currentNode = currentNode->right;
		}
	}
}

void printKeysBSTInRangeMorrisOrder(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				if(currentNode->value >= minValue && currentNode->value <= maxValue){
					printf("%d\t",currentNode->value);
				}
				currentNode = currentNode->right;
			}
		}else{
			if(currentNode->value >= minValue && currentNode->value <= maxValue){
				printf("%d\t",currentNode->value);
			}
			currentNode = currentNode->right;
		}
	}
}

void pkbstFixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	pkbstFixLeftPtr(ptr->left);
	ptr->left = prevNode;
	pkbstFixLeftPtr(ptr->right);
}

void pkbstFixRightPtr(itNode **ptr){
	if(*ptr == null){
		return;
	}
	itNode *traversalNode = *ptr,*prevNode = null;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	while(traversalNode != null){
		traversalNode->right = null;
		prevNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = prevNode;
}

void printKeysBSTInRangeDLLConversion(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	pkbstFixLeftPtr(ptr);
	pkbstFixRightPtr(&ptr);
	while(ptr != null){
		if(ptr->value >= minValue && ptr->value <= maxValue){
			printf("%d\t",ptr->value);
		}
		ptr = ptr->right;
	}
}

void printKeysBSTInRangeDLLConversionMain(itNode **head,itNode *ptr){
	if(*head == null || ptr == null){
		return;
	}
	static itNode *prevNode = null;
	printKeysBSTInRangeDLLConversionON(head,ptr->left);
	if(prevNode == null){
		(*head) = ptr;
	}else{
		prevNode->right = ptr;
	}
	ptr->left = prevNode;
	prevNode = ptr;
	printKeysBSTInRangeDLLConversionON(head,ptr->right);
}

void printKeysBSTInRangeDLLConversionON(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	printKeysBSTInRangeDLLConversionMain(&ptr,ptr);
	itNode *traversalNode = ptr;
	while(traversalNode != null){
		if(traversalNode->value >= minValue && traversalNode->value <= maxValue){
			printf("%d\t",traversalNode->value);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void printKeysBSTInRangeONLOGN(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return;
	}
	vector<int> preOrderValues;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderValues(ptr,preOrderValues);
	sort(preOrderValues.begin(),preOrderValues.end());
	for(unsigned int counter = 0;counter < preOrderValues.size();counter++){
		if(preOrderValues[counter] >= minValue && preOrderValues[counter] <= maxValue){
			printf("%d\t",preOrderValues[counter]);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *printKeysBSTInRangeDllConversionON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftSubTree = printKeysBSTInRangeDllConversionON2Main(ptr->left);
		while(leftSubTree->right != null){
			leftSubTree = leftSubTree->right;
		}
		leftSubTree->right = ptr;
		ptr->left = leftSubTree;
	}
	if(ptr->right != null){
		itNode *rightSubTree = printKeysBSTInRangeDllConversionON2Main(ptr->right);
		while(rightSubTree->left != null){
			rightSubTree = rightSubTree->left;
		}
		rightSubTree->left = ptr;
		ptr->right = rightSubTree;
	}
	return ptr;
}

void printKeysBSTInRangeDllConversionON2(itNode *ptr,int minValue,int maxValue){
	if(ptr == null){
		return null;
	}
	printKeysBSTInRangeDllConversionON2Main(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null){
		if(ptr->value >= minValue && ptr->value <= maxValue){
			printf("%d\t",ptr->value);
		}
		ptr = ptr->right;
	}
}
#endif /* PRINTKEYSBSTINRANGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: treetraversals.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\treetraversals.h
 *  Created on			: Apr 12, 2014 :: 11:40:11 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/618/
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
#define PRINT_NEW_LINE printf("\n")
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void preOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

//Tested
void preOrderTraversalIterative(itNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		printf("%d\t",currentTopNode->value);
		if(currentTopNode->right != NULL){
			auxSpace.push(currentTopNode->right);
		}
		if(currentTopNode->left != NULL){
			auxSpace.push(currentTopNode->left);
		}
	}
}

//Tested
void preOrderTraversalMorrisTraversal(itNode *ptr){
	if(ptr == NULL){
		return;
	}
	itNode *traversalNode = ptr,*currentNode;
	while(traversalNode != NULL){
		if(traversalNode->left != NULL){
			currentNode = traversalNode->left;
			while(currentNode->right != NULL && currentNode->right != traversalNode){
				currentNode = currentNode->right;
			}
			if(currentNode->right == NULL){
				printf("%d\t",traversalNode->value);
				currentNode->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				currentNode->right = null;
				traversalNode = traversalNode->right;
			}
		}else{
			printf("%d\t",traversalNode->value);
			traversalNode = traversalNode->right;
		}
	}
}

//Tested
void postOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	postOrderTraversal(ptr->left);
	postOrderTraversal(ptr->right);
	printf("%d\t",ptr->value);
}

//Tested
void postOrderTraversalIteravativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode;
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentTopNode);
		if(currentTopNode->left != null){
			primaryAuxspace.push(currentTopNode->left);
		}
		if(currentTopNode->right != null){
			primaryAuxspace.push(currentTopNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		printf("%d\t",secondaryAuxspace.top()->value);
		secondaryAuxspace.pop();
	}
}

//Tested
void postOrderTraversalIterativeAuxSpace(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != NULL){
		if(currentNode != NULL){
			if(currentNode->right != NULL){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && currentNode->right == auxSpace.top()){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				printf("%d\t",currentNode->value);
				currentNode = null;
			}
		}
	}
}

//Tested
void inOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	inOrderTraversal(ptr->left);
	printf("%d\t",ptr->value);
	inOrderTraversal(ptr->right);
}

//Tested
void inOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != NULL){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

//Tested
void inOrderTraversalMorrisIterative(itNode *ptr){
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
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			printf("%d\t",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

//Tested
void fixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *previousPtr = NULL;
	fixLeftPtr(ptr->left);
	ptr->left = previousPtr;
	previousPtr = ptr;
	fixLeftPtr(ptr->right);
}

//Tested
void fixRightPtr(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = *ptr,*nextRightNode = NULL;
	while(traversalNode->right != NULL){
		traversalNode = traversalNode->right;
	}
	while(traversalNode != null){
		traversalNode->right = nextRightNode;
		nextRightNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = nextRightNode;
}

//Tested
void inOrderTraversalByTreeToDLL(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *temp = ptr;
	fixLeftPtr(temp);
	fixRightPtr(&temp);
	while(temp != null){
		printf("%d\t",temp->value);
		temp = temp->right;
	}
}

//Tested
void levelOrderTraversal(itNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNodeInQueue;
	auxSpace.push(ptr);
	unsigned int nodeCounterInLevel = 1,nextLevelNodeCounter = 0;
	while(!auxSpace.empty()){
		nextLevelNodeCounter = 0;
		while(nodeCounterInLevel--){
			currentNodeInQueue = auxSpace.front();
			auxSpace.pop();
			printf("%d\t",currentNodeInQueue->value);
			if(currentNodeInQueue->left != NULL){
				auxSpace.push(currentNodeInQueue->left);
				nextLevelNodeCounter++;
			}
			if(currentNodeInQueue->right != NULL){
				auxSpace.push(currentNodeInQueue->right);
				nextLevelNodeCounter++;
			}
		}
		PRINT_NEW_LINE;
		nodeCounterInLevel = nextLevelNodeCounter;
	}
}

void levelOrderTraversalByFillNextRight(){

}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode *inOrderTraversalByTreeToDLLON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	itNode *temp;
	if(ptr->left != null){
		itNode *currentNodesLeftChild = inOrderTraversalByTreeToDLLON2Main(ptr->left);
		temp = currentNodesLeftChild;
		while(temp->right != null){
			temp = temp->right;
		}
		temp->right = ptr;
		ptr->left = temp;
	}
	if(ptr->right != null){
		itNode *currentNodesRightChild = inOrderTraversalByTreeToDLLON2Main(ptr->right);
		temp = currentNodesRightChild;
		while(temp->left != null){
			temp = temp->left;
		}
		temp->left = ptr;
		ptr->right = temp;
	}
	return ptr;
}

//Tested
void inOrderTraversalByTreeToDLLON2Driver(itNode *ptr){
	if(ptr == null){
		return;
	}
	inOrderTraversalByTreeToDLLON2Main(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	while(ptr != null){
		printf("%d\t",ptr->value);
		ptr = ptr->right;
	}
}

//Tested
void printLevelInTree(itNode *ptr,unsigned int currentNodeLevel){
	if(ptr == NULL){
		return;
	}
	if(currentNodeLevel == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevelInTree(ptr->left,currentNodeLevel-1);
	printLevelInTree(ptr->right,currentNodeLevel-1);
}

//Tested
void levelOrderTraversalON2(itNode *ptr){
	if(ptr == NULL){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	for(unsigned int counter = 0;counter < heightOfTree;counter++){
		printLevelInTree(ptr,counter);
		PRINT_NEW_LINE;
	}
}


#endif /* TREETRAVERSALS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

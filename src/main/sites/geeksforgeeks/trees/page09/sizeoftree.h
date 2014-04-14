/****************************************************************************************************************************************************
 *  File Name   		: sizeoftree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\sizeoftree.h
 *  Created on			: Apr 14, 2014 :: 5:03:17 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
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

#ifndef SIZEOFTREE_H_
#define SIZEOFTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int getSizeOfTreePreOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + getSizeOfTreePreOrderTraversal(ptr->left) + getSizeOfTreePreOrderTraversal(ptr->right);
}

//Tested
unsigned int getSizeOfTreePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	auxSpace.push(ptr);
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		sizeOfTree++;
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
		}
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
		}
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreeMorrisPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp;
	unsigned int sizeOfTree = 0;
	while(traversalNode != null){
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp  = temp->right;
			}
			if(temp->right == null){
				sizeOfTree++;
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				traversalNode = traversalNode->right;
			}
		}else{
			sizeOfTree++;
			traversalNode = traversalNode->right;
		}
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreeInOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return getSizeOfTreeInOrderTraversal(ptr->left) + 1 + getSizeOfTreeInOrderTraversal(ptr->right);
}

//Tested
unsigned int getSizeOfTreeInOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			sizeOfTree++;
			currentNode = currentNode->right;
		}
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreeMorrisInOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp;
	unsigned int sizeOfTree = 0;
	while(traversalNode != null){
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				sizeOfTree++;
				traversalNode = traversalNode->right;
			}
		}else{
			sizeOfTree++;
			traversalNode = traversalNode->right;
		}
	}
	return sizeOfTree;
}

//Tested
void sfixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	sfixLeftPtr(ptr->left);
	ptr->left = prevNode;
	prevNode = ptr;
	sfixLeftPtr(ptr->right);
}

//Tested
void sfixRightPtr(itNode **ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = *ptr,*prevNode = null;
	while(traversalNode->right != null){
		traversalNode = traversalNode->right;
	}
	while(traversalNode != null){
		traversalNode->right = prevNode;
		prevNode = traversalNode;
		traversalNode = traversalNode->left;
	}
	(*ptr) = prevNode;
}

//Tested
unsigned int getSizeOfTreeDllConversionON(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	sfixLeftPtr(ptr);
	sfixRightPtr(&ptr);
	unsigned int sizeOfTree =0;
	while(ptr != null){
		sizeOfTree++;
		ptr = ptr->right;
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreePostOrderTraversal(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return getSizeOfTreePostOrderTraversal(ptr->left) + getSizeOfTreePostOrderTraversal(ptr->right) + 1;
}

//Tested
unsigned int getSizeOfTreePostOrderTraversalTwoStacks(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentTopNode;
	primaryAuxspace.push(ptr);
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
	unsigned int sizeOfTree = 0;
	while(!secondaryAuxspace.empty()){
		sizeOfTree++;
		secondaryAuxspace.pop();
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreePostOrderTraversalAuxspace(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				sizeOfTree++;
				currentNode = null;
			}
		}
	}
	return sizeOfTree;
}

//Tested
unsigned int getSizeOfTreeLevelOrderTraverssalIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *>  auxSpace;
	auxSpace.push(ptr);
	itNode *currentFrontNodeInQueue;
	unsigned int sizeOfTree = 0;
	while(!auxSpace.empty()){
		currentFrontNodeInQueue = auxSpace.front();
		auxSpace.pop();
		sizeOfTree++;
		if(currentFrontNodeInQueue->left != null){
			auxSpace.push(currentFrontNodeInQueue->left);
		}
		if(currentFrontNodeInQueue->right != null){
			auxSpace.push(currentFrontNodeInQueue->right);
		}
	}
	return sizeOfTree;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
itNode * sizeOfTreeDLLConversionON2Main(itNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		itNode *leftChild = sizeOfTreeDLLConversionON2Main(ptr->left);
		while(leftChild->right != null){
			leftChild = leftChild->right;
		}
		leftChild->right = ptr;
		ptr->left = leftChild;
	}
	if(ptr->right != null){
		itNode *rightChild = sizeOfTreeDLLConversionON2Main(ptr->right);
		while(rightChild->left != null){
			rightChild = rightChild->left;
		}
		rightChild->left = ptr;
		ptr->right = rightChild;
	}
	return ptr;
}

//Tested
unsigned int getSizeOfTreeDllConversionON2Driver(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	sizeOfTreeDLLConversionON2Main(ptr);
	while(ptr->left != null){
		ptr = ptr->left;
	}
	unsigned int sizeOfTree = 0;
	while(ptr != null){
		ptr = ptr->right;
		sizeOfTree++;
	}
	return sizeOfTree;
}

//Tested
unsigned int nodeCounterInLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return 1;
	}
	return nodeCounterInLevel(ptr->left,level-1) + nodeCounterInLevel(ptr->right,level-1);
}

//Tested
unsigned int getSizeOfTreeLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	unsigned int sizeOfTree = 0;
	for(unsigned int counter = 0;counter < heightOfTree;counter++){
		sizeOfTree += nodeCounterInLevel(ptr,counter);
	}
	return sizeOfTree;
}

#endif /* SIZEOFTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

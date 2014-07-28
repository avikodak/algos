/****************************************************************************************************************************************************
 *  File Name   		: doubletree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\doubletree.h
 *  Created on			: May 1, 2014 :: 7:42:01 PM
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

#ifndef DOUBLETREE_H_
#define DOUBLETREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void doubleTreePostOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	doubleTreePostOrder(ptr->left);
	doubleTreePostOrder(ptr->right);
	itNode *newNode = new itNode(ptr->value);
	newNode->left = ptr->left;
	ptr->left = newNode;
}

void doubleTreePreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *newNode = new itNode(ptr->value);
	newNode->left = ptr->left;
	ptr->left = newNode;
	doubleTreePreOrder(ptr->left->left);
	doubleTreePreOrder(ptr->right);
}

void doubleTreeInOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	doubleTreeInOrder(ptr->left);
	itNode *newNode = new itNode(ptr->value);
	newNode->left = ptr->left;
	ptr->left = newNode;
	doubleTreeInOrder(ptr->right);
}

void doubleTreePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
		}
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
		}
		itNode *newNode = new itNode(currentTopNode->value);
		newNode->left = currentTopNode->left;
		currentTopNode->left = newNode;
	}
}

void doubleTreeInOrderIterative(itNode *ptr){
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
			itNode *newNode = new itNode(currentNode->value);
			newNode->left = currentNode->left;
			currentNode->left = newNode;
			auxSpace.pop();
			currentNode = currentNode->right;
		}
	}
}

void doubleTreePostOrderIterativeTwoStacks(itNode *ptr){
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
		if(currentTopNode->right  != null){
			primaryAuxspace.push(currentTopNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		itNode *newNode = new itNode(currentTopNode->value);
		newNode->left = currentTopNode->left;
		currentTopNode->left = newNode;
	}
}

void doubleTreePostOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && currentNode->right == auxSpace.top()){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				itNode *newNode = new itNode(currentNode->value);
				newNode->left = currentNode->left;
				currentNode->left = newNode;
				currentNode = null;
			}
		}
	}
}

void doubleTreeLevelOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentFrontNode;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentFrontNode = auxSpace.front();
		auxSpace.pop();
		if(currentFrontNode->left != null){
			auxSpace.push(currentFrontNode->left);
		}
		if(currentFrontNode->right != null){
			auxSpace.push(currentFrontNode->right);
		}
		itNode *newNode = new itNode(currentFrontNode->value);
		newNode->left = currentFrontNode->left;
		currentFrontNode->left = newNode;
	}
}

void doubleTreeHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	itNode *currentNode;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNode = itToIndexNodeMap->second;
		itNode *newNode = new itNode(currentNode->value);
		newNode->left = currentNode->left;
		currentNode->left = newNode;
	}
}

void convertDoubleTreePostorderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *traversalNode = ptr,*newNode;
	while(!auxSpace.empty() || traversalNode != null){
		while(traversalNode != null){
			auxSpace.push(traversalNode);
			traversalNode = traversalNode->left;
		}
		if(!auxSpace.empty()){
			traversalNode = auxSpace.top();
			auxSpace.pop();
			newNode = new itNode(traversalNode->value);
			newNode->left = traversalNode->left;
			traversalNode->left = newNode;
			while(!auxSpace.empty() && auxSpace.top()->right == traversalNode){
				traversalNode = auxSpace.top();
				auxSpace.pop();
				newNode = new itNode(traversalNode->value);
				newNode->left = traversalNode->left;
				traversalNode->left = newNode;
			}
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* DOUBLETREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

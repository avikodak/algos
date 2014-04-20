/****************************************************************************************************************************************************
 *  File Name   		: deletetree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\deletetree.h
 *  Created on			: Apr 17, 2014 :: 1:48:17 AM
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

#ifndef DELETETREE_H_
#define DELETETREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void deleteTreePostOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	deleteTreePostOrderTraversal(ptr->left);
	deleteTreePostOrderTraversal(ptr->right);
	free(ptr);
}

void deleteTreePreOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *leftSubTree = ptr->left;
	itNode *rightSubTree = ptr->right;
	free(ptr);
	deleteTreePreOrderTraversal(leftSubTree);
	deleteTreePreOrderTraversal(rightSubTree);
}

void deleteTreePreOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	auxSpace.push(ptr);
	itNode *currentTopNode;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
		}
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
		}
		free(currentTopNode);
	}
}

void deleteTreePostOrderTraversalIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
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
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		free(currentTopNode);
	}
}

void deleteTreePostOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode = ptr;
	while(!auxSpace.empty() || currentTopNode != null){
		if(currentTopNode != null){
			if(currentTopNode->right != null){
				auxSpace.push(currentTopNode->right);
			}
			auxSpace.push(currentTopNode);
			currentTopNode = currentTopNode->left;
		}else{
			currentTopNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && auxSpace.top() == currentTopNode->right){
				auxSpace.pop();
				auxSpace.push(currentTopNode);
				currentTopNode = currentTopNode->right;
			}else{
				free(currentTopNode);
				currentTopNode = null;
			}
		}
	}
}

void fixLeftPtr(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevInOrderNode = null;
	fixLeftPtr(ptr->left);
	ptr->left = prevInOrderNode;
	prevInOrderNode = ptr;
	fixLeftPtr(ptr->right);
}

void fixRightPtr(itNode **ptr){
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

void deleteTreeByLLConversionON(itNode *ptr){
	if(ptr == null){
		return;
	}
	fixLeftPtr(ptr);
	fixRightPtr(&ptr);
	itNode *traversalNode = ptr,*nodeToBeDeleted;
	while(traversalNode != null){
		nodeToBeDeleted = traversalNode;
		traversalNode = traversalNode->right;
		free(nodeToBeDeleted);
	}
	&ptr = null;
}

void treeToLLInOrderConversionON(itNode *ptr){
	if(ptr == null){
		return null;
	}
	static itNode *prevNode = null;
	treeToLLInOrderConversionON(ptr->left);
	ptr->left = prevNode;
	if(prevNode != null){
		prevNode->right = ptr;
	}
	prevNode = ptr;
	treeToLLInOrderConversionON(ptr->right);
}

void deleteTreeByLLConversionInOrderON(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeToLLInOrderConversionON(ptr);
	itNode *traversalNode = ptr,*nodeToBeDeleted;
	while(traversalNode != null){
		nodeToBeDeleted = traversalNode;
		traversalNode = traversalNode->right;
		free(nodeToBeDeleted);
	}
}

void deleteTreeByHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.end()-1;itToIndexNodeMap != indexNodeMap.begin();itToIndexNodeMap--){
		free(itToIndexNodeMap->second);
	}
	free(indexNodeMap.begin());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

void deleteLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		free(ptr);
		return;
	}
	deleteLevel(ptr->left,level-1);
	deleteLevel(ptr->right,level-1);
}

void deleteNodeByLevelON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	for(unsigned int levelCounter = heightOfTree-1;levelCounter >= 0;levelCounter--){
		deleteLevel(ptr,levelCounter);
	}
}

#endif /* DELETETREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

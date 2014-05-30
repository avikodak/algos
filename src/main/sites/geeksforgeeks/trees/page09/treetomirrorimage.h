/****************************************************************************************************************************************************
 *  File Name   		: treetomirrorimage.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\treetomirrorimage.h
 *  Created on			: Apr 20, 2014 :: 6:37:10 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
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

#ifndef TREETOMIRRORIMAGE_H_
#define TREETOMIRRORIMAGE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void treeToMirrorImagePreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *tempForSwap = ptr->left;
	ptr->left = ptr->right;
	ptr->right = tempForSwap;
	treeToMirrorImagePreOrder(ptr->left);
	treeToMirrorImagePreOrder(ptr->right);
}

//Tested
void treeToMirrorImagePostOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeToMirrorImagePostOrder(ptr->left);
	treeToMirrorImagePostOrder(ptr->right);
	itNode *tempForSwap = ptr->left;
	ptr->left = ptr->right;
	ptr->right = tempForSwap;
}

//Tested
void treeToMirrorImagePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	itNode *tempForSwap;
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
		tempForSwap = currentTopNode->left;
		currentTopNode->left = currentTopNode->right;
		currentTopNode->right = tempForSwap;
	}
}

//Tested
void treeToMirrorImagePostOrderTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode,*tempForSwap;
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
		tempForSwap = currentTopNode->left;
		currentTopNode->left = currentTopNode->right;
		currentTopNode->right = tempForSwap;
	}
}

//Tested
void treeToMirrorImagePostOrderAuxspace(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr,*tempForSwap;
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
			if(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				tempForSwap = currentNode->left;
				currentNode->left = currentNode->right;
				currentNode->right = tempForSwap;
				currentNode = null;
			}
		}
	}
}

//Tested
void swapLeftRightChildren(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

//Tested
void treeToMirrorImagePostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			swapLeftRightChildren(currentNode);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				swapLeftRightChildren(currentNode);
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

//Tested
void treeToMirrorImageHashmapTopToBottom(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	itNode *tempForSwap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		tempForSwap = itToIndexNodeMap->second->left;
		itToIndexNodeMap->second->left = itToIndexNodeMap->second->right;
		itToIndexNodeMap->second->right = tempForSwap;
	}
}

#endif /* TREETOMIRRORIMAGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

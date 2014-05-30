/****************************************************************************************************************************************************
 *  File Name   		: treeidentical.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\treeidentical.h
 *  Created on			: Apr 15, 2014 :: 2:11:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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

#ifndef TREEIDENTICAL_H_
#define TREEIDENTICAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool areTreesIdenticalTopToBottom(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	if(ptrToFirstTree->value != ptrToSecondTree->value){
		return false;
	}
	return areTreesIdenticalTopToBottom(ptrToFirstTree->left,ptrToSecondTree->left) && areTreesIdenticalTopToBottom(ptrToFirstTree->right,ptrToSecondTree->right);
}

//Tested
bool areTreesIdenticalBottomUp(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	bool areSubTreesIdentical = areTreesIdenticalBottomUp(ptrToFirstTree->left,ptrToSecondTree->left) && areTreesIdenticalBottomUp(ptrToFirstTree->right,ptrToSecondTree->right);
	return areSubTreesIdentical?(ptrToFirstTree->value == ptrToSecondTree->value?true:false):false;
}

//Tested
bool areTreesIdenticalHashmap(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapFirstTree = utils->getHashmapFormITree(ptrToFirstTree);
	itHashmap *hashmapSecondTree = utils->getHashmapFormITree(ptrToSecondTree);
	hash_map<unsigned int,itNode *> indexNodeMapFirstTree = hashmapFirstTree->indexNodeMap,indexNodeMapSecondTree = hashmapSecondTree->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMapFirstTree,itToIndexNodeMapSecondTree;

	for(itToIndexNodeMapFirstTree = indexNodeMapFirstTree.begin();itToIndexNodeMapFirstTree != indexNodeMapFirstTree.end();itToIndexNodeMapFirstTree++){
		if((itToIndexNodeMapSecondTree = indexNodeMapSecondTree.find(itToIndexNodeMapFirstTree->first)) == indexNodeMapSecondTree.end()){
			return false;
		}
		if(itToIndexNodeMapSecondTree->second->value != itToIndexNodeMapFirstTree->second->value){
			return false;
		}
	}
	return true;
}

//Tested
bool areTreesIdenticalPreInOrderNodes(itNode *ptrToFirstTree,itNode *ptrToSecondTree){
	if(ptrToFirstTree == null && ptrToSecondTree == null){
		return true;
	}
	if(ptrToFirstTree == null || ptrToSecondTree == null){
		return false;
	}
	vector<itNode *> preOrderNodesFirstTree,preOrderNodesSecondTree,inOrderNodesFirstTree,inOrderNodesSecondTree;
	treeutils *utils = new treeutils();
	utils->setVectorWithPreOrderNodes(ptrToFirstTree,preOrderNodesFirstTree);
	utils->setVectorWithPreOrderNodes(ptrToSecondTree,preOrderNodesSecondTree);
	utils->setVectorWithInOrderNodes(ptrToFirstTree,inOrderNodesFirstTree);
	utils->setVectorWithInOrderNodes(ptrToSecondTree,inOrderNodesSecondTree);
	if(preOrderNodesFirstTree.size() != preOrderNodesSecondTree.size()){
		return false;
	}
	for(unsigned int counter = 0;counter < preOrderNodesFirstTree.size();counter++){
		if(preOrderNodesFirstTree[counter]->value != preOrderNodesSecondTree[counter]->value){
			return false;
		}
	}
	for(unsigned int counter = 0;counter < inOrderNodesFirstTree.size();counter++){
		if(inOrderNodesFirstTree[counter]->value != inOrderNodesSecondTree[counter]->value){
			return false;
		}
	}
	return true;
}

bool checkIfPostOrdersAreEquivalent(itNode *firstPtr,itNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return true;
	}
	if(firstPtr == null || secondPtr == null){
		return false;
	}
	stack<itNode *> firstTreeAuxspace,secondTreeAuxspace;
	itNode *traversingFirstTreeNode = firstPtr,*traversingSecondTreeNode = secondPtr,*currentFirstTreePostOrderNode,*currentSecondTreePostOrderNode;
	while(!firstTreeAuxspace.empty() || traversingFirstTreeNode != null || !secondTreeAuxspace.empty() || traversingSecondTreeNode != null){
		currentFirstTreePostOrderNode = null;
		currentSecondTreePostOrderNode = null;
		while(!firstTreeAuxspace.empty() || traversingFirstTreeNode != null ){
			if(traversingFirstTreeNode != null){
				if(traversingFirstTreeNode->right != null){
					firstTreeAuxspace.push(traversingFirstTreeNode->right);
				}
				firstTreeAuxspace.push(traversingFirstTreeNode);
				traversingFirstTreeNode = traversingFirstTreeNode->left;
			}else{
				traversingFirstTreeNode = firstTreeAuxspace.top();
				firstTreeAuxspace.pop();
				if(!firstTreeAuxspace.empty() && firstTreeAuxspace.top() == currentFirstTreePostOrderNode->right){
					firstTreeAuxspace.pop();
					firstTreeAuxspace.push(traversingFirstTreeNode);
					traversingFirstTreeNode = traversingFirstTreeNode->right;
				}else{
					currentFirstTreePostOrderNode = traversingFirstTreeNode;
					traversingFirstTreeNode = null;
					break;
				}
			}
		}
		while(!secondTreeAuxspace.empty() || traversingSecondTreeNode != null){
			if(traversingSecondTreeNode != null){
				if(traversingSecondTreeNode->right != null){
					secondTreeAuxspace.push(traversingSecondTreeNode->right);
				}
				secondTreeAuxspace.push(traversingSecondTreeNode);
				traversingSecondTreeNode = traversingSecondTreeNode->left;
			}else{
				traversingSecondTreeNode = secondTreeAuxspace.top();
				secondTreeAuxspace.pop();
				if(!secondTreeAuxspace.empty() && secondTreeAuxspace.top() == currentSecondTreePostOrderNode->right){
					secondTreeAuxspace.pop();
					secondTreeAuxspace.push(traversingSecondTreeNode);
					traversingSecondTreeNode = traversingSecondTreeNode->right;
				}else{
					currentSecondTreePostOrderNode = traversingSecondTreeNode;
					traversingSecondTreeNode = null;
					break;
				}
			}
		}
		if(traversingFirstTreeNode == null || traversingSecondTreeNode == null){
			return false;
		}
		if(traversingFirstTreeNode->value != traversingSecondTreeNode->value){
			return false;
		}
	}
	return true;
}

bool checkIfInOrdersAreEquivalent(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstTreeAuxspace,secondTreeAuxspace;
	itNode *traversingFirstTreeNode = firstTreePtr,*traversingSecondTreeNode = secondTreePtr,*currentFirstTreeNode,*currentSecondTreeNode;
	while(!firstTreeAuxspace.empty() || traversingFirstTreeNode != null || !secondTreeAuxspace.empty() || traversingSecondTreeNode != null){
		while(!firstTreeAuxspace.empty() || traversingFirstTreeNode != null){
			if(traversingFirstTreeNode != null){
				firstTreeAuxspace.push(traversingFirstTreeNode);
				traversingFirstTreeNode = traversingFirstTreeNode->left;
			}else{
				traversingFirstTreeNode = firstTreeAuxspace.top();
				firstTreeAuxspace.pop();
				currentFirstTreeNode = traversingFirstTreeNode;
				traversingFirstTreeNode = traversingFirstTreeNode->right;
				break;
			}
		}
		while(!secondTreeAuxspace.empty() || traversingSecondTreeNode != null){
			if(traversingSecondTreeNode != null){
				secondTreeAuxspace.push(traversingSecondTreeNode);
				traversingSecondTreeNode = traversingSecondTreeNode->left;
			}else{
				traversingSecondTreeNode = secondTreeAuxspace.top();
				secondTreeAuxspace.pop();
				currentSecondTreeNode = traversingSecondTreeNode;
				traversingSecondTreeNode = traversingSecondTreeNode->right;
				break;
			}
		}
		if(currentFirstTreeNode == null || currentSecondTreeNode == null){
			return false;
		}
		if(currentFirstTreeNode->value != currentSecondTreeNode->value){
			return false;
		}
	}
	return true;
}

bool checkIfPreOrdersAreEquivalent(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	stack<itNode *> firstAuxspace,secondAuxspace;
	itNode *currentFirstNode,*currentSecondNode;
	while(!firstAuxspace.empty() || !secondAuxspace.empty()){
		currentFirstNode = null;
		currentSecondNode = null;
		if(!firstAuxspace.empty()){
			currentFirstNode = firstAuxspace.top();
			firstAuxspace.pop();
		}
		if(!secondAuxspace.empty()){
			currentSecondNode = secondAuxspace.top();
			secondAuxspace.pop();
		}
		if(currentFirstNode == null || currentSecondNode == null){
			return false;
		}
		if(currentFirstNode->value != currentSecondNode->value){
			return false;
		}
		if(currentFirstNode->right != null){
			firstAuxspace.push(currentFirstNode->right);
		}
		if(currentFirstNode->left != null){
			secondAuxspace.push(currentFirstNode->left);
		}
		if(currentSecondNode->right != null){
			firstAuxspace.push(currentSecondNode->right);
		}
		if(currentSecondNode->left != null){
			secondAuxspace.push(currentSecondNode->left);
		}
	}
	return true;
}

bool areTreesIdenticalPostInOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return checkIfPostOrdersAreEquivalent(firstTreePtr,secondTreePtr) && checkIfInOrdersAreEquivalent(firstTreePtr,secondTreePtr);
}


bool areTreesIdenticalPreInOrder(itNode *firstTreePtr,itNode *secondTreePtr){
	if(firstTreePtr == null && secondTreePtr == null){
		return true;
	}
	if(firstTreePtr == null || secondTreePtr == null){
		return false;
	}
	return checkIfPreOrdersAreEquivalent(firstTreePtr,secondTreePtr) && checkIfInOrdersAreEquivalent(firstTreePtr,secondTreePtr);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* TREEIDENTICAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

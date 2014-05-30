/****************************************************************************************************************************************************
 *  File Name   		: heightoftree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\heightoftree.h
 *  Created on			: Apr 16, 2014 :: 1:49:20 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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

#ifndef HEIGHTOFTREE_H_
#define HEIGHTOFTREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int heightOfTreePreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + max(heightOfTreePreOrder(ptr->left),heightOfTreePreOrder(ptr->right));
}

//Tested
unsigned int heightOfTreePostOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return max(heightOfTreePostOrder(ptr->left),heightOfTreePostOrder(ptr->right)) + 1;
}

//Tested
unsigned int heightOfTreeInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return max(heightOfTreeInOrder(ptr->left)+1,1+heightOfTreeInOrder(ptr->right));
}

//Tested
unsigned int heightOfTreePreOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	auxSpace.push(ptr);
	unsigned int currentTopNodeIndex;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentTopNode);
		if(itToNodeIndexMap == nodeIndexMap.end()){
			throw "Node index doesn't exists in the hash map";
		}
		currentTopNodeIndex = itToNodeIndexMap->second;
		if(currentTopNode->left != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->left,2*currentTopNodeIndex));
			auxSpace.push(currentTopNode->left);
		}
		if(currentTopNode->right != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->right,2*currentTopNodeIndex+1));
			auxSpace.push(currentTopNode->right);
		}
	}
	unsigned int maxIndex = 1;
	for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
		maxIndex = max(maxIndex,itToNodeIndexMap->second);
	}
	return log2(maxIndex)+1;
}

//Tested
unsigned int heightOfTreeMorrisPreOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	unsigned int currentNodeIndex;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(traversalNode != null){
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)traversalNode);
		if(itToNodeIndexMap == nodeIndexMap.end()){
			throw "Node doesn't exists in hash map";
		}
		currentNodeIndex = itToNodeIndexMap->second;
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversalNode->left,2*currentNodeIndex));
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				if(traversalNode->right != null){
					nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversalNode->right,2*currentNodeIndex+1));
				}
				traversalNode = traversalNode->right;
			}
		}else{
			if(traversalNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversalNode->right,2*currentNodeIndex+1));
			}
			traversalNode = traversalNode->right;
		}
	}
	unsigned int maxIndex = 1;
	for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
		maxIndex = max(maxIndex,itToNodeIndexMap->second);
	}
	return log2(maxIndex) + 1;
}

//Tested
unsigned int heightOfTreePostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentTopNode;
	unsigned int currentNodeIndex;
	primaryAuxspace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentTopNode);
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentTopNode);
		if(itToNodeIndexMap == nodeIndexMap.end()){
			throw "Node doesn't exists in hash map";
		}
		currentNodeIndex = itToNodeIndexMap->second;
		if(currentTopNode->left != null){
			primaryAuxspace.push(currentTopNode->left);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->left,2*currentNodeIndex));
		}
		if(currentTopNode->right != null){
			primaryAuxspace.push(currentTopNode->right);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->right,2*currentNodeIndex+1));
		}
	}
	unsigned int maxIndex = 1;
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentTopNode);
		if(itToNodeIndexMap == nodeIndexMap.end()){
			throw "Node doesn't exists in hash map";
		}
		maxIndex = max(maxIndex,itToNodeIndexMap->second);
	}
	return log2(maxIndex)+1;
}

//Tested
unsigned int heightOfTreePostOrderAuxspace(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int currentNodeIndex = 0,maxIndex = 1;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			currentNodeIndex = itToNodeIndexMap->second;
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentNodeIndex+1));
			}
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentNodeIndex));
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
				itToNodeIndexMap  = nodeIndexMap.find((uint32_t)currentNode);
				maxIndex = max(maxIndex,itToNodeIndexMap->second);
				currentNode = null;
			}
		}
	}
	return log2(maxIndex) + 1;
}

//Tested
unsigned int heightOfTreePostOrderTraversalIterativeV2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	unsigned int heightOfTree = 0;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == currentNode){
			currentNode = auxSpace.top();
			auxSpace.pop();
			heightOfTree = max(heightOfTree,auxSpace.size()+1);
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				heightOfTree = max(heightOfTree,auxSpace.size()+1);
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return heightOfTree;
}

//Tested
unsigned int heightOfTreeInOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	unsigned int currentNodeIndex,maxIndex = 1;

	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			currentNodeIndex = itToNodeIndexMap->second;
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentNodeIndex));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			currentNodeIndex = itToNodeIndexMap->second;
			maxIndex = max(maxIndex,currentNodeIndex);
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentNodeIndex+1));
			}
			currentNode = currentNode->right;
		}
	}
	return log2(maxIndex) + 1;
}

//Tested
unsigned int heightOfTreeMorrisInOrder(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	itNode *traversalNode = ptr,*temp;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	unsigned int currentNodeIndex,maxNodeIndex = 1;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(traversalNode != null){
		if(traversalNode->left != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)traversalNode);
			currentNodeIndex = itToNodeIndexMap->second;
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversalNode->left,2*currentNodeIndex));
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				maxNodeIndex = max(maxNodeIndex,currentNodeIndex);
				if(traversalNode->right != null){
					nodeIndexMap.insert(pair<uint32_t,unsigned int >((uint32_t)traversalNode->right,2*currentNodeIndex+1));
				}
				traversalNode = traversalNode->right;
			}
		}else{
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)traversalNode);
			currentNodeIndex = itToNodeIndexMap->second;
			maxNodeIndex = max(maxNodeIndex,currentNodeIndex);
			if(traversalNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int >((uint32_t)traversalNode->right,2*currentNodeIndex+1));
			}
			traversalNode = traversalNode->right;
		}
	}
	return log2(maxNodeIndex) + 1;
}

//Tested
unsigned int heightOfTreeLevelOrderMaxindexIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	unsigned int maxIndex = 1,currentNodeIndex;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		currentNodeIndex = itToNodeIndexMap->second;
		maxIndex = max(maxIndex,currentNodeIndex);
		if(itToNodeIndexMap == nodeIndexMap.end()){
			throw "Node doesn't exists in hash map";
		}
		if(currentNode->left != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*currentNodeIndex));
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*currentNodeIndex+1));
			auxSpace.push(currentNode->right);
		}
	}
	return log2(maxIndex) + 1;
}

//Tested
unsigned int heightOfTreeLevelOrderIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	itNode *currentFrontNode;
	auxSpace.push(ptr);
	unsigned int nodeLevelCounter = 1,heightOfTree = 0;
	while(!auxSpace.empty()){
		while(nodeLevelCounter--){
			currentFrontNode = auxSpace.front();
			auxSpace.pop();
			if(currentFrontNode->left  != null){
				auxSpace.push(currentFrontNode->left);
			}
			if(currentFrontNode->right != null){
				auxSpace.push(currentFrontNode->right);
			}
		}
		nodeLevelCounter = auxSpace.size();
		heightOfTree+=1;
	}
	return heightOfTree;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setHashmapNodeIndexLevelByLevel(itNode *ptr,itNode *parentPtr,unsigned int levelCounter,hash_map<uint32_t,unsigned int> &nodeIndexMap){
	if(ptr == null){
		return;
	}
	if(!levelCounter){
		hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap = nodeIndexMap.find((uint32_t)parentPtr);
		unsigned int parentIndex = itToNodeIndexMap->second;
		if(parentPtr->left == ptr){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*parentIndex));
		}else{
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,2*parentIndex+1));
		}
		return;
	}
	setHashmapNodeIndexLevelByLevel(ptr->left,ptr,levelCounter-1,nodeIndexMap);
	setHashmapNodeIndexLevelByLevel(ptr->right,ptr,levelCounter-1,nodeIndexMap);
}

//Tested
unsigned int heightOfTreeLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	for(unsigned int counter = 1;counter < heightOfTree;counter++){
		setHashmapNodeIndexLevelByLevel(ptr,null,counter,nodeIndexMap);
	}
	unsigned int maxIndex = 1;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	for(itToNodeIndexMap = nodeIndexMap.begin();itToNodeIndexMap != nodeIndexMap.end();itToNodeIndexMap++){
		maxIndex = max(maxIndex,itToNodeIndexMap->second);
	}
	return log2(maxIndex) + 1;
}

#endif /* HEIGHTOFTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

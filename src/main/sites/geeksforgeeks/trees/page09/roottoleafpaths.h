/****************************************************************************************************************************************************
 *  File Name   		: roottoleafpaths.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page09\roottoleafpaths.h
 *  Created on			: Apr 21, 2014 :: 11:28:09 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
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

#ifndef ROOTTOLEAFPATHS_H_
#define ROOTTOLEAFPATHS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rootToLeafPathPreOrderTraversal(itNode *ptr,queue<itNode *> auxSpace){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		itNode *traversalNode;
		while(!auxSpace.empty()){
			traversalNode = auxSpace.front();
			auxSpace.pop();
			printf("%d\t",traversalNode->value);
		}
		printf("%d\t",ptr->value);
		printf("\n");
		return;
	}
	auxSpace.push(ptr);
	rootToLeafPathPreOrderTraversal(ptr->left,auxSpace);
	rootToLeafPathPreOrderTraversal(ptr->right,auxSpace);
}

//Tested
void rootToLeafPathPreOrderParentPtr(iptNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		stack<iptNode *> auxSpace;
		while(ptr != null){
			auxSpace.push(ptr);
			ptr = ptr->parent;
		}
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		printf("\n");
		return;
	}
	rootToLeafPathPreOrderParentPtr(ptr->left);
	rootToLeafPathPreOrderParentPtr(ptr->right);
}

//Tested
void rootToLeafPathPreOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	stack<itNode *> ancestorsQueue;
	itNode *frontNode;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	unsigned int currentNodeIndex;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		frontNode = auxSpace.front();
		auxSpace.pop();
		currentNodeIndex = nodeIndexMap.find((uint32_t)frontNode)->second;
		if(frontNode->left == null && frontNode->right == null){
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				currentNodeIndex /= 2;
				ancestorsQueue.push(itToIndexNodeMap->second);
			}
			while(!ancestorsQueue.empty()){
				frontNode =ancestorsQueue.top();
				printf("%d\t",frontNode->value);
				ancestorsQueue.pop();
			}
			printf("\n");
		}else{
			if(frontNode->right != null){
				auxSpace.push(frontNode->right);
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex+1,frontNode->right));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)frontNode->right,2*currentNodeIndex+1));
			}
			if(frontNode->left != null){
				auxSpace.push(frontNode->left);
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex,frontNode->left));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)frontNode->left,2*currentNodeIndex));
			}
		}
	}
}

//Tested
void printRootToLeafInOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left == null && currentNode->right == null){
				unsigned int currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					currentNodeIndex /= 2;
					printf("%d\t",itToIndexNodeMap->second->value);
				}
				PRINT_NEW_LINE;
			}
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			}
			currentNode = currentNode->right;
		}
	}
}

//Tested
void printRootToLeafPostOrderTwoStacksIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		if(currentNode->left == null && currentNode->right == null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			unsigned int currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}
	}
}

//Tested
void rootToLeafPathsPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	unsigned int currentNodeIndex;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
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
				if(currentNode->left == null && currentNode->right == null){
					itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
					currentNodeIndex = itToNodeIndexMap->second;
					while(currentNodeIndex > 0){
						itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
						printf("%d\t",itToIndexNodeMap->second->value);
						currentNodeIndex /= 2;
					}
					PRINT_NEW_LINE;
				}
				currentNode = null;
			}
		}
	}
}

//Tested
void printStack(stack<itNode *> ancestorsStack,itNode *currentNode){
	if(ancestorsStack.empty()){
		return;
	}
	stack<itNode *> auxSpace;
	auxSpace.push(currentNode);
	while(!ancestorsStack.empty()){
		auxSpace.push(ancestorsStack.top());
		ancestorsStack.pop();
	}
	while(!auxSpace.empty()){
		printf("%d\t",auxSpace.top()->value);
		auxSpace.pop();
	}
	PRINT_NEW_LINE;
}

//Tested
void rootToLeafPathPostOrderIterativeV2(itNode *ptr){
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
			if(currentNode->left == null && currentNode->right == null){
				printStack(auxSpace,currentNode);
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->left == null && currentNode->right == null){
					printStack(auxSpace,currentNode);
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rootToLeafPathHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itIndexNodeMap,itToLeftIndexNodeMap,itToRightIndexNodeMap,itTemp;
	stack<itNode *> auxSpace;
	unsigned int currentNodeIndex;
	for(itIndexNodeMap = indexNodeMap.begin();itIndexNodeMap != indexNodeMap.end();itIndexNodeMap++){
		currentNodeIndex = itIndexNodeMap->first;
		itToLeftIndexNodeMap = indexNodeMap.find(2*currentNodeIndex);
		itToRightIndexNodeMap = indexNodeMap.find(2*currentNodeIndex+1);
		if(itToLeftIndexNodeMap == indexNodeMap.end() && itToRightIndexNodeMap == indexNodeMap.end()){
			auxSpace.push(itIndexNodeMap->second);
			currentNodeIndex /= 2;
			while(currentNodeIndex > 0){
				itTemp = indexNodeMap.find(currentNodeIndex);
				auxSpace.push(itTemp->second);
				currentNodeIndex /= 2;
			}
			while(!auxSpace.empty()){
				printf("%d\t",auxSpace.top()->value);
				auxSpace.pop();
			}
			printf("\n");
		}
	}
}

#endif /* ROOTTOLEAFPATHS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

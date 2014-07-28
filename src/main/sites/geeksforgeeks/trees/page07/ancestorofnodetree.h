/****************************************************************************************************************************************************
 *  File Name   		: ancestorofnodetree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\ancestorofnodetree.h
 *  Created on			: May 1, 2014 :: 7:43:39 PM
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

#ifndef ANCESTOROFNODETREE_H_
#define ANCESTOROFNODETREE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool printAncestorsON(itNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		printf("%d\t",ptr->value);
		return true;
	}
	if(printAncestorsON(ptr->left,value) || printAncestorsON(ptr->right,value)){
		printf("%d\t",ptr->value);
	}
}

void printAncestorsAuxspace(itNode *ptr,int keyValue,queue<itNode *> auxSpace){
	if(ptr == null){
		return;
	}
	auxSpace.push(ptr);
	if(ptr->value == keyValue){
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.front()->value);
			auxSpace.pop();
		}
		return;
	}
	printAncestorsAuxspace(ptr->left,keyValue,auxSpace);
	printAncestorsAuxspace(ptr->right,keyValue,auxSpace);
}

void printAncestorParentPtr(iptNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	if(ptr->value == keyValue){
		stack<itNode *> auxSpace;
		while(ptr != null){
			auxSpace.push(ptr);
			ptr = ptr->parent;
		}
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.top()->value);
			auxSpace.pop();
		}
		return;
	}
	printAncestorParentPtr(ptr->left,keyValue);
	printAncestorParentPtr(ptr->right,keyValue);
}

void printAncestorHashmap(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int currentNodeIndex;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->second->value == keyValue){
			currentNodeIndex = itToIndexNodeMap->first;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
				return;
			}
		}
	}
}

void printAncestorsPostOrderIterativeV2(itNode *ptr,int keyValue){
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
		if(!auxSpace.empty() || auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value == keyValue){
				while(!auxSpace.empty()){
					printf("%d\t",auxSpace.top()->value);
					auxSpace.pop();
				}
				return;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(currentNode->value == keyValue){
					while(!auxSpace.empty()){
						printf("%d\t",auxSpace.top()->value);
						auxSpace.pop();
					}
				}
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

void printAncestorsOfNodePreOrderIterative(itNode *ptr,int value){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->value == value){
			unsigned int currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}
		if(currentNode->right != null){
			nodeIndexMap.find((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1);
			indexNodeMap.find(2*itToNodeIndexMap->second+1,currentNode->right);
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			nodeIndexMap.find((uint32_t)currentNode->left,2*itToNodeIndexMap->second);
			indexNodeMap.find(2*itToNodeIndexMap->second,currentNode->left);
			auxSpace.push(currentNode->left);
		}
	}
}

void printAncestorsInOrderIterative(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value == keyValue){
				itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
				unsigned int currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					printf("%d\t",itToIndexNodeMap->second->value);
					currentNodeIndex /= 2;
				}
			}
			if(currentNode->right != null){
				itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			}
			currentNode = currentNode->right;
		}
	}
}

void printAncestorsOfNodePostOrderIterativeTwoStacks(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode;
	primaryAuxspace.push(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			nodeIndexMap.insert((uint32_t)currentNode->left,2*itToNodeIndexMap->second);
			indexNodeMap.insert(2*itToNodeIndexMap->second,currentNode->left);
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			nodeIndexMap.insert((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1);
			indexNodeMap.insert(2*itToNodeIndexMap->second+1,currentNode->right);
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode  = secondaryAuxspace.top();
		if(currentNode->value == keyValue){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			unsigned int currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}
		secondaryAuxspace.pop();
	}
}

void printAncestorsOfNodePostOrderIterative(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert((uint32_t)ptr,1);
	indexNodeMap.insert(1,ptr);
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
				auxSpace.push(currentNode->right);
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
				auxSpace.top();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				if(currentNode->value == keyValue){
					unsigned int currentNodeIndex;
					itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
					currentNodeIndex = itToNodeIndexMap->second;
					while(currentNodeIndex > 0){
						itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
						printf("%d\t",itToIndexNodeMap->second->value);
						currentNodeIndex /= 2;
					}
					return;
				}
				currentNode = null;
			}
		}
	}
}

void ancestorsOfNodePostOrderIterativeV2(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			}
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() ||auxSpace.top()->right == null){
			currentNode  = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value == keyValue){
				itToNodeIndexMap = nodeIndexMap.find(currentNode);
				unsigned int currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					printf("%d\t",itToIndexNodeMap->second->value);
					currentNodeIndex /= 2;
				}
				PRINT_NEW_LINE;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(currentNode->value == keyValue){
					itToNodeIndexMap = nodeIndexMap.find(currentNode);
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
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)auxSpace.top());
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,2*itToNodeIndexMap->second+1));
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode));
		}
	}
}

void ancestorsOfNodeLevelOrderIterative(itNode *ptr,int keyValue){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	unsigned int currentLevelSize;
	while(!auxSpace.empty()){
		currentLevelSize = auxSpace.size();
		while(currentLevelSize--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->value == keyValue){
				unsigned int currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					printf("%d\t",itToIndexNodeMap->second->value);
					currentNodeIndex /= 2;
				}
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			}
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

bool checkIfNodeIsAncestor(itNode *ptr,int value){
	if(ptr == null){
		return false;
	}
	if(ptr->value == value){
		return true;
	}
	return checkIfNodeIsAncestor(ptr->left,value) || checkIfNodeIsAncestor(ptr->right,value);
}

void printAncestorON2(itNode *ptr,int value){
	if(ptr == null){
		return;
	}
	if(checkIfNodeIsAncestor(ptr,value)){
		printf("%d\t",ptr->value);
		printAncestorON2(ptr->left,value);
		printAncestorON2(ptr->right,value);
	}
}

#endif /* ANCESTOROFNODETREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

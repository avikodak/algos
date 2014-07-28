/****************************************************************************************************************************************************
 *  File Name   		: roottoleafpaths.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\roottoleafpaths.h
 *  Created on			: May 1, 2014 :: 7:41:50 PM
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

#ifndef ROOTTOLEAFPATHS_H_
#define ROOTTOLEAFPATHS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void rootToLeafPathsON(itNode *ptr,queue<itNode *> auxSpace){
	if(ptr == null){
		return;
	}
	auxSpace.push(ptr);
	if(ptr->left == null && ptr->right == null){
		while(!auxSpace.empty()){
			printf("%d\t",auxSpace.front()->value);
		}
		printf("\n");
	}
	rootToLeafPathsON(ptr->left,auxSpace);
	rootToLeafPathsON(ptr->right,auxSpace);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void rootToLeafPathPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	unsigned int currentNodeIndex;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left == null && currentNode->right == null){
			currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}
		if(currentNode->right != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			auxSpace.push(currentNode->left);
		}
	}
}

void printRootToLeafPathInOrderIterative(itNode *ptr){
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
		if(currentNode != null){
			auxSpace.push(currentNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToIndexNodeMap,currentNode->left));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left == null && currentNode->right == null){
				unsigned int currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					printf("%d\t",itToIndexNodeMap->second->value);
					currentNodeIndex /= 2;
				}
				PRINT_NEW_LINE;
			}
			auxSpace.pop();
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap+1));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToIndexNodeMap+1,currentNode->right));
			}
			currentNode = currentNode->right;
		}
	}
}

void rootToLeafPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode = ptr;
	primaryAuxspace.push(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left == null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			indexNodeMap.insert(2*itToNodeIndexMap->second,currentNode->left);
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right == null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			indexNodeMap.insert(2*itToNodeIndexMap->second+1,currentNode->right);
			primaryAuxspace.push(currentNode->right);
		}
	}
	unsigned int currentNodeIndex;
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		if(currentNode->left == null  && currentNode->right == null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}
	}
}

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
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
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
			if(!auxSpace.empty() && auxSpace.top() == currentNode->right){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
				currentNodeIndex = itToNodeIndexMap->second;
				while(currentNodeIndex > 0){
					currentNodeIndex /= 2;
				}
				currentNode = null;
			}
		}
	}
}

void rootToLeafPostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,currentNode));
	unsigned int currentNodeIndex;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
			}
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode =  auxSpace.top();
			auxSpace.pop();
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
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				auxSpace.pop();
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
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)auxSpace.top());
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
		}
	}
}

void rootToLeafPathLevelOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	unsigned int currentNodeIndex;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left == null && currentNode->right == null){
			currentNodeIndex = itToNodeIndexMap->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				printf("%d\t",itToIndexNodeMap->second->value);
				currentNodeIndex /= 2;
			}
			PRINT_NEW_LINE;
		}else{
			if(currentNode->left != null){
				nodeIndexMap.insert((uint32_t)currentNode->left,2*(itToNodeIndexMap->second));
				indexNodeMap.insert(2*itToNodeIndexMap->second,currentNode->left);
			}
			if(currentNode->right != null){
				nodeIndexMap.insert((uint32_t)currentNode->right,2*(itToNodeIndexMap->second)+1);
				indexNodeMap.insert(2*itToNodeIndexMap->second+1,currentNode->right);
			}
		}
	}
}

void printRootToLeafMorrisOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *currentNode = ptr,*temp;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	unsigned int currentNodeIndex;
	while(currentNode != null){
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right == currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second,currentNode->left));
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				if(temp->left == null && temp->right == null){
					itToNodeIndexMap = nodeIndexMap.find(temp);
					currentNodeIndex = itToNodeIndexMap->second;
					while(currentNodeIndex > 0){
						itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
						printf("%d\t",itToIndexNodeMap->second->value);
						currentNodeIndex /= 2;
					}
					PRINT_NEW_LINE;
				}
				currentNode = currentNode->right;
			}
		}else{
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			indexNodeMap.insert(pair<unsigned int,itNode *>(2*itToNodeIndexMap->second+1,currentNode->right));
			currentNode = currentNode->right;
		}
	}
}

#endif /* ROOTTOLEAFPATHS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

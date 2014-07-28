/****************************************************************************************************************************************************
 *  File Name   		: nodelevel.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\nodelevel.h
 *  Created on			: May 1, 2014 :: 7:43:19 PM
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

#ifndef NODELEVEL_H_
#define NODELEVEL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getLevelOfNode(itNode *ptr,int value,unsigned int runningLevel){
	if(ptr == null){
		return UINT_MAX;
	}
	if(ptr->value == value){
		return runningLevel;
	}
	unsigned int leftReturnedVal = getLevelOfNode(ptr->left,value,runningLevel+1);
	if(leftReturnedVal != UINT_MAX){
		return leftReturnedVal;
	}
	return getLevelOfNode(ptr->right,value,runningLevel+1);
}

unsigned int getLevelOfNodeAncestors(itNode *ptr,int value,stack<itNode *> auxSpace){
	if(ptr == null){
		return UINT_MAX;
	}
	if(ptr->value == value){
		return auxSpace.size()+1;
	}
	auxSpace.push(ptr);
	unsigned int leftValue = getLevelOfNodeAncestors(ptr->left,value,auxSpace);
	if(leftValue != UINT_MAX){
		return leftValue;
	}
	return getLevelOfNodeAncestors(ptr->right,value,auxSpace);
}

unsigned int getLevelOfNodePreOrderIterative(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	itNode *currentNode;
	stack<itNode *> auxSpace;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->value == value){
			return log2(itToNodeIndexMap->second)+1;
		}
		if(currentNode->right != null){
			auxSpace.push(currentNode->right);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((currentNode->right,2*itToNodeIndexMap->second+1)));
		}
		if(currentNode->left != null){
			auxSpace.push(currentNode->left);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((currentNode->left,2*itToNodeIndexMap->first+1)));
		}
	}
	return UINT_MAX;
}

unsigned int getLevelOfNodeMorrisPreOrder(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	itNode *currentNode = ptr,*temp;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(currentNode != null){
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				if(currentNode->value == null){
					return log2(itToNodeIndexMap->second)+1;
				}
				temp->right = currentNode;
			}else{

			}
		}else{
			currentNode = currentNode->right;
		}
	}
}

unsigned int getLevelOfNodeInOrderIterative(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,1));
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->value == value){
				return log2(itToNodeIndexMap->second)+1;
			}
			auxSpace.pop();
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			}
			currentNode = currentNode->right;
		}
	}
	return UINT_MAX;
}

//incomplete
unsigned int getLevelOfNodeMorrisInorder(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	itNode *currentNode = ptr,*temp;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(currentNode != null){
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
				currentNode = currentNode->left;
			}else{

			}
		}else{
			if(currentNode->value == value){
				return itToNodeIndexMap->second;
			}
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			}
			currentNode = currentNode->right;
		}
	}
}

unsigned int getLevelOfNodePostOrderIterativeTwoStacks(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> primaryAuxSpace,secondaryAuxSpace;
	itNode *currentNode;
	primaryAuxSpace.push(ptr);
	while(!primaryAuxSpace.empty()){
		currentNode = primaryAuxSpace.top();
		primaryAuxSpace.pop();
		secondaryAuxSpace.push(currentNode);
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			primaryAuxSpace.push(currentNode->left);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
		}
		if(currentNode->right != null){
			primaryAuxSpace.push(currentNode->right);
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
		}
	}
	while(!secondaryAuxSpace.empty()){
		currentNode = secondaryAuxSpace.top();
		secondaryAuxSpace.pop();
		if(currentNode->value == value){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			return log2(itToNodeIndexMap->second)+1;
		}
	}
	return UINT_MAX;
}

unsigned int getLevelOfNodePostOrderIterative(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap));
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
				if(currentNode->value == value){
					itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
					return log2(itToNodeIndexMap->second)+1;
				}
				currentNode = null;
			}
		}
	}
	return UINT_MAX;
}

unsigned int getLevelOfNodePostOrderIterativeV2(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,1));
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
			if(currentNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			}
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->value == value){
				itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
				return log2(itToNodeIndexMap->second)+1;
			}
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->value == value){
					itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
					return log2(itToNodeIndexMap->second)+1;
				}
				auxSpace.pop();
			}
		}
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
		if(currentNode != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
		}
	}
}

unsigned int getLevelOfNodePostOrderIterativeAncestorsV2(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
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
			if(currentNode->value == value){
				return auxSpace.size();
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->value == value){
					return auxSpace.size();
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return UINT_MAX;
}

unsigned int getLevelOfNodeHashmap(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false);
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->second->value == value){
			return log2(itToIndexNodeMap->first) + 1;
		}
	}
	return UINT_MAX;
}

unsigned int getLevelOfNodeO2N(itNode *ptr,int value){
	if(ptr == null){
		return UINT_MAX;
	}
	treeutils *utils = new treeutils();
	static unsigned int height = utils->heightOfTree(ptr);
	if(ptr->value == value){
		unsigned int currentSubTreeHeight = utils->heightOfTree(ptr);
		return height-currentSubTreeHeight;
	}
	unsigned int leftReturnedVal = getLevelOfNodeON2(ptr->left,value);
	if(leftReturnedVal != UINT_MAX){
		return leftReturnedVal;
	}
	return getLevelOfNodeON2(ptr->right,value);
}

unsigned int getLevelOrNodeHashmap(itNode *ptr,int value){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(itToIndexNodeMap->second->value == value){
			return log2(itToIndexNodeMap->first) + 1;
		}
	}
}

#endif /* NODELEVEL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: roottoleafsum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\roottoleafsum.h
 *  Created on			: May 1, 2014 :: 8:24:14 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
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

#ifndef ROOTTOLEAFSUM_H_
#define ROOTTOLEAFSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool checkForSumRootToLeafPreOrder(itNode *ptr,int sum){
	if(ptr == null){
		return false;
	}
	if(ptr->left == null && ptr->right == null){
		return sum - ptr->value == 0?true:false;
	}
	return checkForSumRootToLeafPreOrder(ptr->left,sum-ptr->value) || checkForSumRootToLeafPreOrder(ptr->right,sum - ptr->value);
}

//Tested
bool checkForSumRootToLeafParentPtr(iptNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	if(ptr->left == null && ptr->right == null){
		int sum = 0;
		while(ptr != null){
			sum += ptr->value;
			ptr = ptr->parent;
		}
		return sum == key?true:false;
	}
	return checkForSumRootToLeafParentPtr(ptr->left,key) || checkForSumRootToLeafParentPtr(ptr->right,key);
}

//Tested
bool checkForSumRootToLeafPreOrderIterative(itNode *ptr,int sum){
	if(ptr == null){
		return false;
	}
	hash_map<unsigned int,itNode *> indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentTopNode,*currentNode;
	auxSpace.push(ptr);
	indexNodeMap.insert(pair<unsigned int,itNode *>(1,ptr));
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	int currentPathSum;
	unsigned int currentNodeIndex;
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentTopNode);
		currentNodeIndex = itToNodeIndexMap->second;
		if(currentTopNode->left == null && currentTopNode->right == null){
			currentPathSum = 0;
			while(currentNodeIndex > 0){
				currentNode = indexNodeMap.find(currentNodeIndex)->second;
				currentPathSum += currentNode->value;
				currentNodeIndex /= 2;
			}
			if(currentPathSum == sum){
				return true;
			}
		}else{
			if(currentTopNode->right != null){
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex+1,currentTopNode->right));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->right,2*currentNodeIndex + 1));
				auxSpace.push(currentTopNode->right);
			}
			if(currentTopNode->left != null){
				indexNodeMap.insert(pair<unsigned int,itNode *>(2*currentNodeIndex,currentTopNode->left));
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentTopNode->left,2*currentNodeIndex));
				auxSpace.push(currentTopNode->left);
			}
		}
	}
	return false;
}

//Tested
bool checkForSumRootToLeafInOrderIterative(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapTree= utils->getHashmapFormITree(ptr,false);
	hash_map<unsigned int,itNode *> indexNodeMap = hashmapTree->indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap = hashmapTree->nodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int sum;
	unsigned int currentNodeIndex;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->left == null && currentNode->right == null){
				currentNodeIndex = nodeIndexMap.find((uint32_t)currentNode)->second;
				sum = 0;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					sum += itToIndexNodeMap->second->value;
					currentNodeIndex /= 2;
				}
				if(sum == key){
					return true;
				}
			}
			currentNode = currentNode->right;
		}
	}
	return false;
}

//Tested
bool checkForSumRootToLeafPostOrderTwoStacks(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapTree= utils->getHashmapFormITree(ptr,false);
	hash_map<unsigned int,itNode *> indexNodeMap = hashmapTree->indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap = hashmapTree->nodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentTopNode;
	int sum;
	unsigned int currentNodeIndex;
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
		if(currentTopNode->left == null && currentTopNode->right == null){
			currentNodeIndex = nodeIndexMap.find((uint32_t)currentTopNode)->second;
			sum = 0;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				sum += itToIndexNodeMap->second->value;
				currentNodeIndex /= 2;
			}
			if(sum == key){
				return true;
			}
		}
	}
	return false;
}

//Tested
bool checkForSumRootToLeafSumPostOrderIterative(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapTree= utils->getHashmapFormITree(ptr,false);
	hash_map<unsigned int,itNode *> indexNodeMap = hashmapTree->indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap = hashmapTree->nodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int sum;
	unsigned int currentNodeIndex;
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
				currentNodeIndex = nodeIndexMap.find((uint32_t)currentNode)->second;
				sum = 0;
				while(currentNodeIndex > 0){
					itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
					sum += itToIndexNodeMap->second->value;
					currentNodeIndex /= 2;
				}
				if(sum == key){
					return true;
				}
				currentNode = NULL;
			}
		}
	}
	return false;
}

//Tested
bool rootToLeafSumAncestorstack(stack<itNode *> auxSpace,int requiredSum){
	if(auxSpace.empty()){
		return false;
	}
	int currentSum = 0;
	while(!auxSpace.empty()){
		currentSum += auxSpace.top()->value;
		auxSpace.pop();
	}
	return requiredSum == currentSum;
}

//Tested
bool checkForRootToLeafSumPostOrderIterativeV2(itNode *ptr,int requiredSum){
	if(ptr == null){
		return false;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	while(!auxSpace.empty() || currentNode != null){
		while(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}
		if(auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			if(currentNode->left == null && currentNode->right == null){
				if(rootToLeafSumAncestorstack(auxSpace,requiredSum)){
					return true;
				}
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				if(currentNode->left == null && currentNode->right == null){
					if(rootToLeafSumAncestorstack(auxSpace,requiredSum)){
						return true;
					}
				}
				auxSpace.pop();
			}
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return false;
}

//Tested
bool checkForSumRootToLeafSumHashmap(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap,itToLeftIndexNodeMap,itToRightIndexNodeMap,itToTempIndexNodeMap;
	unsigned int currentNodeIndex;
	int sum;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeIndex = itToIndexNodeMap->first;
		itToLeftIndexNodeMap = indexNodeMap.find(2*currentNodeIndex);
		itToRightIndexNodeMap = indexNodeMap.find(2*currentNodeIndex+1);
		if(itToLeftIndexNodeMap == indexNodeMap.end() && itToRightIndexNodeMap == indexNodeMap.end()){
			sum = 0;
			while(currentNodeIndex > 0){
				itToTempIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				sum += itToTempIndexNodeMap->second->value;
				currentNodeIndex /= 2;
			}
			if(key == sum){
				return true;
			}
		}
	}
	return false;
}

//Tested
bool checkForSumRootToLeafSumLevelorder(itNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	treeutils *utils = new treeutils();
	itHashmap *hashmapTree= utils->getHashmapFormITree(ptr,false);
	hash_map<unsigned int,itNode *> indexNodeMap = hashmapTree->indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap = hashmapTree->nodeIndexMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	queue<itNode *> auxSpace;
	itNode *currentFrontNode;
	int sum;
	unsigned int currentNodeIndex;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentFrontNode = auxSpace.front();
		auxSpace.pop();
		if(currentFrontNode->left == null && currentFrontNode->right == null){
			sum = 0;
			currentNodeIndex = nodeIndexMap.find((uint32_t)currentFrontNode)->second;
			while(currentNodeIndex > 0){
				itToIndexNodeMap = indexNodeMap.find(currentNodeIndex);
				sum += itToIndexNodeMap->second->value;
				currentNodeIndex /= 2;
			}
			if(sum == key){
				return true;
			}
		}else{
			if(currentFrontNode->left != null){
				auxSpace.push(currentFrontNode->left);
			}
			if(currentFrontNode->right != null){
				auxSpace.push(currentFrontNode->right);
			}
		}
	}
	return false;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ROOTTOLEAFSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

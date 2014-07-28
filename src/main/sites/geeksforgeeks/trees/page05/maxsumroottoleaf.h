/****************************************************************************************************************************************************
 *  File Name   		: maxsumroottoleaf.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\maxsumroottoleaf.h
 *  Created on			: May 16, 2014 :: 12:13:47 AM
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

#ifndef MAXSUMROOTTOLEAF_H_
#define MAXSUMROOTTOLEAF_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int maxSumRootToLeaf(itNode *ptr,int sumancestors){
	if(ptr->value == null){
		return INT_MIN;
	}
	if(ptr->left == null && ptr->right == null){
		return sumancestors + ptr->value;
	}
	return max(maxSumRootToLeaf(ptr->left,sumancestors+ptr->value),maxSumRootToLeaf(ptr->right,sumancestors + ptr->value));
}

int maxSumRootToLeafPreOrderIterative(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	auxSpace.push(ptr);
	nodeSumMap.insert(pair<uint32_t,int>((uint32_t)ptr,ptr->value));
	int maxSum = INT_MIN;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
		if(currentNode->left == null && currentNode->right == null){
			maxSum = max(maxSum,itToNodeSumMap->second);
		}else{
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
				nodeSumMap.insert((uint32_t)currentNode->right,itToNodeSumMap->second + currentNode->right->value);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
				nodeSumMap.insert((uint32_t)currentNode->left,itToNodeSumMap->second + currentNode->left->value);
			}
		}
	}
	return maxSum;
}

int maxSumRootToLeafMorrisPreOrder(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	itNode *currentNode = ptr,*temp;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	nodeSumMap.insert(pair<uint32_t,int>((uint32_t)ptr,ptr->value));
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null || temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				if(temp->left == null){

				}
				currentNode = currentNode->right;
			}
		}else{
			currentNode = currentNode->right;
		}
	}
}

int maxSumRootToLeafInorderIterative(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode,currentNode->value));
	int maxSumRootToLeaf = INT_MIN;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
				nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->left),itToNodeSumMap->second + currentNode->left->value);
			}
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
			if(currentNode->right == null){
				if(currentNode->left == null){
					maxSumRootToLeaf = max(maxSumRootToLeaf,itToNodeSumMap->second);
				}
			}else{
				nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->right),itToNodeSumMap->second + currentNode->right->value);
			}
			currentNode = currentNode->right;
		}
	}
	return maxSumRootToLeaf;
}

int maxSumRootToLeafPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	nodeSumMap.insert(pair<uint32_t,int>((uint32_t)ptr,ptr->value));
	primaryAuxspace.push(ptr);
	int maxSumRootToLeaf = INT_MIN;
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
			nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->left,itToNodeSumMap->second + currentNode->left->value));
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
			nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->right,itToNodeSumMap->second + currentNode->right->value));
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		if(currentNode->left == null && currentNode->right == null){
			itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
			maxSumRootToLeaf = max(maxSumRootToLeaf,itToNodeSumMap->second);
		}
	}
	return maxSumRootToLeaf;
}

int maxSumRootToLeafPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,int> nodeSumMap;
	hash_map<uint32_t,int>::iterator itToNodeSumMap;
	nodeSumMap.insert(pair<uint32_t,int>((uint32_t)ptr,ptr->value));
	int maxSumRootToLeaf = INT_MIN;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
			if(currentNode->right != null){
				nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->right,itToNodeSumMap->second + currentNode->right->value));
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left != null){
				nodeSumMap.insert(pair<uint32_t,int>((uint32_t)currentNode->left,itToNodeSumMap->second + currentNode->left->value));
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
				if(currentNode->left == null && currentNode->right == null){
					itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
					maxSumRootToLeaf = max(maxSumRootToLeaf,itToNodeSumMap->second);
				}
				currentNode = null;
			}
		}
	}
	return maxSumRootToLeaf;
}

int maxSumRootToLeafLevelOrder(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	hash_map<uint32_t,itNode *> nodeSumMap;
	hash_map<uint32_t,itNode *>::iterator itToNodeSumMap;
	nodeSumMap.insert(pair<uint32_t,itNode *>((uint32_t)ptr,ptr->value));
	int maxSumRootToLeaf = INT_MIN;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		itToNodeSumMap = nodeSumMap.find((uint32_t)currentNode);
		auxSpace.pop();
		if(currentNode->left == null && currentNode->right == null){
			maxSumRootToLeaf = max(maxSumRootToLeaf,itToNodeSumMap->second);
		}else{
			if(currentNode->left != null){
				nodeSumMap.insert(pair<uint32_t,itNode *>((uint32_t)currentNode->left,currentNode->left->value));
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				nodeSumMap.insert(pair<uint32_t,itNode *>((uint32_t)currentNode->right,currentNode->right->value));
				auxSpace.push(currentNode->right);
			}
		}
	}
	return maxSumRootToLeaf;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

int maxSumRootToLeafLevelByLevel(itNode *ptr,hash_map<uint32_t,int> &nodeSumMap,unsigned int levelIndex){
	if(ptr == null){
		return INT_MIN;
	}
	if(ptr->left == null && ptr->right == null){
		return nodeSumMap.find((uint32_t)ptr)->second;
	}
	hash_map<uint32_t,int>::iterator itToNodeSumMap = nodeSumMap.find(ptr);
	if(ptr->left != null){
		nodeSumMap.insert(pair<uint32_t,int>(ptr->left,itToNodeSumMap->second + ptr->left->value));
	}
	if(ptr->right != null){
		nodeSumMap.insert(pair<uint32_t,int>(ptr->right,itToNodeSumMap->second + ptr->right->value));
	}
	return max(maxSumRootToLeafLevelByLevel(ptr->left,nodeSumMap,levelIndex-1),maxSumRootToLeafLevelByLevel(ptr->right,nodeSumMap,levelIndex-1));
}

int maxSumRootToLeafLevelOrderON2(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	int heightOfTree = utils->heightOfTree(ptr);
	hash_map<uint32_t,int> nodeSumMap;
	int maxValue = INT_MIN;
	for(unsigned int counter = 0;counter < heightOfTree;counter++){
		nodeSumMap.insert(pair<uint32_t,int>((uint32_t)ptr,ptr->value));
		maxValue = max(maxValue,maxSumRootToLeafLevelByLevel(ptr,nodeSumMap,counter));
	}
	return maxValue;
}

#endif /* MAXSUMROOTTOLEAF_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

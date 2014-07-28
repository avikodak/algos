/****************************************************************************************************************************************************
 *  File Name   		: printleftview.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page02\printleftview.h
 *  Created on			: Jun 30, 2014 :: 12:09:31 PM
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

#ifndef PRINTLEFTVIEW_H_
#define PRINTLEFTVIEW_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printLeftViewON(itNode *ptr,unsigned int &maxSeenLevel = UINT_MIN,unsigned int currentLevel){
	if(ptr == null){
		return;
	}
	if(currentLevel == 0){
		printf("%d\n",ptr->value);
	}
	if(currentLevel > maxSeenLevel){
		currentLevel = maxSeenLevel;
	}
	printLeftViewON(ptr->left,maxSeenLevel,currentLevel+1);
	printLeftViewON(ptr->right,maxSeenLevel,currentLevel+1);
}

void printLeftViewON(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int sizeOfLevel;
	while(!auxSpace.empty()){
		sizeOfLevel = auxSpace.size();
		printf("%d\n",auxSpace.front()->value);
		while(sizeOfLevel--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
	}
}

void preOrderTraversalLeftView(itNode *ptr,unsigned int currentNodeLevel){
	if(ptr == null){
		return;
	}
	static hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	if((itToLevelFlags = levelFlags.find(currentNodeLevel)) == levelFlags.end()){
		printf("%d\n",ptr->value);
		levelFlags.insert(pair<unsigned int,bool>(currentNodeLevel,true));
	}
	preOrderTraversalLeftView(ptr->left,currentNodeLevel+1);
	preOrderTraversalLeftView(ptr->right,currentNodeLevel+1);
}

void preOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	auxSpace.push(ptr);
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		itToNodeIndexMap = nodeIndexMap.find((uint32_t)currentNode);
		if((itToLevelFlags = levelFlags.find(log2(itToNodeIndexMap->second))) == levelFlags.end()){
			printf("%d\n",currentNode->value);
			levelFlags[log2(itToNodeIndexMap->second)] = true;
		}
		if(currentNode->right != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,2*itToNodeIndexMap->second+1));
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != null){
			nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,2*itToNodeIndexMap->second));
			auxSpace.push(currentNode->left);
		}
	}
}

void inOrderTraversalLeftView(itNode *ptr,unsigned int currentNodeLevel){
	if(ptr == null){
		return;
	}
	static hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	inOrderTraversalLeftView(ptr->left,currentNodeLevel+1);
	if((itToLevelFlags = levelFlags.find(currentNodeLevel)) == levelFlags.end()){
		printf("%d\n",ptr->value);
		levelFlags.insert(pair<unsigned int,bool>(currentNodeLevel,true));
	}
	inOrderTraversalLeftView(ptr->right,currentNodeLevel+1);
}

void inOrderTraversalLeftViewIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<uint32_t,unsigned int> nodeIndexMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeIndexMap;
	hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	stack<itNode *> auxSpace;
	itNode *traversingNode = ptr;
	nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty() || traversingNode != null){
		if(traversingNode != null){
			auxSpace.push(traversingNode);
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)traversingNode);
			if(traversingNode->left != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversingNode->left,2*itToNodeIndexMap->second));
			}
			traversingNode = traversingNode->left;
		}else{
			traversingNode = auxSpace.top();
			auxSpace.pop();
			itToNodeIndexMap = nodeIndexMap.find((uint32_t)traversingNode);
			if((itToLevelFlags = levelFlags.find(log2(itToNodeIndexMap->second))) == levelFlags.end()){
				printf("%d\n",traversingNode->value);
				levelFlags.insert(pair<unsigned int,bool>(log2(itToNodeIndexMap->second),true));
			}
			if(traversingNode->right != null){
				nodeIndexMap.insert(pair<uint32_t,unsigned int>((uint32_t)traversingNode->right,2*itToNodeIndexMap->second+1));
			}
			traversingNode = traversingNode->right;
		}
	}
}

void postOrderIterativeTwoStacksLeftView(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	hash_map<unsigned int,bool> levelFlag;
	hash_map<unsigned int,bool>::iterator itToLevelFlag;
	itNode *currentNode;
	primaryAuxspace.push(ptr);
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,0));
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,itToNodeLevelMap->second+1));
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,itToNodeLevelMap->second+1));
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
		if((itToLevelFlag = levelFlag.find(itToNodeLevelMap->second)) == levelFlag.end()){
			printf("%d\n",currentNode->value);
			levelFlag.insert(itToNodeLevelMap->second,true);
		}
		secondaryAuxspace.pop();
	}
}

void postOrderIterativeLeftView(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)ptr,1));
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
			if(currentNode->right != null){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->right,itToNodeLevelMap->second+1));
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode->left,itToNodeLevelMap->second+1));
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
				itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
				if((itToLevelFlags = levelFlags.find(itToNodeLevelMap->second)) == levelFlags.end()){
					printf("%d\n",currentNode->value);
				}
				currentNode = null;
			}
		}
	}
}

void postOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	hash_map<uint32_t,unsigned int> nodeLevelMap;
	hash_map<uint32_t,unsigned int>::iterator itToNodeLevelMap;
	hash_map<unsigned int,bool> levelFlags;
	hash_map<unsigned int,bool>::iterator itToLevelFlags;
	nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,1));
	while(!auxSpace.empty()){
		while(currentNode != null){
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
			auxSpace.push(currentNode);
			if(currentNode->left != null){
				nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)currentNode,itToNodeLevelMap->second+1));
			}
			currentNode = currentNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			currentNode = auxSpace.top();
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
			if((itToLevelFlags == levelFlags.find(itToNodeLevelMap->second)) == nodeLevelMap.end()){
				printf("%d\n",currentNode->value);
				nodeLevelMap.insert(pair<unsigned int,bool>(itToNodeLevelMap->second,true));
			}
			auxSpace.pop();
			while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
				currentNode = auxSpace.top();
				itToNodeLevelMap = nodeLevelMap.find((uint32_t)currentNode);
				if((itToLevelFlags == levelFlags.find(itToNodeLevelMap->second)) == nodeLevelMap.end()){
					printf("%d\n",currentNode->value);
					nodeLevelMap.insert(pair<unsigned int,bool>(itToNodeLevelMap->second,true));
				}
				auxSpace.pop();
			}
		}
		if(!auxSpace.empty() && auxSpace.top()->right != null){
			itToNodeLevelMap = nodeLevelMap.find((uint32_t)auxSpace.top());
			nodeLevelMap.insert(pair<uint32_t,unsigned int>((uint32_t)auxSpace.top()->right,itToNodeLevelMap->second+1));
		}
		currentNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* PRINTLEFTVIEW_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

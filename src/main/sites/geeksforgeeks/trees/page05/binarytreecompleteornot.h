/****************************************************************************************************************************************************
 *  File Name   		: binarytreecompleteornot.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\binarytreecompleteornot.h
 *  Created on			: May 28, 2014 :: 4:26:23 PM
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

#ifndef BINARYTREECOMPLETEORNOT_H_
#define BINARYTREECOMPLETEORNOT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setLevelNodeCounterHashmap(itNode *ptr,hash_map<unsigned int,unsigned int> &levelCounter,unsigned int currentLevel){
	if(ptr == null){
		return;
	}
	hash_map<unsigned int,unsigned int>::iterator itToLevelCounter;
	if((itToLevelCounter = levelCounter.find(currentLevel)) != levelCounter.end()){
		levelCounter[currentLevel] += 1;
	}else{
		levelCounter[currentLevel] = 1;
	}
	setLevelNodeCounterHashmap(ptr->left,levelCounter,currentLevel+1);
	setLevelNodeCounterHashmap(ptr->right,levelCounter,currentLevel+1);
}


bool isTreeComplete(itNode *ptr){
	if(ptr == null){
		return true;
	}
	hash_map<unsigned int,unsigned int> levelCounter;
	hash_map<unsigned int,unsigned int>::iterator itToLevelCounter;
	setLevelNodeCounterHashmap(ptr,levelCounter,0);
	for(itToLevelCounter = levelCounter.begin();itToLevelCounter != levelCounter.end()-1;itToLevelCounter++){
		if(itToLevelCounter->second != pow(2,itToLevelCounter->first)){
			return false;
		}
	}
	unsigned int lastLevelStartIndex = pow(2,itToLevelCounter->first-1)+1;
	if(itToLevelCounter->second == pow(2,itToLevelCounter->first)){
		return true;
	}
	return true;
}

bool isTreeCompleteON(itNode *ptr,unsigned int level){
	if(ptr == null){
		return true;
	}
	static int firstLeafLevel = UINT_MAX;
	bool flag = true;
	if(ptr->left == null && ptr->right == null){
		if(firstLeafLevel == UINT_MAX){
			firstLeafLevel = level;
			return true;
		}else{
			if(level == firstLeafLevel){
				return flag;
			}else if(level == firstLeafLevel-1){
				if(!flag){
					return false;
				}
				flag = false;
				return true;
			}
		}
	}
	bool leftTruthValue = isTreeCompleteON(ptr->left,level+1);
	bool rightTruthValue = isTreeCompleteON(ptr->right,level+1);
	if(ptr->left == null){
		if(ptr->right != null || level != firstLeafLevel-1){
			return false;
		}
	}
	return leftTruthValue && rightTruthValue;
}

unsigned int getSizeOfTree(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return 1 + getSizeOfTree(ptr->left) + getSizeOfTree(ptr->right);
}

bool isTreeCompleteHashmap(itNode *ptr){
	if(ptr == null){
		return true;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int sizeOfTree = getSizeOfTree(ptr);
	for(unsigned int counter = 0;counter < sizeOfTree;counter++){
		if((itToIndexNodeMap = indexNodeMap.find(counter)) == indexNodeMap.end()){
			return false;
		}
	}
	return true;
}

bool isTreeCompleteLevelOrder(itNode *ptr){
	if(ptr == null){
		return true;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	bool flag = true;
	unsigned int levelSize;
	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		levelSize = auxSpace.size();
		while(levelSize--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left == null){
				flag = false;
			}else{
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right == null){
				if(!flag){
					return false;
				}
			}else{
				auxSpace.push(currentNode->right);
			}
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* BINARYTREECOMPLETEORNOT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

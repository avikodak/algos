/****************************************************************************************************************************************************
 *  File Name   		: differencesumoddevenlevel.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page03\differencesumoddevenlevel.h
 *  Created on			: May 25, 2014 :: 2:41:16 PM
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


#ifndef DIFFERENCESUMODDEVENLEVEL_H_
#define DIFFERENCESUMODDEVENLEVEL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void differenceSumOddEvenLevelMain(itNode *ptr,unsigned int currentLevel,int &oddSum,int &evenSum){
	if(ptr == null){
		return;
	}
	if(currentLevel&1){
		oddSum += ptr->value;
	}else{
		evenSum += ptr->value;
	}
	differenceSumOddEventLevelMain(ptr->left,currentLevel+1,oddSum,evenSum);
	differenceSumOddEventLevelMain(ptr->right,currentLevel+1,oddSum,evenSum);
}

int differenceSumOddEventLevel(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	int oddSum,evenSum;
	differenceSumOddEvenLevelMain(ptr,1,oddSum,evenSum);
	return oddSum-evenSum;
}

int differenceSumOddEvenLevelHashmap(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	int oddSum = 0,evenSum = 0;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		if(log2(itToIndexNodeMap->first)&1){
			oddSum += itToIndexNodeMap->second->value;
		}else{
			evenSum += itToIndexNodeMap->second->value;
		}
	}
	return oddSum-evenSum;
}

int differenceSumOddEvenLevelLeveOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode = ptr;
	auxSpace.push(ptr);
	int oddSum = 0,evenSum = 0,currentLevelNodeCounter,level = 1;
	while(!auxSpace.empty()){
		currentLevelNodeCounter = auxSpace.size();
		while(currentLevelNodeCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(level&1){
				oddSum += currentNode->value;
			}else{
				evenSum += currentNode->value;
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		level++;
	}
	return oddSum - evenSum;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int getSumOfLevelByLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return ptr->value;
	}
	return getSumOfLevelByLevel(ptr->left,level-1) + getSumOfLevelByLevel(ptr->right,level-1);
}

int getSumOddEvenLevel(itNode *ptr){
	if(ptr == null){
		return INT_MIN;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->heightOfTree(ptr);
	int oddSum = 0,evenSum = 0;
	for(unsigned int counter = 0;counter < height;counter++){
		if(counter&1){
			oddSum += getSumOfLevelByLevel(ptr,counter);
		}else{
			evenSum += getSumOfLevelByLevel(ptr,counter);
		}
	}
	return oddSum - evenSum;
}
#endif /* DIFFERENCESUMODDEVENLEVEL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

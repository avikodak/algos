/****************************************************************************************************************************************************
 *  File Name   		: heightoftreeiterative.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page03\heightoftreeiterative.h
 *  Created on			: May 25, 2014 :: 7:08:00 PM
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

#ifndef HEIGHTOFTREEITERATIVE_H_
#define HEIGHTOFTREEITERATIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getHeightOfTreeIterative(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	queue<itNode *> auxSpace;
	unsigned int currentNodeLevelCounter,levelCounter = 0;
	itNode *currentNode;

	auxSpace.push(ptr);
	while(!auxSpace.empty()){
		currentLevelCounter = auxSpace.size();
		while(currentLevelCounter--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		levelCounter += 1;
	}
	return levelCounter;
}

unsigned int getHeightOfTreeHashmap(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int maxIndex = 0;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		maxIndex = max(maxIndex,itToIndexNodeMap->first);
	}
	return log2(maxIndex);
}

#endif /* HEIGHTOFTREEITERATIVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/


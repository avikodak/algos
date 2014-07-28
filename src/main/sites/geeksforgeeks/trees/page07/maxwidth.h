/****************************************************************************************************************************************************
 *  File Name   		: maxwidth.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\maxwidth.h
 *  Created on			: May 1, 2014 :: 7:44:09 PM
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

#ifndef MAXWIDTH_H_
#define MAXWIDTH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setNodeLevelCounter(itNode *ptr,unsigned int level,vector<unsigned int> &levelCounter){
	if(ptr == null){
		return;
	}
	levelCounter[level] += 1;
	setNodeLevelCounter(ptr->left,level+1,levelCounter);
	setNodeLevelCounter(ptr->right,level+1,levelCounter);
}

unsigned int getMaxWidthLevel(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	vector<unsigned int> levelCounter;
	setNodeLevelCounter(ptr,0,levelCounter);
	unsigned int maxWidth = 0,maxWidthLevel = 0;
	for(unsigned int counter = 0;counter < levelCounter.size();counter++){
		if(maxWidth < levelCounter[counter]){
			maxWidth = levelCounter[counter];
			maxWidthLevel = counter;
		}
	}
	return maxWidthLevel;
}

unsigned int getMaxWidthLevelHashmap(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	hash_map<unsigned int,unsigned int> levelNodeCounter;
	hash_map<unsigned int,unsigned int>::iterator itToLevelNodeCounter;
	unsigned int currentNodeLevel;
	unsigned int maxWidth = 0,maxWidthLevel = 0;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeLevel = log2(itToIndexNodeMap->first);
		if((itToLevelNodeCounter = levelNodeCounter.find(currentNodeLevel)) ==  levelNodeCounter.end()){
			levelNodeCounter[currentNodeLevel] = 1;
		}else{
			levelNodeCounter[currentNodeLevel] += 1;
		}
		if(maxWidth < levelNodeCounter[currentNodeLevel]){
			maxWidth = levelNodeCounter[currentNodeLevel];
			maxWidthLevel = currentNodeLevel;
		}
	}
	return maxWidthLevel;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int levelCounter(itNode *ptr,unsigned int level){
	if(ptr == null){
		return 0;
	}
	if(level == 0){
		return 1;
	}
	return levelCounter(ptr->left,level-1) + levelCounter(ptr->right,level-1);
}

unsigned int getMaxWidthLevelByLevel(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->heightOfTree(ptr);
	unsigned int maxWidth = 0,maxWidthLevel = 0,currentLevelWidth;
	for(unsigned int counter = 0;counter < height;counter++){
		currentLevelWidth = levelCounter(ptr,counter);
		if(currentLevelWidth > maxWidth){
			maxWidth = currentLevelWidth;
			maxWidthLevel = counter;
		}
	}
	return maxWidthLevel;
}

#endif /* MAXWIDTH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: printnodesatkdistance.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\printnodesatkdistance.h
 *  Created on			: May 1, 2014 :: 7:42:21 PM
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

#ifndef PRINTNODESATKDISTANCE_H_
#define PRINTNODESATKDISTANCE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printNodesAtKDistance(itNode *ptr,unsigned int kDistance){
	if(ptr == null){
		return;
	}
	if(kDistance == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printNodesAtKDistance(ptr->left,kDistance-1);
	printNodesAtKDistance(ptr->right,kDistance-1);
}

void printNodesAtKDistanceHashmap(itNode *ptr,unsigned int kDistance){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	for(unsigned int counter = pow(2,kDistance-1);counter < pow(2,kDistance);counter++){
		if((itToIndexNodeMap = indexNodeMap.find(counter)) != indexNodeMap.end()){
			printf("%d\t",itToIndexNodeMap->second->value);
		}
	}
}

struct iltNode{
	int value;
	unsigned int level;
	iltNode *left;
	iltNode *right;

	iltNode(){

	}

	iltNode(int userInput){
		value = userInput;
		left =  null;
		right = null;
		level = 0;
	}
};

void setLevelInNodes(iltNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	ptr->level = level;
	setLevelInNodes(ptr->left,level+1);
	setLevelInNodes(ptr->right,level+1);
}

void printLevelAtKLevel(iltNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	if(kValue == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevelAtKLevel(ptr->left,kValue-1);
	printLevelAtKLevel(ptr->right,kValue-1);
}

void printNodesAtLevelK(iltNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	setLevelInNodes(ptr,1);
	printLevelAtKLevel(ptr,kValue);
}

void printNodesAtLevelHashmap(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int currentNodeLevel;
	for(itToIndexNodeMap = indexNodeMap.begin();itToIndexNodeMap != indexNodeMap.end();itToIndexNodeMap++){
		currentNodeLevel = log2(itToIndexNodeMap->first) + 1;
		if(currentNodeLevel == kValue){
			printf("%d\t",itToIndexNodeMap->second->value);
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printNodesAtKLevelON2(itNode *ptr,unsigned int kValue){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	static unsigned int height = utils->heightOfTree(ptr);
	unsigned int currentNodeTreeHeight = utils->heightOfTree(ptr);
	if(height-currentNodeTreeHeight  == kValue){
		printf("%d\t",ptr->value);
		return;
	}
	printNodesAtKLevelON2(ptr->left,kValue);
	printNodesAtKLevelON2(ptr->right,kValue);
}

#endif /* PRINTNODESATKDISTANCE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

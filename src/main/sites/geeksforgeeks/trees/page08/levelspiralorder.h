/****************************************************************************************************************************************************
 *  File Name   		: levelspiralorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\levelspiralorder.h
 *  Created on			: Apr 28, 2014 :: 2:47:02 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
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

#ifndef LEVELSPIRALORDER_H_
#define LEVELSPIRALORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void levelSpiralOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> oddLevel;
	stack<itNode *> evenLevel;
	oddLevel.push(ptr);
	itNode *currentNode;
	while(!oddLevel.empty() || !evenLevel.empty()){
		while(!oddLevel.empty()){
			currentNode = oddLevel.top();
			oddLevel.pop();
			printf("%d\t",currentNode->value);
			if(currentNode->left != null){
				evenLevel.push(currentNode->left);
			}
			if(currentNode->right != null){
				evenLevel.push(currentNode->right);
			}
		}
		printf("\n");
		while(!evenLevel.empty()){
			currentNode = evenLevel.top();
			evenLevel.pop();
			printf("%d\t",currentNode->value);
			if(currentNode->right != null){
				oddLevel.push(currentNode->right);
			}
			if(currentNode->left != null){
				oddLevel.push(currentNode->left);
			}
		}
		printf("\n");
	}
}

//Tested
void levelSpiralOrderHashmap(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	hash_map<unsigned int,itNode *> indexNodeMap = utils->getHashmapFormITree(ptr,false)->indexNodeMap;
	hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
	unsigned int height = utils->heightOfTree(ptr);
	for(unsigned int heightCounter = 0;heightCounter < height;heightCounter++){
		if(heightCounter%2 == 0){
			for(unsigned int indexCounter = pow(2,heightCounter);indexCounter < pow(2,heightCounter+1);indexCounter++){
				if((itToIndexNodeMap = indexNodeMap.find(indexCounter)) != indexNodeMap.end()){
					printf("%d\t",itToIndexNodeMap->second->value);
				}
			}
		}else{
			for(unsigned int indexCounter = pow(2,heightCounter+1)-1;indexCounter >= pow(2,heightCounter);indexCounter--){
				if((itToIndexNodeMap = indexNodeMap.find(indexCounter)) != indexNodeMap.end()){
					printf("%d\t",itToIndexNodeMap->second->value);
				}
			}
		}
		printf("\n");
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevelLToR(itNode *ptr,unsigned int index){
	if(ptr == null){
		return;
	}
	if(index == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevelLToR(ptr->left,index-1);
	printLevelLToR(ptr->right,index-1);
}

//Tested
void printLevelRToL(itNode *ptr,unsigned int index){
	if(ptr == null){
		return;
	}
	if(index == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevelRToL(ptr->right,index-1);
	printLevelRToL(ptr->left,index-1);
}

//Tested
void printLevelSpiralOrderON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int heightOfTree = utils->heightOfTree(ptr);
	for(unsigned int counter = 0;counter < heightOfTree;counter++){
		if(counter%2){
			printLevelRToL(ptr,counter);
		}else{
			printLevelLToR(ptr,counter);
		}
		printf("\n");
	}
}

#endif /* LEVELSPIRALORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

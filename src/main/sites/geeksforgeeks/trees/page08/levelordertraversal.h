/****************************************************************************************************************************************************
 *  File Name   		: levelordertraversal.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\levelordertraversal.h
 *  Created on			: Apr 24, 2014 :: 11:48:37 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/level-order-tree-traversal/
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

#ifndef LEVELORDERTRAVERSAL_H_
#define LEVELORDERTRAVERSAL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void glevelOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> auxSpace;
	unsigned int levelNodeCounter = 1;
	auxSpace.push(ptr);
	itNode *currentNode;
	while(!auxSpace.empty()){
		while(levelNodeCounter--){
			currentNode = auxSpace.front();
			printf("%d\t",currentNode->value);
			auxSpace.pop();
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		printf("\n");
		levelNodeCounter = auxSpace.size();
	}
}

//Tested
void setLevelNodesPreOrderTraversal(itNode *ptr,hash_map<unsigned int,vector<itNode *> > &levelNodesMap,unsigned int currentNodeLevel){
	if(ptr == null){
		return;
	}
	hash_map<unsigned int,vector<itNode *> >::iterator itToLevelNodesMap;
	if((itToLevelNodesMap = levelNodesMap.find(currentNodeLevel)) == levelNodesMap.end()){
		vector<itNode *> level;
		level.push_back(ptr);
		levelNodesMap[currentNodeLevel] = level;
	}else{
		itToLevelNodesMap->second.push_back(ptr);
	}
	setLevelNodesPreOrderTraversal(ptr->left,levelNodesMap,currentNodeLevel+1);
	setLevelNodesPreOrderTraversal(ptr->right,levelNodesMap,currentNodeLevel+1);
}

//Tested
void levelOrderTraversalAuxSpacePreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	hash_map<unsigned int,vector<itNode *> > levelNodesMap;
	setLevelNodesPreOrderTraversal(ptr,levelNodesMap,0);
	hash_map<unsigned int,vector<itNode *> >::iterator itToLevelNodesMap;
	unsigned int currentLevelSize;
	for(itToLevelNodesMap = levelNodesMap.begin();itToLevelNodesMap != levelNodesMap.end();itToLevelNodesMap++){
		currentLevelSize = itToLevelNodesMap->second.size();
		for(unsigned int counter = 0;counter < currentLevelSize;counter++){
			printf("%d\t",itToLevelNodesMap->second[counter]->value);
		}
		PRINT_NEW_LINE;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printLevel(itNode *ptr,unsigned int level){
	if(ptr == null){
		return;
	}
	if(level == 0){
		printf("%d\t",ptr->value);
		return;
	}
	printLevel(ptr->left,level-1);
	printLevel(ptr->right,level-1);
}

//Tested
void glevelOrderTraversalON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->heightOfTree(ptr);
	for(unsigned int counter = 0;counter < height;counter++){
		printLevel(ptr,counter);
		printf("\n");
	}
}

#endif /* LEVELORDERTRAVERSAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

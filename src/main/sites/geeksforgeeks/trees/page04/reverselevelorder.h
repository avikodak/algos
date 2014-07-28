/****************************************************************************************************************************************************
 *  File Name   		: reverselevelorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\reverselevelorder.h
 *  Created on			: May 25, 2014 :: 2:15:36 PM
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

#ifndef REVERSELEVELORDER_H_
#define REVERSELEVELORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void reverseLevelOrderIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNode *> inorderAuxspace;
	stack<itNode *> reverseInOrderAuxspace;
	itNode *currentNode;
	inorderAuxspace.push(ptr);
	while(!inorderAuxspace.empty()){
		currentNode = inorderAuxspace.front();
		inorderAuxspace.pop();
		reverseInOrderAuxspace.push(currentNode);
		if(currentNode->left != null){
			inorderAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			inorderAuxspace.push(currentNode->right);
		}
	}
	while(!reverseInOrderAuxspace.empty()){
		printf("%d\t",reverseInOrderAuxspace.top()->value);
		reverseInOrderAuxspace.pop();
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void reverseLevelOrderLevelByLevel(itNode *ptr,unsigned int currentIndex){
	if(ptr == null){
		return;
	}
	if(currentIndex == 0){
		printf("%d\t",ptr->value);
		return;
	}
	reverseLevelOrderLevelByLevel(ptr->right,currentIndex-1);
	reverseLevelOrderLevelByLevel(ptr->left,currentIndex-1);
}

void printReverseLevelOrderIterativeON2(itNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->heightOfTree(ptr);
	for(unsigned int counter = height-1;counter >= 0;counter--){
		reverseLevelOrderLevelByLevel(ptr,counter);
	}
}
#endif /* REVERSELEVELORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: connectnodesconstantspace.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\connectnodesconstantspace.h
 *  Created on			: May 13, 2014 :: 9:33:17 PM
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

#ifndef CONNECTNODESCONSTANTSPACE_H_
#define CONNECTNODESCONSTANTSPACE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
struct itNextRightNode{
	int value;
	itNextRightNode *left;
	itNextRightNode *right;
	itNextRightNode *nextRight;

	itNextRightNode(){

	}

	itNextRightNode(int userInput){
		value = userInput;
		left = null;
		right = null;
		nextRight = null;
	}
};

itNextRightNode *getNextRightNode(itNextRightNode *ptr){
	if(ptr == null){
		return null;
	}
	if(ptr->left != null){
		return ptr->left;
	}
	if(ptr->right != null){
		return ptr->right;
	}
	return getNextRightNode(ptr->nextRight);
}

void connectNodesAtSameLevelConstantSpaceMain(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->nextRight != null){
		connectNodesAtSameLevelConstantSpaceMain(ptr->nextRight);
	}
	if(ptr->left != null){
		if(ptr->right != null){
			ptr->left = ptr->right;
			ptr->right->nextRight = getNextRightNode(ptr);
		}else{
			ptr->left = getNextRightNode(ptr);
		}
		connectNodesAtSameLevelConstantSpaceMain(ptr->left);
	}else if(ptr->right != null){
		ptr->right->nextRight  = getNextRightNode(ptr);
		connectNodesAtSameLevelConstantSpaceMain(ptr->right);
	}else{
		connectNodesAtSameLevelConstantSpaceMain(ptr->nextRight);
	}
}

void connectNodesAtSameLevelDriver(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	ptr->nextRight = null;
	connectNodesAtSameLevelConstantSpaceMain(ptr);
}
#endif /* CONNECTNODESCONSTANTSPACE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

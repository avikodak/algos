/****************************************************************************************************************************************************
 *  File Name   		: connectnodesatsamelevel.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\connectnodesatsamelevel.h
 *  Created on			: May 10, 2014 :: 12:01:52 AM
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

#ifndef CONNECTNODESATSAMELEVEL_H_
#define CONNECTNODESATSAMELEVEL_H_

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

void connectNodesAtSameLevel(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	queue<itNextRightNode *> auxSpace;
	auxSpace.push(ptr);
	unsigned int counter = 1;
	itNextRightNode *prevNode,*currentFrontNode;
	while(!auxSpace.empty()){
		prevNode = null;
		while(!auxSpace.empty() && counter > 0){
			currentFrontNode = auxSpace.front();
			if(prevNode != null){
				prevNode->nextRight = currentFrontNode;
			}
			prevNode = currentFrontNode;
			if(currentFrontNode->left != null){
				auxSpace.push(currentFrontNode->left);
			}
			if(currentFrontNode->right != null){
				auxSpace.push(currentFrontNode->right);
			}
			counter--;
		}
		counter = auxSpace.size();
	}
}

void connectNodesAtSameLevelReverseLevelOrder(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNextRightNode *> auxSpace;
	auxSpace.push(ptr);
	unsigned int counter = 1;
	itNextRightNode *prevNode,*currentTopNode;
	while(!auxSpace.empty()){
		prevNode = null;
		while(!auxSpace.empty() && counter--){
			currentTopNode = auxSpace.top();
			auxSpace.pop();
			currentTopNode->nextRight = prevNode;
			prevNode = currentTopNode;
			if(currentTopNode->left != null){
				auxSpace.push(currentTopNode->left);
			}
			if(currentTopNode->right != null){
				auxSpace.push(currentTopNode->right);
			}
		}
		counter = auxSpace.size();
	}
}

/*
 * Works only for complete binary trees
 */
void connectNodesAtSameLevelPreorder(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left != null){
		ptr->left->nextRight = ptr->right;
	}
	if(ptr->right != null){
		ptr->right->nextRight = ptr->nextRight == null?null:ptr->nextRight->left;
	}
	connectNodesAtSameLevelPreorder(ptr->left);
	connectNodesAtSameLevelPreorder(ptr->right);
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void connectNodesAtSameLevelByLevel(itNextRightNode *ptr,unsigned int counter){
	if(ptr == null){
		return;
	}
	static itNextRightNode *prevNode = null;
	if(counter == 0){
		if(prevNode != null){
			prevNode->nextRight = ptr;
		}
		prevNode = ptr;
		return;
	}
	connectNodesAtSameLevelByLevel(ptr->left,counter-1);
	connectNodesAtSameLevelByLevel(ptr->right,counter-1);
}

void connectNodesAtSameLevelON2(itNextRightNode *ptr){
	if(ptr == null){
		return;
	}
	treeutils *utils = new treeutils();
	unsigned int height = utils->heightOfTree(ptr);
	for(unsigned int counter = 0;counter < height;counter++){
		connectNodesAtSameLevelByLevel(ptr,counter);
	}
}

#endif /* CONNECTNODESATSAMELEVEL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: treeinpreorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page07\treeinpreorder.h
 *  Created on			: May 1, 2014 :: 7:41:30 PM
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

#ifndef TREEINPREORDER_H_
#define TREEINPREORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getTreeFromPreInOrder(vector<int> preOrder,vector<int> inOrder,unsigned int inOrderStartIndex,unsigned int inOrderEndIndex){
	static unsigned int preOrderIndex = 0;
	if(preOrderIndex >= preOrder.size() || inOrderStartIndex > inOrderEndIndex){
		return null;
	}
	itNode *node = new itNode(preOrder[preOrderIndex]);
	unsigned int inorderIndex = inOrderStartIndex;
	for(inorderIndex = inOrderStartIndex;inorderIndex <= inOrderEndIndex;inorderIndex++){
		if(preOrder[preOrderIndex] == inOrder[inorderIndex]){
			break;
		}
	}
	if(inorderIndex > inOrderEndIndex){
		throw "Invalid index";
	}
	node->left = getTreeFromPreInOrder(preOrder,inOrder,inOrderStartIndex,inorderIndex-1);
	node->right = getTreeFromPreInOrder(preOrder,inOrder,inorderIndex+1,inOrderEndIndex);
	return node;
}

#endif /* TREEINPREORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: heightbalanced.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\heightbalanced.h
 *  Created on			: May 1, 2014 :: 8:49:35 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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

#ifndef HEIGHTBALANCED_H_
#define HEIGHTBALANCED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int isTreeHeightBalancedOptimizedMain(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	unsigned int leftHeight = isTreeHeightBalancedOptimizedMain(ptr->left);
	unsigned int rightHeight = isTreeHeightBalancedOptimizedMain(ptr->right);
	return abs(leftHeight-rightHeight) > 1?UINT_MAX:1+max(leftHeight,rightHeight);
}

//Tested
bool isTreeHeightBalancedOptimized(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return isTreeHeightBalancedOptimizedMain(ptr) == UINT_MAX?false:true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool isTreeHeightBalanced(itNode *ptr){
	if(ptr == null){
		return true;
	}
	static treeutils *utils = new treeutils();
	unsigned int leftHeight = utils->heightOfTree(ptr->left),rightHeight = utils->heightOfTree(ptr->right);
	if(abs(leftHeight-rightHeight) > 1){
		return false;
	}
	return isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
}

#endif /* HEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

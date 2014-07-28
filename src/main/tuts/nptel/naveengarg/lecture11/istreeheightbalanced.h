/****************************************************************************************************************************************************
 *  File Name   		: istreeheightbalanced.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture11\istreeheightbalanced.h
 *  Created on			: Jun 7, 2014 :: 7:57:08 PM
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

#ifndef ISTREEHEIGHTBALANCED_H_
#define ISTREEHEIGHTBALANCED_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int isTreeHeightBalancedONMain(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return 1;
	}
	unsigned int leftHeight = isTreeHeightBalancedON(ptr->left,isTreeBalanced);
	if(leftHeight == UINT_MAX){
		return UINT_MAX;
	}
	unsigned int rightHeight = isTreeHeightBalancedON(ptr->right,isTreeBalanced);
	if(rightHeight == UINT_MAX){
		return UINT_MAX;
	}
	return abs(leftHeight-rightHeight) <= 1?max(leftHeight,rightHeight)+1:UINT_MAX;
}

bool isTreeHeightBalancedON(itNode *ptr){
	unsigned int height = isTreeHeightBalancedONMain(ptr);
	return height == UINT_MAX?false:true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int heightOfTree(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return max(heightOfTree(ptr->left),heightOfTree(ptr->right)) + 1;
}

bool isTreeHeightBalancedON2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	unsigned int leftHeight = heightOfTree(ptr->left);
	unsigned int rightHeight = heightOfTree(ptr->right);
	return abs(leftHeight - rightHeight) <= 1 && isTreeHeightBalancedON2(ptr->left) && isTreeHeightBalancedON2(ptr->right);
}

#endif /* ISTREEHEIGHTBALANCED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

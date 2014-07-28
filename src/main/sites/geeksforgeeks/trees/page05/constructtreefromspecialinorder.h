/****************************************************************************************************************************************************
 *  File Name   		: constructtreefromspecialinorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\constructtreefromspecialinorder.h
 *  Created on			: May 16, 2014 :: 12:43:33 AM
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


#ifndef CONSTRUCTTREEFROMSPECIALINORDER_H_
#define CONSTRUCTTREEFROMSPECIALINORDER_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getMaxValueIndex(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int maxValueIndex = startIndex;
	for(unsigned int counter = startIndex+1;counter <= endIndex;counter++){
		if(userInput[maxValueIndex] < userInput[counter]){
			maxValueIndex = counter;
		}
	}
	return maxValueIndex;
}

itNode *constructTreeFromSpecialInOrderMain(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	itNode *root;
	if(startIndex == endIndex){
		root = new itNode(userInput[userInput]);
		return root;
	}
	unsigned int dividingIndex = getMaxValueIndex(userInput,startIndex,endIndex);
	root  = new itNode(userInput[dividingIndex]);
	root->left = constructTreeFromSpecialInOrderMain(userInput,startIndex,dividingIndex-1);
	root->right = constructTreeFromSpecialInOrderMain(userInput,dividingIndex+1,endIndex);
	return root;
}

#endif /* CONSTRUCTTREEFROMSPECIALINORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

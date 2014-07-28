/****************************************************************************************************************************************************
 *  File Name   		: balancedtreefromsortedarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\balancedtreefromsortedarray.h
 *  Created on			: Jun 4, 2014 :: 5:38:49 PM
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

#ifndef BALANCEDTREEFROMSORTEDARRAY_H_
#define BALANCEDTREEFROMSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *buildBalancedBSTFromSortedArray(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	itNode *root = new itNode(userInput[middleIndex]);
	root->left = buildBalancedBSTFromSortedArray(userInput,startIndex,middleIndex-1);
	root->right = buildBalancedBSTFromSortedArray(userInput,middleIndex+1,endIndex);
	return root;
}

#endif /* BALANCEDTREEFROMSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

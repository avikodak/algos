/****************************************************************************************************************************************************
 *  File Name   		: constructtreespecialpreorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\constructtreespecialpreorder.h
 *  Created on			: May 16, 2014 :: 12:55:48 AM
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

#ifndef CONSTRUCTTREESPECIALPREORDER_H_
#define CONSTRUCTTREESPECIALPREORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *constructTreeSpecialPreOrder(vector<int> userInput,vector<bool> leafflags){
	if(userInput.size() == 0){
		return null;
	}
	static unsigned int runningIndex = 0;
	if(runningIndex >= userInput.size()){
		return null;
	}
	itNode *root;
	root = new itNode(userInput[runningIndex]);
	runningIndex += 1;
	if(leafflags[runningIndex]){
		return root;
	}
	root->left = constructTreeSpecialPreOrder(userInput,leafflags,runningIndex);
	root->right = constructTreeSpecialPreOrder(userInput,leafflags,runningIndex);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* CONSTRUCTTREESPECIALPREORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

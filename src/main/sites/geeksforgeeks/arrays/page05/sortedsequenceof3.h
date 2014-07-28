/****************************************************************************************************************************************************
 *  File Name   		: sortedsequenceof3.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\sortedsequenceof3.h
 *  Created on			: Jul 1, 2014 :: 12:16:10 AM
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

#ifndef SORTEDSEQUENCEOF3_H_
#define SORTEDSEQUENCEOF3_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int *getSortedSequenceOfSize3(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	vector<int> lessL2RAuxSpace,greaterR2LAuxSpace;
	lessL2RAuxSpace.push_back(INT_MIN);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		lessL2RAuxSpace.push_back(min(lessL2RAuxSpace[counter-1],userInput[counter-1]));
	}
	greaterR2LAuxSpace.push_back(INT_MAX);
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter--){
		greaterR2LAuxSpace.push_back(max(greaterR2LAuxSpace[userInput.size() - counter+1],userInput[counter]));
	}
	for(unsigned int counter = 1;counter < userInput.size()-1;counter++){
		if(lessL2RAuxSpace[counter] <= userInput[counter] && greaterR2LAuxSpace[counter]  <= userInput[counter]){
			int *result = (int *)calloc(3,sizeof(int));
			result[0] = lessL2RAuxSpace[counter];
			result[1] = userInput[counter];
			result[2] = greaterR2LAuxSpace[counter];
			return result;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SORTEDSEQUENCEOF3_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

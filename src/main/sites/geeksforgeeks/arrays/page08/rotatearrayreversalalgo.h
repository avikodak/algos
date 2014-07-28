/****************************************************************************************************************************************************
 *  File Name   		: rotatearrayreversalalgo.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\rotatearrayreversalalgo.h
 *  Created on			: Apr 26, 2014 :: 11:01:55 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
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

#ifndef ROTATEARRAYREVERSALALGO_H_
#define ROTATEARRAYREVERSALALGO_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseArrayForIndexes(vector<int> &userInput,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || startIndex > endIndex || startIndex == endIndex){
		return;
	}
	int temp;
	while(startIndex < endIndex){
		temp = userInput[startIndex];
		userInput[startIndex] = userInput[endIndex];
		userInput[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}

//Tested
void rotateArrayReversalAlgo(vector<int> &userInput,unsigned int rotateBy){
	if(userInput.size() == 0 || rotateBy == 0){
		return;
	}
	rotateBy %= userInput.size();
	reverseArrayForIndexes(userInput,0,rotateBy-1);
	reverseArrayForIndexes(userInput,rotateBy,userInput.size()-1);
	reverseArrayForIndexes(userInput,0,userInput.size()-1);
}

#endif /* ROTATEARRAYREVERSALALGO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

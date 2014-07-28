/****************************************************************************************************************************************************
 *  File Name   		: equilibriumindex.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\equilibriumindex.h
 *  Created on			: May 1, 2014 :: 7:38:23 PM
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

#ifndef EQUILIBRIUMINDEX_H_
#define EQUILIBRIUMINDEX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getEquilibriumIndexON(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	vector<int> leftSums,rightSums;
	leftSums.push_back(0);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftSums[counter] = leftSums[counter-1] + userInput[counter-1];
	}
	rightSums[userInput.size()-1] = 0;
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter++){
		rightSums[counter] = rightSums[counter+1] + userInput[counter+1];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(leftSums[counter] == rightSums[counter]){
			return counter;
		}
	}
	return UINT_MAX;
}

unsigned int getEquilibriumIndexONOptimised(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	vector<int> leftSums;
	leftSums.push_back(0);
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftSums[counter] =  leftSums[counter-1] + userInput[counter-1];
	}
	int rightRunningSum = 0;
	if(leftSums[userInput.size()-1] == rightRunningSum){
		return userInput.size()-1;
	}
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter--){
		rightRunningSum += userInput[counter+1];
		if(leftSums[counter] == rightRunningSum){
			return counter;
		}
	}
	return UINT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getEquilibriumIndexON2(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	int leftSum,rightSum;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		leftSum = 0;rightSum = 0;
		for(unsigned int leftCounter = 0;leftCounter < counter;leftCounter++){
			leftSum += userInput[leftCounter];
		}
		for(unsigned int rightCounter = 0;rightCounter < userInput.size();rightCounter++){
			rightSum += userInput[rightCounter];
		}
		if(leftSum == rightSum){
			return counter;
		}
	}
	return UINT_MAX;
}

#endif /* EQUILIBRIUMINDEX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: maxminarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\maxminarray.h
 *  Created on			: May 7, 2014 :: 11:40:29 PM
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

#ifndef MAXMINARRAY_H_
#define MAXMINARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int *maxMinArrayDADMain(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return null;
	}
	int *maxMin = (int *)malloc(2*sizeof(int));
	if(startIndex == endIndex){
		maxMin[0] = maxMin[1] = userInput[startIndex];
		return maxMin;
	}
	if(abs(startIndex-endIndex)==1){
		maxMin[0] = min(userInput[startIndex],userInput[endIndex]);
		maxMin[1] = maxMin[0] ^ userInput[startIndex] ^ userInput[endIndex];
		return maxMin;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	int *leftResult = maxMinArrayDADMain(userInput,startIndex,middleIndex);
	int *rightResult = maxMinArrayDADMain(userInput,middleIndex+1,endIndex);
	if(leftResult != null && rightResult != null){
		maxMin[0] = max(leftResult[0],rightResult[0]);
		maxMin[1] = min(leftResult[1],rightResult[1]);
	}
	if(leftResult != null){
		return leftResult;
	}
	if(rightResult != null){
		return rightResult;
	}
	return null;
}

int *maxMinArrayDAD(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	if(userInput.size() == 1){
		int *maxMin = (int *)malloc(2*sizeof(int));
		maxMin[0] = maxMin[1] = userInput[0];
		return maxMin;
	}
	return maxMinArrayDADMain(userInput,0,userInput.size()-1);
}

int *maxMinArrayInPairs(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *maxMin = (int *)malloc(2*sizeof(int));
	unsigned int counter;
	if(userInput.size()&1){
		maxMin[0] = maxMin[1] = userInput[0];
		counter = 1;
	}else{
		maxMin[0] = max(userInput[0],userInput[1]);
		maxMin[1] = userInput[0] ^ userInput[1] ^ maxMin[0];
		counter = 2;
	}
	for(;counter<userInput.size();counter+=2){
		if(userInput[counter] > userInput[counter+1]){
			maxMin[0] = max(maxMin[0],userInput[counter]);
			maxMin[1] = min(maxMin[1],userInput[counter+1]);
		}else{
			maxMin[0] = max(maxMin[0],userInput[counter+1]);
			maxMin[1] = min(maxMin[1],userInput[counter]);
		}
	}
	return maxMin;
}

int *maxMinArrayON(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *maxMin = (int *)malloc(2*sizeof(int));
	maxMin[0] = maxMin[1] = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(maxMin[0] < userInput[counter]){
			maxMin[0] = userInput[counter];
		}
		if(maxMin[1] > userInput[counter]){
			maxMin[1] = userInput[counter];
		}
	}
	return maxMin;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

int *maxMinArrayONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	int *maxMin = (int *)malloc(2*sizeof(int));
	maxMin[0] = maxMin[1] = userInput[0];
	return maxMin;
}

#endif /* MAXMINARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

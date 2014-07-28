/****************************************************************************************************************************************************
 *  File Name   		: firstsecondsmallest.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\firstsecondsmallest.h
 *  Created on			: May 1, 2014 :: 5:54:33 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/
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

#ifndef FIRSTSECONDSMALLEST_H_
#define FIRSTSECONDSMALLEST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int  *firstSecondElementON(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *minElements = (int *)malloc(sizeof(int));
	minElements[0] = minElements[1] = INT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] < minElements[0]){
			minElements[1] = minElements[0];
			minElements[0] = userInput[counter];
		}else{
			if(userInput[counter] < minElements[1]){
				minElements[1] = userInput[counter];
			}
		}
	}
	return minElements;
}

//Tested
int *firstSecondElementO2N(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *minElements = (int *)malloc(sizeof(int));
	minElements[0] = minElements[1] = INT_MAX;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		minElements[0] = min(minElements[0],userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(minElements[counter] == minElements[0]){
			continue;
		}
		minElements[1] = min(minElements[1],userInput[counter]);
	}
	return minElements;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *firstSecondElementONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	int *minElements = (int *)malloc(sizeof(int));
	minElements[0] = minElements[1] = INT_MAX;
	minElements[0] = userInput[0];
	if(userInput.size() > 1){
		minElements[1] = userInput[1];
	}
	return minElements;
}

#endif /* FIRSTSECONDSMALLEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: twoelementsclosetozero.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\twoelementsclosetozero.h
 *  Created on			: May 1, 2014 :: 7:04:57 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/
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

#ifndef TWOELEMENTSCLOSETOZERO_H_
#define TWOELEMENTSCLOSETOZERO_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *twoElementsCloseToZero(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	int minSum = INT_MAX;
	int *requiredValues = (int *)malloc(2*sizeof(int));
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	while(frontCrawler < backCrawler){
		if(minSum > abs(userInput[frontCrawler] + userInput[backCrawler])){
			minSum = abs(userInput[frontCrawler] + userInput[backCrawler]);
			requiredValues[0] = userInput[frontCrawler];
			requiredValues[1] = userInput[backCrawler];
		}
		if(abs(userInput[frontCrawler] + userInput[backCrawler]) == 0){
			return requiredValues;
		}else{
			if(abs(userInput[frontCrawler] + userInput[backCrawler]) < 0){
				frontCrawler++;
			}else{
				backCrawler--;
			}
		}
	}
	return requiredValues;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int *twoElementsCloseToZeroON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	int minSum = INT_MAX;
	int *requiredValues = (int *)malloc(2*sizeof(int));
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(minSum > abs(userInput[innerCrawler] + userInput[outerCrawler])){
				minSum = abs(userInput[innerCrawler] + userInput[outerCrawler]);
				requiredValues[0] = userInput[outerCrawler];
				requiredValues[1] = userInput[innerCrawler];
			}
		}
	}
	return requiredValues;
}

#endif /* TWOELEMENTSCLOSETOZERO_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

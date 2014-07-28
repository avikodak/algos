/****************************************************************************************************************************************************
 *  File Name   		: findsubarrayforgivensum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\findsubarrayforgivensum.h
 *  Created on			: Jun 30, 2014 :: 11:48:58 PM
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

#ifndef FINDSUBARRAYFORGIVENSUM_H_
#define FINDSUBARRAYFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findSubArrayForGivenSum(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	unsigned int frontCrawler=0,rearCrawler=0;
	int runningSum = userInput[frontCrawler];
	if(sum < userInput[0] || sum > userInput[userInput.size()]){
		return null;
	}
	while(rearCrawler < userInput.size() && frontCrawler < userInput.size()){
		if(runningSum == sum){
			int *result = (int *)calloc(2,sizeof(int));
			result[0] = rearCrawler;
			result[1] = frontCrawler;
			return result;
		}
		if(runningSum < sum){
			runningSum += userInput[frontCrawler++];
		}else{
			runningSum -= userInput[rearCrawler++];
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findSubArrayForGivenSumON2(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	int currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		currentSum = 0;
		for(unsigned int innerCrawler = outerCrawler;innerCrawler < userInput.size();innerCrawler++){
			currentSum += userInput[innerCrawler];
			if(currentSum == sum){
				int *result = (int *)calloc(2,sizeof(int));
				result[0] = outerCrawler;
				result[1] = innerCrawler;
				return result;
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findSubArrayForGivenSumON3(vector<int> userInput,int sum){
	if(userInput.size() == 0){
		return null;
	}
	int currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		for(unsigned int middleCrawler = outerCrawler;middleCrawler < userInput.size();middleCrawler++){
			currentSum = 0;
			for(unsigned int innerCrawler = outerCrawler;innerCrawler <= middleCrawler;innerCrawler++){
				currentSum += userInput[innerCrawler];
			}
			if(currentSum == sum){
				int *result = (int *)calloc(2,sizeof(int));
				result[0] = outerCrawler;
				result[1] = middleCrawler;
				return result;
			}
		}
	}
	return null;
}
#endif /* FINDSUBARRAYFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

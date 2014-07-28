/****************************************************************************************************************************************************
 *  File Name   		: prefixaverage.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture01\prefixaverage.h
 *  Created on			: May 29, 2014 :: 12:57:09 AM
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

#ifndef PREFIXAVERAGE_H_
#define PREFIXAVERAGE_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> setVectorWithPrefixAverageON(vector<int> userInput){
	vector<int> prefixAverage;
	if(userInput.size() == 0){
		return prefixAverage;
	}
	prefixAverage = userInput[0];
	for(unsigned int crawler = 1;crawler < userInput.size();crawler++){
		prefixAverage[crawler] = ((prefixAverage[crawler-1] * crawler)+userInput[crawler])/(crawler+1);
	}
	return prefixAverage;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> setVectorWithPrefixAveragesON2(vector<int> userInput){
	vector<int> prefixAverage;
	if(userInput.size() == 0){
		return prefixAverage;
	}
	int currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		currentSum = userInput[outerCrawler];
		for(unsigned int innerCrawler = outerCrawler;innerCrawler > 0;innerCrawler++){
			currentSum += userInput[innerCrawler];
		}
		prefixAverage[outerCrawler] = (currentSum/outerCrawler+1);
	}
	return prefixAverage;
}

#endif /* PREFIXAVERAGE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

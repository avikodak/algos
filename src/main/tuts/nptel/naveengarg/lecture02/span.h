/****************************************************************************************************************************************************
 *  File Name   		: span.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture02\span.h
 *  Created on			: May 29, 2014 :: 2:31:39 AM
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

#ifndef SPAN_H_
#define SPAN_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> computeSpanON(vector<int> stockPrices){
	vector<int> spanOfStocks;
	if(stockPrices.size() == 0){
		return spanOfStocks;
	}
	spanOfStocks.push_back(1);
	unsigned int fillCounter = 1;
	stack<unsigned int> auxSpace;
	auxSpace.push(0);
	for(unsigned int counter = 1;counter < stockPrices.size();counter++){
		while(stockPrices[auxSpace.top()] < stockPrices[counter]){
			auxSpace.pop();
		}
		spanOfStocks[fillCounter++] = counter - auxSpace.top() + 1;
		auxSpace.push(counter);
	}
	return spanOfStocks;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> computeSpanON2(vector<int> stockPrices){
	vector<int> spanOfStocks;
	if(stockPrices.size() == 0){
		return spanOfStocks;
	}
	unsigned int counter = 0;
	for(unsigned int outerCrawler;outerCrawler < stockPrices.size();outerCrawler++){
		counter = 1;
		for(int innerCrawler=outerCrawler-1;innerCrawler >= 0;innerCrawler++){
			if(stockPrices[outerCrawler] <= stockPrices[innerCrawler]){
				counter++;
			}else{
				break;
			}
		}
		stockPrices[outerCrawler] = counter;
	}
	return spanOfStocks;
}

#endif /* SPAN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

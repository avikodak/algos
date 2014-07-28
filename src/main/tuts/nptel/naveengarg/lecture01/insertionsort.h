/****************************************************************************************************************************************************
 *  File Name   		: insertionsort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture01\insertionsort.h
 *  Created on			: May 23, 2014 :: 1:08:05 AM
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

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void insertionSort(vector<int> &userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
	int key;
	int innerCrawler;
	for(unsigned int outerCrawler = 1;outerCrawler < userInput.size();outerCrawler++){
		key  = userInput[outerCrawler];
		for(innerCrawler = outerCrawler-1;innerCrawler >= 0 && userInput[innerCrawler] > key;innerCrawler--){
			userInput[innerCrawler+1] = userInput[innerCrawler];
		}
		userInput[innerCrawler+1] = key;
	}
}

#endif /* INSERTIONSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

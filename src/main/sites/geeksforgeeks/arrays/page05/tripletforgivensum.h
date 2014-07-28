/****************************************************************************************************************************************************
 *  File Name   		: tripletforgivensum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\tripletforgivensum.h
 *  Created on			: Jun 30, 2014 :: 11:54:59 PM
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

#ifndef TRIPLETFORGIVENSUM_H_
#define TRIPLETFORGIVENSUM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *getTripletForGivenSum(vector<int> userInput,int key){
	if(userInput.size() < 3){
		return null;
	}
	sort(userInput.begin(),userInput.end());
	int requiredSum = key,currentSum;
	unsigned int frontCrawler,rearCrawler;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-2;outerCrawler++){
		requiredSum = key - userInput[outerCrawler];
		frontCrawler = outerCrawler+1;
		rearCrawler = userInput.size()-1;
		while(frontCrawler < rearCrawler){
			currentSum = userInput[frontCrawler] + userInput[rearCrawler];
			if(currentSum == requiredSum){
				int *result = (int *)calloc(3,sizeof(int));
				result[0] = userInput[outerCrawler];
				result[1] = userInput[frontCrawler];
				result[2] = userInput[rearCrawler];
				return result;
			}
			if(currentSum < requiredSum){
				frontCrawler++;
			}else{
				rearCrawler--;
			}
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int *getTripletForGivenSum(vector<int> userInput,int key){
	if(userInput.size() < 3){
		return null;
	}
	int currentSum;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-2;outerCrawler++){
		for(unsigned int middleCrawler = 0;middleCrawler < userInput.size()-1;middleCrawler++){
			for(unsigned int innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
				currentSum = userInput[outerCrawler] + userInput[middleCrawler] + userInput[innerCrawler];
				if(currentSum == key){
					int *result = (int *)calloc(3,sizeof(int));
					result[0] = userInput[outerCrawler];
					result[1] = userInput[middleCrawler];
					result[2] = userInput[innerCrawler];
					return result;
				}
			}
		}
	}
	return null;
}
#endif /* TRIPLETFORGIVENSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

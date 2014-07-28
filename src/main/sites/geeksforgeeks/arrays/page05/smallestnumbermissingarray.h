/****************************************************************************************************************************************************
 *  File Name   		: smallestnumbermissingarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\smallestnumbermissingarray.h
 *  Created on			: Jul 1, 2014 :: 12:15:16 AM
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

#ifndef SMALLESTNUMBERMISSINGARRAY_H_
#define SMALLESTNUMBERMISSINGARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int smallestNumberMissingArray(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int tempForSwap;
	while(frontCrawler < rearCrawler){
		while(userInput[frontCrawler] < 0){
			frontCrawler++;
		}
		while(userInput[rearCrawler] > 0){
			rearCrawler--;
		}
		if(frontCrawler < rearCrawler){
			tempForSwap = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[rearCrawler];
			userInput[rearCrawler] = tempForSwap;
		}
	}
	for(unsigned int counter = 0;counter < frontCrawler;counter++){
		userInput[counter] *= -1;
	}
	for(unsigned int counter = frontCrawler;counter < userInput.size();counter++){
		userInput[userInput[counter]] *= -1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			return counter;
		}
	}
	return userInput.size();
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int getSmallestNumberMissingONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	while(counter < userInput.size() && userInput[counter] < 0){
		counter++;
	}
	if(counter >= userInput.size() || userInput[counter] != 0) {
		return 0;
	}
	while(counter+1 < userInput.size()){
		if(userInput[counter+1]-userInput[counter] != 1){
			return counter+1;
		}
		counter++;
	}
	return userInput.size();
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int getSmallestNumberMissingON2(vector<int> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	bool flag;
	for(unsigned int outerCrawler = 0;outerCrawler <= userInput.size();outerCrawler++){
		flag = false;
		for(unsigned int vectorCrawler = 0;vectorCrawler < userInput.size();vectorCrawler++){
			if(userInput[vectorCrawler] == userInput){
				flag = true;
				break;
			}
		}
		if(!flag){
			return outerCrawler;
		}
	}
}
#endif /* SMALLESTNUMBERMISSINGARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

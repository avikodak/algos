/****************************************************************************************************************************************************
 *  File Name   		: formgreatestnumberforgivendigits.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\formgreatestnumberforgivendigits.h
 *  Created on			: Jun 7, 2014 :: 10:46:20 PM
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

#ifndef FORMGREATESTNUMBERFORGIVENDIGITS_H_
#define FORMGREATESTNUMBERFORGIVENDIGITS_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int formGreatestNumberONLOGN(vector<uint8_t> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	sort(userInput.begin(),userInput.end());
	unsigned int greatestNumber = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		greatestNumber = greatestNumber*10 + userInput[counter];
	}
	return greatestNumber;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int formGreatestNumberON2(vector<uint8_t> userInput){
	if(userInput.size() == 0){
		return 0;
	}
	int temp;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
	 	for(unsigned int innerCrawler = 0;innerCrawler < userInput.size()-1;innerCrawler++){
			if(userInput[innerCrawler] < userInput[innerCrawler+1]){
				temp = userInput[innerCrawler];
				userInput[innerCrawler] = userInput[innerCrawler+1];
				userInput[innerCrawler+1] = temp;
			}
		}
	}
	unsigned int number = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		number = number*10+userInput[counter];
	}
	return number;
}

#endif /* FORMGREATESTNUMBERFORGIVENDIGITS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: placefacevalue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\placefacevalue.h
 *  Created on			: Jun 7, 2014 :: 10:48:07 PM
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

#ifndef PLACEFACEVALUE_H_
#define PLACEFACEVALUE_H_

vector<unsigned int> placeValues(unsigned int userInput,uint8_t digit){
	vector<unsigned int> placeValuesForDigit;
	uint8_t lastDigit;
	unsigned int counter = 0;
	while(userInput){
		lastDigit = userInput % 10;
		if(digit == lastDigit){
			placeValuesForDigit.push_back(lastDigit * pow(10,counter));
		}
		counter++;
		userInput /= 10;
	}
	return placeValuesForDigit;
}

#endif /* PLACEFACEVALUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

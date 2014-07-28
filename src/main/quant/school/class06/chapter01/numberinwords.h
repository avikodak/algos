/****************************************************************************************************************************************************
 *  File Name   		: numberinwords.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\numberinwords.h
 *  Created on			: Jun 7, 2014 :: 10:45:43 PM
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

#ifndef NUMBERINWORDS_H_
#define NUMBERINWORDS_H_

void init(hash_map<unsigned long long int,string> &numberStringMap){
	numberStringMap[0] = "Zero";
	numberStringMap[1] = "One";
	numberStringMap[2] = "Two";
	numberStringMap[3] = "Three";
	numberStringMap[4] = "Four";
	numberStringMap[5] = "Five";
	numberStringMap[6] = "Six";
	numberStringMap[7] = "Seven";
	numberStringMap[8] = "Eight";
	numberStringMap[9] = "Nine";
	numberStringMap[10] = "Ten";
	numberStringMap[11] = "Eleven";
	numberStringMap[12] = "Twelve";
	numberStringMap[13] = "Thirteen";
	numberStringMap[14] = "Fourteen";
	numberStringMap[15] = "Fifteen";
	numberStringMap[16] = "Sixteen";
	numberStringMap[17] = "Seventeen";
	numberStringMap[18] = "Eighteen";
	numberStringMap[19] = "Nineteen";
	numberStringMap[20] = "Twenty";
	numberStringMap[30] = "Thirty";
	numberStringMap[40] = "Forty";
	numberStringMap[50] = "Fifty";
	numberStringMap[60] = "Sixty";
	numberStringMap[70] = "Seventy";
	numberStringMap[80] = "Eighty";
	numberStringMap[90] = "Ninety";
}

void placeValueInit(hash_map<unsigned long long int,string> &placeValueMap){
	placeValueMap[1] = "Units";
	placeValueMap[2] = "Tens";
	placeValueMap[3] = "Hundred";
	placeValueMap[4] = "Thousand";
	placeValueMap[5] = "Ten thousand";
	placeValueMap[6] = "Lakhs";
	placeValueMap[7] = "Ten lakhs";
	placeValueMap[8] = "Crore";
	placeValueMap[9] = "Ten crore";
}

void printNumberInWords(unsigned int userInput){
	hash_map<unsigned long long int,string> numberStringMap;
	init(userInput);

}

#endif /* NUMBERINWORDS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

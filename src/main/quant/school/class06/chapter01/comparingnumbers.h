/****************************************************************************************************************************************************
 *  File Name   		: comparingnumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\comparingnumbers.h
 *  Created on			: Jun 7, 2014 :: 10:44:20 PM
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

#ifndef COMPARINGNUMBERS_H_
#define COMPARINGNUMBERS_H_

bool compareNumbers(unsigned int firstNumber,unsigned int secondNumber){
	stack<uint8_t> firstNumberDigits,secondNumberDigits;
	while(firstNumber){
		firstNumberDigits.push(firstNumber%10);
		firstNumber /= 10;
	}
	while(secondNumber){
		secondNumberDigits.push(secondNumber%10);
		secondNumber /= 10;
	}
	if(firstNumberDigits.size() != secondNumberDigits.size()){
		return firstNumberDigits.size() > secondNumberDigits.size()?true:false;
	}
	while(!firstNumberDigits.empty() && !secondNumberDigits.empty()){
		if(firstNumberDigits.top() != secondNumberDigits.top()){
			return firstNumberDigits.top() > secondNumberDigits.top()?true:false;
		}
		firstNumberDigits.pop();
		secondNumberDigits.pop();
	}
	return true;
}

bool compareNumberByDiffernece(unsigned int firstNumber,unsigned int secondNumber){
	long int difference = (int)(firstNumber - secondNumber);
	return difference > 0;
}
#endif /* COMPARINGNUMBERS_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: traditionalsorting.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\traditionalsorting.h
 *  Created on			: Jun 7, 2014 :: 11:58:21 PM
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

#ifndef TRADITIONALSORTING_H_
#define TRADITIONALSORTING_H_

bool compareFunc(unsigned int firstNumber,unsigned int secondNumber){
	stack<uint8_t> digitsFirstNumber,digitsSecondNumber;
	while(firstNumber){
		digitsFirstNumber.push(firstNumber%10);
		firstNumber /= 10;
	}
	while(secondNumber){
		digitsSecondNumber.push(secondNumber%10);
		secondNumber /= 10;
	}
	//This should be replaced
	if(digitsFirstNumber.size() != digitsSecondNumber.size()){
		return digitsFirstNumber.size() < digitsSecondNumber.size()?true:false;
	}
	while(!digitsFirstNumber.empty() && digitsSecondNumber.empty()){
		if(digitsFirstNumber.top() != digitsSecondNumber.top()){
			return digitsFirstNumber.top() < digitsSecondNumber.top()?true:false;
		}
		digitsFirstNumber.pop();
		digitsSecondNumber.pop();
	}
	return true;
}

void traditionalSorting(vector<unsigned int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int minValueIndex,tempForSwap;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		minValue = outerCrawler;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(compareFunc(userInput[innerCrawler],userInput[minValueIndex])){
				minValueIndex = innerCrawler;
			}
		}
		tempForSwap = userInput[outerCrawler];
		userInput[outerCrawler] = userInput[minValueIndex];
		userInput[minValueIndex] = tempForSwap;
	}
}

#endif /* TRADITIONALSORTING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

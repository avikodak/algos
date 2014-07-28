/****************************************************************************************************************************************************
 *  File Name   		: coprimes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\coprimes.h
 *  Created on			: Jun 15, 2014 :: 6:07:59 PM
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

#include "factors.h"
#include "hcf.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COPRIMES_H_
#define COPRIMES_H_

//Tested
bool areNumbersCoprime(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return false;
	}
	if(firstNumber == 1 || secondNumber == 1){
		return true;
	}
	vector<unsigned int> factorsFirstNumber,factorsSecondNumber;
	factorsFirstNumber = getFactorsForGivenNumbers(firstNumber);
	factorsSecondNumber = getFactorsForGivenNumbers(secondNumber);
	unsigned int numberOfCommonFactors = 0;
	unsigned int firstCounter = 0,secondCounter = 0;
	while(firstCounter < factorsFirstNumber.size() && secondCounter < factorsSecondNumber.size()){
		if(factorsFirstNumber[firstCounter] == factorsSecondNumber[secondCounter]){
			numberOfCommonFactors++;
			firstCounter++;
			secondCounter++;
		}else{
			if(factorsFirstNumber[firstCounter] < factorsSecondNumber[secondCounter]){
				firstCounter++;
			}else{
				secondCounter++;
			}
		}
	}
	return numberOfCommonFactors == 1;
}

//Tested
bool areNumbersCoprimeGCDCheck(unsigned int firstNumber,unsigned int secondNumber){
	return hcfEuclidMethod(firstNumber,secondNumber) == 1;
}
#endif /* COPRIMES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

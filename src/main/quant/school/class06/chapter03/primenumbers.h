/****************************************************************************************************************************************************
 *  File Name   		: primenumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\primenumbers.h
 *  Created on			: Jun 15, 2014 :: 5:05:27 PM
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

#include "sieveoferathosthenes.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRIMENUMBERS_H_
#define PRIMENUMBERS_H_

//Tested
bool checkIsNumberPrime(unsigned int userInput){
	if(userInput == 1){
		return false;
	}
	unsigned int numberOfFactors = 0;
	for(unsigned int counter = 1;counter <= userInput;counter++){
		if(userInput % counter == 0){
			numberOfFactors += 1;
		}
	}
	return numberOfFactors == 2?true:false;
}

//Tested
bool isNumberPrimeOptimisedNaive(unsigned int userInput){
	if(userInput == 1){
		return false;
	}
	unsigned int sqrtOfGivenNumber = sqrt(userInput);
	unsigned int numberOfFactors = 0;
	for(unsigned int counter = 2;counter <= sqrtOfGivenNumber;counter++){
		if(userInput % counter == 0){
			numberOfFactors += 1;
		}
	}
	return numberOfFactors == 0;
}

//Tested
bool isNumberPrimeOptimised(unsigned int userInput){
	if(userInput == 1){
		return false;
	}
	vector<unsigned int> primeNumbers = generatePrimeNumber(userInput);
	for(unsigned int counter = 0;counter < primeNumbers.size()&& primeNumbers[counter] < userInput;counter++){
		if(primeNumbers[counter] != userInput && userInput%primeNumbers[counter] == 0){
			return false;
		}
	}
	return true;
}
#endif /* PRIMENUMBERS_H_ */
/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

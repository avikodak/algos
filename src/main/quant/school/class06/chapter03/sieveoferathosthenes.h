/****************************************************************************************************************************************************
 *  File Name   		: sieveoferathosthenes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\sieveoferathosthenes.h
 *  Created on			: Jun 15, 2014 :: 5:23:18 PM
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

#ifndef SIEVEOFERATHOSTHENES_H_
#define SIEVEOFERATHOSTHENES_H_

//Tested
bool isNumberPrime(unsigned int userInput){
	if(userInput == 1 || userInput == 0){
		return false;
	}
	unsigned int sqrtOfNumber = sqrt(userInput),noOfFactors = 0;
	for(unsigned int counter = 2;counter <= sqrtOfNumber;counter++){
		if(userInput % counter == 0){
			noOfFactors += 1;
		}
	}
	return !(noOfFactors >= 1);
}

//Tested
vector<unsigned int> generatePrimeNumberNaive(unsigned int userInput){
	vector<unsigned int> primeNumbers;
	for(unsigned int counter = 1;counter <= userInput;counter++){
		if(isNumberPrime(counter)){
			primeNumbers.push_back(counter);
		}
	}
	return primeNumbers;
}

//Tested
vector<unsigned int> generatePrimeNumber(unsigned int userInput){
	vector<bool> auxSpace(userInput+1,true);
	auxSpace[0] = false;
	auxSpace[1] = false;
	for(unsigned int outerCrawler = 2;outerCrawler <= userInput/2;outerCrawler++){
		for(unsigned int innerCrawler = 2;innerCrawler *outerCrawler <= userInput;innerCrawler++){
			auxSpace[outerCrawler * innerCrawler] = false;
		}
	}
	vector<unsigned int> primeNumbers;
	for(unsigned int counter = 2;counter <= userInput;counter++){
		if(auxSpace[counter]){
			primeNumbers.push_back(counter);
		}
	}
	return primeNumbers;
}

#endif /* SIEVEOFERATHOSTHENES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

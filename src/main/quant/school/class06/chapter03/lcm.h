/****************************************************************************************************************************************************
 *  File Name   		: lcm.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\lcm.h
 *  Created on			: Jun 15, 2014 :: 8:55:39 PM
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
#include "primefactorization.h"
#include "hcf.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LCM_H_
#define LCM_H_

//Tested
unsigned int lcmOfNumberNaiveMethod(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 0 || secondNumber == 0){
		return 0;
	}
	if(firstNumber == 1 || secondNumber == 1){
		return firstNumber *secondNumber;
	}
	unsigned int firstCounter=1,secondCounter=1;
	while(true){
		if(firstNumber * firstCounter == secondNumber * secondCounter){
			return firstCounter * firstNumber;
		}else{
			if(firstNumber * firstCounter < secondNumber *secondCounter){
				firstCounter += 1;
			}else{
				secondCounter += 1;
			}
		}
	}
	return UINT_MAX;
}

//Tested
unsigned int lcmNumberFactorizationMethod(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 1 || secondNumber == 1){
		return firstNumber * secondNumber;
	}
	hash_map<unsigned int,unsigned int> factorsFirstNumber,factorsSecondNumber;
	hash_map<unsigned int,unsigned int>::iterator itToFactorsFirstNumber,itToFactorsSecondNumber;
	factorsFirstNumber = primeFactorizationOfNumber(firstNumber);
	factorsSecondNumber = primeFactorizationOfNumber(secondNumber);
	unsigned int lcm = 1;
	itToFactorsFirstNumber = factorsFirstNumber.begin();
	itToFactorsSecondNumber  = factorsSecondNumber.begin();
	while(itToFactorsFirstNumber != factorsFirstNumber.end() && itToFactorsSecondNumber != factorsSecondNumber.end()){
		if(itToFactorsFirstNumber->first == itToFactorsSecondNumber->first){
			lcm *= pow(itToFactorsFirstNumber->first,max(itToFactorsFirstNumber->second,itToFactorsSecondNumber->second));
			itToFactorsFirstNumber++;
			itToFactorsSecondNumber++;
		}else{
			if(itToFactorsFirstNumber->first < itToFactorsSecondNumber->first){
				lcm *= pow(itToFactorsFirstNumber->first,itToFactorsFirstNumber->second);
				itToFactorsFirstNumber++;
			}else{
				lcm *= pow(itToFactorsSecondNumber->first,itToFactorsSecondNumber->second);
				itToFactorsSecondNumber++;
			}
		}
	}
	while(itToFactorsFirstNumber != factorsFirstNumber.end()){
		lcm *= pow(itToFactorsFirstNumber->first,itToFactorsFirstNumber->second);
		itToFactorsFirstNumber++;
	}
	while(itToFactorsSecondNumber != factorsFirstNumber.end()){
		lcm *= pow(itToFactorsSecondNumber->first,itToFactorsSecondNumber->second);
		itToFactorsSecondNumber++;
	}
	return lcm;
}

//Tested
unsigned int lcmByDivisionMethod(vector<unsigned int> userInputs){
	if(userInputs.size() == 0){
		return 0;
	}
	if(userInputs.size() == 1){
		return userInputs[0];
	}
	unsigned int maxElement = *max_element(userInputs.begin(),userInputs.end());
	vector<unsigned int> primeNumbers = generatePrimeNumber(maxElement);
	bool flag = true;
	unsigned int noOfElementsDivisible = 0;
	unsigned int lcm = 1;
	unsigned int lastDividedIndex;
	while(flag){
		noOfElementsDivisible = 0;
		flag = false;
		for(unsigned int primeCounter = 0;primeCounter < primeNumbers.size();primeCounter++){
			noOfElementsDivisible = 0;
			for(unsigned int counter = 0;counter < userInputs.size();counter++){
				if(userInputs[counter] % primeNumbers[primeCounter] == 0){
					noOfElementsDivisible += 1;
					userInputs[counter] /= primeNumbers[primeCounter];
					lastDividedIndex = counter;
				}
			}
			if(noOfElementsDivisible < 2){
				if(noOfElementsDivisible == 1){
					userInputs[lastDividedIndex] *= primeNumbers[primeCounter];
				}
			}else{
				flag = true;
				lcm *= primeNumbers[primeCounter];
				break;
			}
		}
		if(!flag){
			for(unsigned int counter = 0;counter < userInputs.size();counter++){
				lcm *= userInputs[counter];
			}
			return lcm;
		}
	}
	return 1;
}

//Tested
unsigned int lcmByFindingGCD(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 1 || secondNumber == 1){
		return firstNumber * secondNumber;
	}
	unsigned int gcd = hcfEuclidMethod(firstNumber,secondNumber);
	return ((firstNumber * secondNumber)/gcd);
}

#endif /* LCM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

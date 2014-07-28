/****************************************************************************************************************************************************
 *  File Name   		: primefactorization.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\primefactorization.h
 *  Created on			: Jun 15, 2014 :: 7:45:10 PM
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

#ifndef PRIMEFACTORIZATION_H_
#define PRIMEFACTORIZATION_H_

//Tested
hash_map<unsigned int,unsigned int> primeFactorizationOfNumber(unsigned int userInput){
	hash_map<unsigned int,unsigned int> primeFactors;
	if(userInput == 0 || userInput == 1){
		return primeFactors;
	}
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactors;
	vector<unsigned int> primeNumbers = generatePrimeNumber(userInput);
	while(userInput != 1){
		for(unsigned int counter = 0;counter < primeNumbers.size();counter++){
			if(userInput%primeNumbers[counter] == 0){
				if((itToPrimeFactors = primeFactors.find(primeNumbers[counter])) == primeFactors.end()){
					primeFactors[primeNumbers[counter]] = 1;
				}else{
					primeFactors[primeNumbers[counter]] += 1;
				}
				userInput /= primeNumbers[counter];
				break;
			}
		}
	}
	return primeFactors;
}

//Tested
void primeFactorizationFactorMethod(unsigned int userInput,hash_map<unsigned int,unsigned int> &primeFactors){
	if(userInput == 1 || userInput == 0){
		return;
	}
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactors;
	bool factorsFound = false;
	for(unsigned int counter = 2;counter < userInput;counter++){
		if(userInput % counter == 0){
			primeFactorizationFactorMethod(userInput/counter,primeFactors);
			primeFactorizationFactorMethod(counter,primeFactors);
			factorsFound = true;
			break;
		}
	}
	if(!factorsFound){
		if((itToPrimeFactors = primeFactors.find(userInput)) != primeFactors.end()){
			primeFactors[userInput] += 1;
		}else{
			primeFactors[userInput] = 1;
		}
	}
}

#endif /* PRIMEFACTORIZATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

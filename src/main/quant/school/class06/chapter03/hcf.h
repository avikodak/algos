/****************************************************************************************************************************************************
 *  File Name   		: hcf.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\hcf.h
 *  Created on			: Jun 15, 2014 :: 8:28:33 PM
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
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef HCF_H_
#define HCF_H_

//Tested
unsigned int hcfNaiveMethod(unsigned int firstNumber,unsigned int secondNumber){
	vector<unsigned int> commonFactors = getCommonFactors(firstNumber,secondNumber);
	return commonFactors[commonFactors.size()-1];
}

//Tested
unsigned int hcfFactorizationMethod(unsigned int firstNumber,unsigned int secondNumber){
	hash_map<unsigned int,unsigned int> primefactorsFirstNumber = primeFactorizationOfNumber(firstNumber);
	hash_map<unsigned int,unsigned int> primefactorsSecondNumber = primeFactorizationOfNumber(secondNumber);
	hash_map<unsigned int,unsigned int>::iterator itToPrimeFactorsFirstNumber = primefactorsFirstNumber.begin(),itToPrimeFactorsSecondNumber = primefactorsSecondNumber.begin();
	unsigned int hcf = 1;
	while(itToPrimeFactorsFirstNumber != primefactorsFirstNumber.end() && itToPrimeFactorsSecondNumber != primefactorsSecondNumber.end()){
		if(itToPrimeFactorsFirstNumber->first == itToPrimeFactorsSecondNumber->first){
			hcf *= pow(itToPrimeFactorsFirstNumber->first,min(itToPrimeFactorsFirstNumber->second,itToPrimeFactorsSecondNumber->second));
			itToPrimeFactorsFirstNumber++;
			itToPrimeFactorsSecondNumber++;
		}else{
			if(itToPrimeFactorsFirstNumber->first < itToPrimeFactorsSecondNumber->first){
				itToPrimeFactorsFirstNumber++;
			}else{
				itToPrimeFactorsSecondNumber++;
			}
		}
	}
	return hcf;
}

//Tested
unsigned int hcfEuclidMethod(unsigned int firstNumber,unsigned int secondNumber){
	if(firstNumber == 1 || secondNumber == 1){
		return 1;
	}
	if(firstNumber > secondNumber){
		unsigned int temp = firstNumber;
		firstNumber = secondNumber;
		secondNumber = temp;
	}
	if(secondNumber%firstNumber == 0){
		return firstNumber;
	}
	return hcfEuclidMethod(secondNumber%firstNumber,firstNumber);
}

#endif /* HCF_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

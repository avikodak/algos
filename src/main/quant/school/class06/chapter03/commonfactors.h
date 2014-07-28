/****************************************************************************************************************************************************
 *  File Name   		: commonfactors.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\commonfactors.h
 *  Created on			: Jun 15, 2014 :: 8:00:04 PM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COMMONFACTORS_H_
#define COMMONFACTORS_H_

//Tested
vector<unsigned int> getCommonFactors(unsigned int firstNumber,unsigned int secondNumber){
	vector<unsigned int> factorsFirstNumbers = getFactorsForGivenNumbers(firstNumber);
	vector<unsigned int> factorsSecondNumbers = getFactorsForGivenNumbers(secondNumber);
	unsigned int firstFactorsCounter = 0,secondFactorsCounter = 0;
	vector<unsigned int> commonFactors;
	while(firstFactorsCounter < factorsFirstNumbers.size() && secondFactorsCounter < factorsSecondNumbers.size()){
		if(factorsFirstNumbers[firstFactorsCounter] == factorsSecondNumbers[secondFactorsCounter]){
			commonFactors.push_back(factorsFirstNumbers[firstFactorsCounter]);
			firstFactorsCounter++;
			secondFactorsCounter++;
		}else{
			if(factorsFirstNumbers[firstFactorsCounter] < factorsSecondNumbers[secondFactorsCounter]){
				firstFactorsCounter++;
			}else{
				secondFactorsCounter++;
			}
		}
	}
	return commonFactors;
}

#endif /* COMMONFACTORS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: checkifarrayareconsecutive.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\checkifarrayareconsecutive.h
 *  Created on			: May 10, 2014 :: 11:50:27 AM
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

#ifndef CHECKIFARRAYARECONSECUTIVE_H_
#define CHECKIFARRAYARECONSECUTIVE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool checkElementsConsecutiveFlags(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	vector<bool> flags(userInput.size(),false);
	int minValue = min_element(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		flags[userInput[counter]-minValue] = true;
	}
	for(unsigned int counter = 0;counter <flags.size();counter++){
		if(!flags[counter]){
			return false;
		}
	}
	return true;
}

bool checkElementsAreConsecutiveON(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(abs(userInput[counter])-minValue >= userInput.size()){
			return false;
		}
		if(userInput[abs(userInput[counter])-minValue] > 0){
			userInput[abs(userInput[counter])-minValue] *= -1;
		}else{
			return false;
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			return false;
		}
	}
	return true;
}

bool checkElementsAreConsecutiveONSum(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	int minElement = INT_MAX,maxElement = INT_MIN,sumOfVector= 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(minElement > userInput[counter]){
			minElement = userInput[counter];
		}
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
		sumOfVector += userInput[counter];
	}
	if(maxElement != minElement + userInput.size() - 1){
		return false;
	}
	int requiredSum = (userInput.size()/2)(minElement + maxElement);
	return requiredSum != sumOfVector?false:true;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool checkElementsAreConsecutiveONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(abs(userInput[counter] - userInput[counter+1]) != 1){
			return false;
		}
	}
	return true;
}
/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

bool checkIfElementsAreConsecutive(vector<int> userInput){
	if(userInput.size() ==  0){
		return true;
	}
	int minValue = min_element(userInput.begin(),userInput.end());
	bool elementFound;
	for(unsigned int counter = minValue;counter < minValue + userInput.size();counter++){
		elementFound = false;
		for(unsigned int arrayCounter = 0;arrayCounter < userInput.size();arrayCounter++){
			if(userInput[arrayCounter] == counter){
				elementFound = true;
				break;
			}
		}
		if(!elementFound){
			return false;
		}
	}
	return true;
}
#endif /* CHECKIFARRAYARECONSECUTIVE_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

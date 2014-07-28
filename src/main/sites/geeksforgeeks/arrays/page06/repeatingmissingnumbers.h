/****************************************************************************************************************************************************
 *  File Name   		: repeatingmissingnumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\repeatingmissingnumbers.h
 *  Created on			: May 10, 2014 :: 12:59:54 PM
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

#ifndef REPEATINGMISSINGNUMBERS_H_
#define REPEATINGMISSINGNUMBERS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findRepeatingMissingNumberON(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *result = (int *)malloc(2*sizeof(int));
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[abs(userInput[counter])-1] > 0){
			userInput[abs(userInput[counter])-1] *= -1;
		}else{
			result[0] = userInput[counter];
		}
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			result[1] = counter+1;
		}
	}
	return result;
}

int *findRepeatingMissingNumberHashmap(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *result = (int *)malloc(2*sizeof(int));
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			if(itToFrequencyMap->second > 1){
				result[0] = counter;
			}
		}else{
			result[1] = counter;
		}
	}
	return result;
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

int *findRepeatingMissingNumber(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *result = (int *)malloc(2*sizeof(int));
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		for(unsigned int arrayCounter = 0;arrayCounter < userInput.size();arrayCounter++){
			if(userInput[arrayCounter] == counter){
				if(arrayCounter + 1 < userInput.size()){
					if(userInput[arrayCounter] == userInput[arrayCounter+1]){
						result[0] = userInput[arrayCounter];
						arrayCounter += 1;
					}
				}
			}else{
				result[1] = counter;
			}
		}
	}
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findRepeatingMissingNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return null;
	}
	int *result = (int *)malloc(2*sizeof(int));
	unsigned int frequency;
	for(unsigned int counter = 1;counter <= userInput.size();counter++){
		frequency = 0;
		for(unsigned int arrayCounter = 0;arrayCounter < userInput.size();arrayCounter++){
			if(counter == userInput[arrayCounter]){
				frequency += 1;
			}
		}
		if(frequency == 0){
			result[1] = counter;
		}else{
			if(frequency == 2){
				result[0] = counter;
			}
		}
	}
	return result;
}
#endif /* REPEATINGMISSINGNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: printitemswithallchars.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page03\printitemswithallchars.h
 *  Created on			: Jun 26, 2014 :: 4:24:13 PM
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

#ifndef PRINTITEMSWITHALLCHARS_H_
#define PRINTITEMSWITHALLCHARS_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void setFrequencies(string userInput,hash_map<char,unsigned int> &frequencyMap){
	if(userInput.size() == 0){
		return;
	}
	frequencyMap.clear();
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) == frequencyMap.end()){
			frequencyMap.insert(pair<char,unsigned int>(userInput[counter],1));
		}else{
			frequencyMap[userInput[counter]] += 1;
		}
	}
}

vector<string> getItemsWithAllCharsOfPattern(vector<string> userInputs,string pattern){
	vector<string> result;
	if(userInputs.size() == 0){
		return result;
	}
	if(pattern == null){
		return userInputs;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInputs.size();counter++){
		setFrequencies(pattern,frequencyMap);
		for(unsigned int textCounter = 0;textCounter < userInputs[counter].size();textCounter++){
			if((itToFrequencyMap = frequencyMap.find(userInputs[counter][textCounter])) != frequencyMap.end()){
				if(itToFrequencyMap->second == 1){
					frequencyMap.erase(itToFrequencyMap->first);
				}else{
					frequencyMap[itToFrequencyMap->first] -= 1;
				}
			}
		}
		if(frequencyMap.size() == 0){
			result.push_back(userInputs[counter]);
		}
	}
	return result;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* PRINTITEMSWITHALLCHARS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

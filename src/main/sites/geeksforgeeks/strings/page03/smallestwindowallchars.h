/****************************************************************************************************************************************************
 *  File Name   		: smallestwindowallchars.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page03\smallestwindowallchars.h
 *  Created on			: Jun 26, 2014 :: 5:18:36 PM
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

#ifndef SMALLESTWINDOWALLCHARS_H_
#define SMALLESTWINDOWALLCHARS_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setFrequencyMap(string userInput,hash_map<char,unsigned int> &charFrequencyMap){
	if(userInput.size() == 0){
		return;
	}
	hash_map<char,unsigned int>::iterator itToCharFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();userInput++){
		if((itToCharFrequencyMap = charFrequencyMap.find(userInput[counter])) == charFrequencyMap.end()){
			charFrequencyMap[userInput[counter]] = 1;
		}else{
			charFrequencyMap[userInput[counter]] += 1;
		}
	}
}

unsigned int minWindowSize(string text,string pattern){
	if(text.size() == 0 || pattern == 0){
		return 0;
	}
	unsigned int numberOfMatchingChar = 0;
	hash_map<char,unsigned int> patternCharFrequency;
	hash_map<char,unsigned int>::iterator itToPatternCharFrequency;
	setFrequencyMap(pattern,patternCharFrequency);
	bool flag = true;
	unsigned int windowStartIndex,windowEndIndex;
	for(unsigned int counter = 0;counter < text.size();counter++){
		if((itToPatternCharFrequency = patternCharFrequency.find(text[counter])) != patternCharFrequency.end()){
			if(flag){
				windowStartIndex = counter;
				flag = false;
			}
			if(itToPatternCharFrequency->second == 1){
				patternCharFrequency.erase(itToPatternCharFrequency->first);
			}else{
				patternCharFrequency[itToPatternCharFrequency->first] -= 1;
			}
			if(patternCharFrequency.empty()){
				windowEndIndex = counter;
				break;
			}
		}
	}
	setFrequencyMap(pattern,patternCharFrequency);
	unsigned int minLength = windowEndIndex - windowStartIndex + 1;
	for(unsigned int counter = windowEndIndex+1;counter < text.size();counter++){
		if(text[counter] == text[windowStartIndex]){
			windowStartIndex++;
			while((itToPatternCharFrequency = patternCharFrequency.find(text[windowStartIndex])) == patternCharFrequency.end()){
				windowStartIndex++;
			}
			minLength = min(minLength,windowEndIndex - windowStartIndex +1);
		}
	}
	return minLength;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool doesTextContainAllChars(string text,string pattern){
	if(pattern == null){
		return true;
	}
	if(text == null){
		return false;
	}
	hash_map<char,unsigned int> charFrequencyMap;
	hash_map<char,unsigned int>::iterator itToCharFrequencyMap;
	setFrequencyMap(pattern,charFrequencyMap);
	for(unsigned int counter = 0;counter < text.size();counter++){
		if((itToCharFrequencyMap = charFrequencyMap.find(text[counter])) != charFrequencyMap.end()){
			if(itToCharFrequencyMap->second == 1){
				charFrequencyMap.erase(itToCharFrequencyMap->first);
			}else{
				charFrequencyMap[itToCharFrequencyMap->first] -= 1;
			}
		}
	}
	return charFrequencyMap.size() == 0;
}

unsigned int smallestWindowAllCharsON2(string text,string pattern){
	if(text == null || pattern == null){
		return 0;
	}
	unsigned int minWindowSize = 0;
	for(unsigned int outerCrawler = 0;outerCrawler < text.size();outerCrawler++){
		for(unsigned int innerCrawler = outerCrawler;innerCrawler < text.size();innerCrawler++){
			string substring(text,outerCrawler,innerCrawler-outerCrawler+1);
			if(doesTextContainAllChars(substring,pattern)){
				minWindowSize = min(minWindowSize,substring.size());
			}
		}
	}
	return minWindowSize;
}


#endif /* SMALLESTWINDOWALLCHARS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: tworepeatingelements.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\tworepeatingelements.h
 *  Created on			: May 1, 2014 :: 7:36:55 PM
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

#ifndef TWOREPEATINGELEMENTS_H_
#define TWOREPEATINGELEMENTS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

int *twoRepeatingElementXOR(vector<int> userInput){
	if(userInput.size() == 0 ||  userInput.size() == 1){
		return null;
	}
	int xorVector  = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		xorVector ^= userInput[counter];
	}
	unsigned int rightMostSetBit = log2(n&-n)+1,startCrawler = 0,rearCrawler = userInput.size()-1;
	int tempForSwap;
	while(startCrawler < rearCrawler){
		while(userInput[startCrawler] >> rightMostSetBit & 1){
			startCrawler++;
		}
		while(startCrawler < rearCrawler && !(userInput[rearCrawler] >> rightMostSetBit & 1)){
			rearCrawler--;
		}
		if(startCrawler < rearCrawler){
			tempForSwap = userInput[startCrawler];
			userInput[startCrawler] = userInput[rearCrawler];
			userInput[rearCrawler] = tempForSwap;
		}
	}
}

int *twoRepeatingElementONHashmap(vector<int> userInput){
	if(userInput.size() == 0 ||  userInput.size() == 1){
		return null;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			frequencyMap[userInput[counter]] += 1;
		}else{
			frequencyMap[userInput[counter]] = 1;
		}
	}
	unsigned int noOfRepeatsFound = 0;
	int *repeatedElements = (int *)malloc(2*sizeof(int));
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second == 2){
			repeatedElements[noOfRepeatsFound++] = itToFrequencyMap->first;
		}
	}
	return noOfRepeatsFound;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int *twoRepeatingElementONLOGNSorting(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	unsigned int noOfRepeatsFound = 0;
	int *repeatedElements = (int *)malloc(2*sizeof(int));
	sort(userInput.begin(),userInput.end());
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] == userInput[counter--]){
			repeatedElements[noOfRepeatsFound++] = userInput[counter];
		}
	}
	return repeatedElements;
}

vector<int> twoRepeatingElementsONLOGNBST(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}

}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *twoRepeatingElementsON2(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return null;
	}
	unsigned int noOfRepeatsFound = 0;
	int *repeatedElements = (int *)malloc(2*sizeof(int));
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				repeatedElements[noOfRepeatsFound++] = userInput[outerCounter];
				if(noOfRepeatsFound == 2){
					return repeatedElements;
				}
			}
		}
	}
	return null;
}

#endif /* TWOREPEATINGELEMENTS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

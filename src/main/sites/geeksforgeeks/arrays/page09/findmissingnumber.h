/****************************************************************************************************************************************************
 *  File Name   		: findmissingnumber.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\findmissingnumber.h
 *  Created on			: Apr 17, 2014 :: 1:10:47 AM
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

#ifndef FINDMISSINGNUMBER_H_
#define FINDMISSINGNUMBER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int findMissingNumberSum(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	unsigned int targetSum = 0,vectorSum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		vectorSum += userInput[counter];
		targetSum += counter+1;
	}
	targetSum += userInput.size() + 1;
	return targetSum - vectorSum;
}

//Tested
unsigned int findMissingNumberInplaceHashing(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[abs(userInput[counter])-1] *= -1;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] > 0){
			return counter+1;
		}
	}
	return userInput.size();
}

//Tested
unsigned int findMissingNumberXOR(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	unsigned int targetXorResult = 0,vectorXorResult = 0;
	for(unsigned int counter =0;counter < userInput.size();counter++){
		targetXorResult ^= counter+1;
		vectorXorResult ^= userInput[counter];
	}
	targetXorResult ^= userInput.size()+1;
	return targetXorResult ^ vectorXorResult;
}

//Tested
unsigned int findMissingNumberAuxspace(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	hash_map<unsigned int,bool> flags;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		flags.insert(pair<unsigned int,bool>(userInput[counter],true));
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(flags.find(counter+1) == flags.end()){
			return counter+1;
		}
	}
	return userInput.size();
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int findMissingNumberSortingLinearSearch(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	sort(userInput.begin(),userInput.end());
	if(userInput[0] != 1){
		return 1;
	}
	unsigned int counter = 0;
	while(counter < userInput.size()-1){
		if(userInput[counter+1]-userInput[counter] != 1){
			return counter+2;
		}
		counter++;
	}
	return userInput.size();
}

//Tested
unsigned int findMissingNumberBinarySearch(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if((unsigned int)userInput[middleIndex] != middleIndex+1){
		if(middleIndex - 1 >= startIndex){
			if((unsigned int)userInput[middleIndex - 1] != middleIndex){
				return findMissingNumberBinarySearch(userInput,startIndex,middleIndex-1);
			}else{
				return middleIndex+1;
			}
		}else{
			return startIndex + 1;
		}
	}else{
		return findMissingNumberBinarySearch(userInput,middleIndex+1,endIndex);
	}

}

//Tested
unsigned int findMissingNumberSortingBinarySearch(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	sort(userInput.begin(),userInput.end());
	return findMissingNumberBinarySearch(userInput,0,userInput.size()-1);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int findMissingNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return 1;
	}
	bool numberFound;
	for(unsigned int numberCounter = 1;numberCounter <= userInput.size()+1;numberCounter++){
		numberFound = false;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(numberCounter == (unsigned int)userInput[counter]){
				numberFound = true;
			}
		}
		if(!numberFound){
			return numberCounter;
		}
	}
	return UINT_MAX;
}

#endif /* FINDMISSINGNUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

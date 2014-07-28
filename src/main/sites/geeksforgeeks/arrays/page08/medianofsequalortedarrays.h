/****************************************************************************************************************************************************
 *  File Name   		: medianofsequalortedarrays.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\medianofsequalortedarrays.h
 *  Created on			: Apr 23, 2014 :: 9:49:59 PM
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

#ifndef MEDIANOFSEQUALORTEDARRAYS_H_
#define MEDIANOFSEQUALORTEDARRAYS_H_

/****************************************************************************************************************************************************/
/* 																	O(LOGN) Algorithm 																*/
/****************************************************************************************************************************************************/
//Tested
int medianOfTwoSortedEqualArrayONLOGNMain(vector<int> firstSortedArray,vector<int> secondSortedArray,unsigned int firstArrayStartCounter,unsigned int firstArrayEndCounter,unsigned int secondArrayStartCounter,unsigned int secondArrayEndCounter){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size() || (firstArrayEndCounter - firstArrayStartCounter != secondArrayEndCounter - secondArrayStartCounter)){
		throw "Vectors are not of equal sizes";
	}
	if(firstArrayStartCounter == firstArrayEndCounter){
		printf("%d %d",firstSortedArray[firstArrayStartCounter],secondSortedArray[secondArrayStartCounter]);
		return (firstSortedArray[firstArrayStartCounter] + secondSortedArray[secondArrayStartCounter])/2;
	}
	if(firstArrayEndCounter - firstArrayStartCounter == 1){
		int median = (max(firstSortedArray[firstArrayStartCounter],secondSortedArray[secondArrayStartCounter]) + min(firstSortedArray[firstArrayEndCounter],secondSortedArray[secondArrayEndCounter]))/2;
		return median;
	}
	unsigned int firstArrayMiddleIndex,secondArrayMiddleIndex;
	firstArrayMiddleIndex = ((firstArrayEndCounter + firstArrayStartCounter)/2);
	secondArrayMiddleIndex = (secondArrayEndCounter + secondArrayStartCounter)/2;
	if(firstSortedArray[firstArrayMiddleIndex] == secondSortedArray[secondArrayMiddleIndex]){
		return firstSortedArray[firstArrayMiddleIndex];
	}
	if(firstSortedArray[firstArrayMiddleIndex] > secondSortedArray[secondArrayMiddleIndex]){
		return medianOfTwoSortedEqualArrayONLOGNMain(firstSortedArray,secondSortedArray,firstArrayStartCounter,firstArrayMiddleIndex+1,secondArrayMiddleIndex,secondArrayEndCounter);
	}else{
		return medianOfTwoSortedEqualArrayONLOGNMain(firstSortedArray,secondSortedArray,firstArrayMiddleIndex,firstArrayEndCounter,secondArrayStartCounter,secondArrayMiddleIndex+1);
	}
}

//Tested
int medianOfTwoSortedEqualArrayONLOGN(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size()){
		throw "Vectors are not of equal sizes";
	}
	return medianOfTwoSortedEqualArrayONLOGNMain(firstSortedArray,secondSortedArray,0,firstSortedArray.size()-1,0,secondSortedArray.size()-1);
}

int medianOfTwoSortedEqualArrayONLOGNIterative(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size()){
		throw "Vectors are not of equal sizes";
	}
	unsigned int firstArrayStartIndex = 0,firstArrayEndIndex = firstSortedArray.size()-1,secondArrayStartIndex = 0,secondArrayEndIndex = secondSortedArray.size()-1;
	unsigned int middleFirstArrayIndex,middleSecondArrayIndex;
	while(true){
		if(firstArrayEndIndex == firstArrayStartIndex){
			return (firstSortedArray[firstArrayStartIndex] + secondSortedArray[secondArrayStartIndex])/2;
		}
		if(firstArrayEndIndex-firstArrayStartIndex == 1){
			int median = (max(firstSortedArray[firstArrayStartIndex],secondSortedArray[secondArrayStartIndex]) + min(firstSortedArray[firstArrayEndIndex],secondSortedArray[secondArrayEndIndex]))/2;
			return median;
		}
		middleFirstArrayIndex = (firstArrayEndIndex - firstArrayStartIndex)/2;
		middleSecondArrayIndex = (secondArrayEndIndex - secondArrayStartIndex)/2;
		if(firstSortedArray[middleFirstArrayIndex] == secondSortedArray[middleSecondArrayIndex]){
			return firstSortedArray[middleFirstArrayIndex];
		}
		if(firstSortedArray[middleFirstArrayIndex] > secondSortedArray[middleSecondArrayIndex]){
			firstArrayStartIndex = middleFirstArrayIndex+1;
			secondArrayEndIndex = middleSecondArrayIndex-1;
		}else{
			firstArrayEndIndex = middleFirstArrayIndex-1;
			secondArrayStartIndex = middleSecondArrayIndex+1;
		}
	}
	return INT_MIN;
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

int medianOfTwoSortedEqualArrayON(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size()){
		throw "Vectors are not of equal sizes";
	}

	unsigned int requiredIndex = firstSortedArray.size() + 1;
	unsigned int firstArrayCounter=0,secondArrayCounter=0,counter = 0;
	int median = 0,data;
	printf("%d\t",requiredIndex);
	while(counter <= requiredIndex){
		if(firstSortedArray[firstArrayCounter] < secondSortedArray[secondArrayCounter]){
			data = firstSortedArray[firstArrayCounter];
			firstArrayCounter++;
		}else{
			data = secondSortedArray[secondArrayCounter];
			secondArrayCounter++;
		}
		if(counter == requiredIndex-1){
			printf("%d\t",data);
			median += data;
		}
		if(counter ==  requiredIndex){
			printf("%d\t",data);
			median += data;
			median /= 2;
		}
		counter++;
	}
	return median;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
int medianOfTwoSortedEqualArrayONLOGNAuxspace(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size()){
		throw "Vectors are not of equal sizes";
	}
	firstSortedArray.insert(firstSortedArray.end(),secondSortedArray.begin(),secondSortedArray.end());
	sort(firstSortedArray.begin(),firstSortedArray.end());
	unsigned int middleIndex = firstSortedArray.size()/2;
	return (firstSortedArray[middleIndex] + firstSortedArray[middleIndex+1])/2;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getfloorValueIndexBinarySearch(vector<int> sortedArray,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return startIndex;
	}
	unsigned int middleIndex = (startIndex +  endIndex)/2;
	if(middleIndex+1 <= endIndex){
		if(middleIndex-1 <= startIndex){
			if(sortedArray[middleIndex-1] == sortedArray[middleIndex]){
				return getfloorValueIndexBinarySearch(sortedArray,key,startIndex,middleIndex-1);
			}
		}else{
			return startIndex;
		}
		if(sortedArray[middleIndex] <= key && sortedArray[middleIndex+1] >= key){
			return middleIndex;
		}
		if(sortedArray[middleIndex] > key){
			return getfloorValueIndexBinarySearch(sortedArray,key,startIndex,middleIndex-1);
		}else{
			return getfloorValueIndexBinarySearch(sortedArray,key,middleIndex+1,endIndex+1);
		}
	}else{
		return middleIndex;
	}
}

int medianOfTwoSortedEqualArrayON2(vector<int> firstSortedArray,vector<int> secondSortedArray){
	if(firstSortedArray.size() == 0 && secondSortedArray.size() == 0){
		return INT_MIN;
	}
	if(firstSortedArray.size() != secondSortedArray.size()){
		throw "Vectors are not of equal sizes";
	}
	unsigned int floorIndexOfCurrentValue;
	unsigned int numberOfElementsOnLeftSide,numberOfElementsOnRightSide;
	for(unsigned int firstArrayCounter = firstSortedArray.size()/2;firstArrayCounter < firstSortedArray.size();firstArrayCounter++){
		floorIndexOfCurrentValue = getfloorValueIndexBinarySearch(secondSortedArray,firstSortedArray[firstArrayCounter],0,secondSortedArray.size()-1);
		numberOfElementsOnLeftSide = firstArrayCounter + floorIndexOfCurrentValue - 1;
		numberOfElementsOnRightSide = firstSortedArray.size() - firstArrayCounter + secondSortedArray.size() - floorIndexOfCurrentValue;
		if(numberOfElementsOnLeftSide == numberOfElementsOnRightSide){
			return (firstSortedArray[firstArrayCounter] + secondSortedArray[floorIndexOfCurrentValue])/2;
		}
	}
	return INT_MIN;
}

#endif /* MEDIANOFSEQUALORTEDARRAYS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

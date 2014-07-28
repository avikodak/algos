/****************************************************************************************************************************************************
 *  File Name   		: findarrayissubarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\findarrayissubarray.h
 *  Created on			: May 10, 2014 :: 12:58:19 PM
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

#ifndef FINDARRAYISSUBARRAY_H_
#define FINDARRAYISSUBARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

bool areArraysSubarray(vector<int> firstArray,vector<int> secondArray){
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return false;
	}
	hash_map<int,unsigned int> frequencyMap;
	hash_map<int,unsigned int>::iterator itToFrequencyMap;
	if(firstArray.size() > secondArray.size()){
		for(unsigned int counter = 0;counter < firstArray.size();counter++){
			if((itToFrequencyMap = frequencyMap.find(firstArray[counter])) != frequencyMap.end()){
				frequencyMap[firstArray[counter]] += 1;
			}else{
				frequencyMap[firstArray[counter]] = 1;
			}
		}
		for(unsigned int counter = 0;counter < secondArray.size();counter++){
			if((itToFrequencyMap = frequencyMap.find(secondArray[counter])) == frequencyMap.end()){
				return false;
			}
			if(itToFrequencyMap->second == 1){
				frequencyMap.erase(secondArray[counter]);
			}else{
				frequencyMap[secondArray[counter]] -= 1;
			}
		}
	}else{
		for(unsigned int counter = 0;counter < secondArray.size();counter++){
			if((itToFrequencyMap = frequencyMap.find(secondArray[counter])) != frequencyMap.end()){
				frequencyMap[secondArray[counter]] += 1;
			}else{
				frequencyMap[secondArray[counter]] = 1;
			}
		}
		for(unsigned int counter = 0;counter < firstArray.size();counter++){
			if((itToFrequencyMap = frequencyMap.find(firstArray[counter])) == frequencyMap.end()){
				return false;
			}
			if(itToFrequencyMap->second == 1){
				frequencyMap.erase(firstArray[counter]);
			}else{
				frequencyMap[firstArray[counter]] -= 1;
			}
		}
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isArraySubarrayOfAnotherSorting(vector<int> firstArray,vector<int> secondArray){
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return false;
	}
	sort(firstArray.begin(),firstArray.end());
	sort(secondArray.begin(),secondArray.end());
	unsigned int firstArrayCrawler = 0,secondArrayCrawler = 0;
	while(firstArrayCrawler < firstArray.size() && secondArrayCrawler < secondArray.size()){
		if(firstArray[firstArrayCrawler] ==  secondArray[secondArrayCrawler]){
			firstArrayCrawler += 1;
			secondArrayCrawler += 1;
		}
		if(firstArray[firstArrayCrawler] > secondArray[secondArrayCrawler]){
			return false;
		}else{
			firstArrayCrawler++;
		}

	}
	return true;
}

bool searchForNodeInFBST(iftNode *ptr,int key){
	if(ptr == null){
		return false;
	}
	if(ptr->value == key){
		if(ptr->frequency == 0){
			return false;
		}
		ptr->frequency -= 1;
		return true;
	}
	if(ptr->value > key){
		return searchForNodeInFBST(ptr->left,key);
	}else{
		return searchForNodeInFBST(ptr->right,key);
	}
}

bool isArraySubarrayOfAnotherONLOGNBST(vector<int> firstArray,vector<int> secondArray){
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return false;
	}
	iftNode *ptr;
	treeutils *utils = new treeutils();
	if(firstArray.size() > secondArray.size()){
		ptr = utils->getFBSTreeFromVector(firstArray);
		for(unsigned int counter = 0;counter < secondArray.size();counter++){
			if(!searchForNodeInFBST(ptr,secondArray[counter])){
				return false;
			}
		}
	}else{
		ptr = utils->getFBSTreeFromVector(secondArray);
		for(unsigned int counter = 0;counter < firstArray.size();counter++){
			if(!searchForNodeInFBST(ptr,firstArray[counter])){
				return false;
			}
		}
	}
	return true;
}

//Works for distinct elements
bool isArraySubarrayBinarySearchSorting(vector<int> firstArray,vector<int> secondArray){
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return false;
	}
	if(firstArray.size() > 0){
		sort(firstArray.begin(),firstArray.end());
		for(unsigned int counter  = 0;counter < secondArray.size();counter++){
			if(!binary_search(firstArray.begin(),firstArray.end(),secondArray[counter])){
				return false;
			}
		}
	}else{
		sort(secondArray.begin(),secondArray.end());
		for(unsigned int counter  = 0;counter < firstArray.size();counter++){
			if(!binary_search(secondArray.begin(),secondArray.end(),firstArray[counter])){
				return false;
			}
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
bool isArraySubarrayOfAnother(vector<int> firstArray,vector<int> secondArray){
	if(firstArray.size() == 0 || secondArray.size() == 0){
		return false;
	}
	if(firstArray.size() > secondArray.size()){
		for(unsigned int outerCrawler = 0;outerCrawler < secondArray.size();outerCrawler++){
			for(unsigned int innerCrawler = 0;innerCrawler < firstArray.size();innerCrawler++){
				if(firstArray[innerCrawler] == secondArray[outerCrawler]){
					return false;
				}
			}
		}
	}else{
		for(unsigned int outerCrawler = 0;outerCrawler < firstArray.size();outerCrawler++){
			for(unsigned int innerCrawler = 0;innerCrawler < secondArray.size();innerCrawler++){
				if(secondArray[innerCrawler] == firstArray[outerCrawler]){
					return false;
				}
			}
		}
	}
	return true;
}
#endif /* FINDARRAYISSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: unionintersection.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\unionintersection.h
 *  Created on			: May 1, 2014 :: 7:35:57 PM
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

#ifndef UNIONINTERSECTION_H_
#define UNIONINTERSECTION_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<vector<int> > unionIntersectionOfSortedArray(vector<int> firstArray,vector<int> secondArray){
	vector<vector<int> > unionOfSortedArray,intersectionOfSortedArray;
	vector<int> unionIntersectionArrays;
	if(firstArray.size() == 0 && secondArray.size() == 0){
		return unionOfSortedArray;
	}
	if(firstArray.size() == 0 || secondArray.size() == 0){
		if(firstArray.size() == 0){
			unionIntersectionArrays.push_back(secondArray);
		}else{
			unionIntersectionArrays.push_back(firstArray);
		}
		unionIntersectionArrays.push_back(intersectionOfSortedArray);
	}
	unsigned int firstSortedArrayCrawler = 0,secondSortedArrayCrawler = 0;
	while(firstSortedArrayCrawler < firstArray.size() && secondSortedArrayCrawler < secondArray.size()){
		if(firstArray[firstSortedArrayCrawler] ==  secondArray[secondSortedArrayCrawler]){
			intersectionOfSortedArray.push_back(firstArray[firstSortedArrayCrawler]);
			if(unionOfSortedArray.size() == 0 || unionOfSortedArray[unionOfSortedArray.size() - 1] != firstArray[firstSortedArrayCrawler]){
				unionOfSortedArray.push_back(firstArray[firstSortedArrayCrawler]);
			}
		}
		if(firstArray[firstSortedArrayCrawler] < secondArray[secondSortedArrayCrawler]){
			firstSortedArrayCrawler++;
			if(unionOfSortedArray.size() == 0 || unionOfSortedArray[unionOfSortedArray.size() - 1] != firstArray[firstSortedArrayCrawler]){
				unionOfSortedArray.push_back(firstArray[firstSortedArrayCrawler]);
			}
		}else{
			secondSortedArrayCrawler++;
			if(unionOfSortedArray.size() == 0 || unionOfSortedArray[unionOfSortedArray.size() - 1] != secondArray[secondSortedArrayCrawler]){
				unionOfSortedArray.push_back(firstArray[firstSortedArrayCrawler]);
			}
		}
	}
	unionIntersectionArrays.push_back(unionOfSortedArray);
	unionIntersectionArrays.push_back(intersectionOfSortedArray);
	return unionIntersectionArrays;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

void setUnionIntersectionInVector(iftNode *ptr,vector<vector<int> > &unionIntersectionArray){
	if(ptr == null){
		return;
	}
	unionIntersectionArray[0].push_back(ptr->value);
	while(ptr->frequency--){
		unionIntersectionArray[1].push_back(ptr->value);
	}
	setUnionIntersectionInVector(ptr->left,unionIntersectionArray);
	setUnionIntersectionInVector(ptr->right,unionIntersectionArray);
}

vector<vector<int> > unionIntersectionOfSortedArrayONLOGN(vector<int> firstArray,vector<int> secondArray){
	vector<int> unionOfSortedArray,intersectionOfSortedArray;
	vector<vector<int> > unionIntersectionArrays;
	if(firstArray.size() == 0 && secondArray.size() == 0){
		return unionOfSortedArray;
	}
	if(firstArray.size() == 0 || secondArray.size() == 0){
		if(firstArray.size() == 0){
			unionIntersectionArrays.push_back(secondArray);
		}else{
			unionIntersectionArrays.push_back(firstArray);
		}
		unionIntersectionArrays.push_back(intersectionOfSortedArray);
	}
	iftNode *frequencyBST = null;
	treeutils *utils = new treeutils();
	utils->getFBSTreeFromVector(firstArray);
	utils->appendToFBST(&frequencyBST,secondArray);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<vector<int> > unionIntersectionOfSortedArrayON2(vector<int> firstArray,vector<int> secondArray){
	vector<int> unionOfSortedArray,intersectionOfSortedArray;
	vector<vector<int> > unionIntersectionArrays;
	if(firstArray.size() == 0 && secondArray.size() == 0){
		return unionOfSortedArray;
	}
	if(firstArray.size() == 0 || secondArray.size() == 0){
		if(firstArray.size() == 0){
			unionIntersectionArrays.push_back(secondArray);
		}else{
			unionIntersectionArrays.push_back(firstArray);
		}
		unionIntersectionArrays.push_back(intersectionOfSortedArray);
	}
	//Setting union
	bool isElementFound;
	for(unsigned int counter = 0;counter < firstArray.size();counter++){
		isElementFound = false;
		for(unsigned int unionCounter = 0;unionCounter < unionOfSortedArray.size();unionCounter++){
			if(firstArray[counter] == unionOfSortedArray[unionCounter]){
				isElementFound = true;
				break;
			}
		}
		if(!isElementFound){
			unionOfSortedArray.push_back(firstArray[counter]);
		}
	}
	for(unsigned int counter = 0;counter < secondArray.size();counter++){
		isElementFound = false;
		for(unsigned int unionCounter = 0;unionCounter < unionOfSortedArray.size();unionCounter++){
			if(secondArray[counter] == unionOfSortedArray[unionCounter]){
				isElementFound = true;
				break;
			}
		}
		if(!isElementFound){
			unionOfSortedArray.push_back(secondArray[counter]);
		}
	}
	for(unsigned int firstArrayCrawler = 0;firstArrayCrawler < firstArray.size();firstArrayCrawler++){
		isElementFound  = false;
		for(unsigned int secondArrayCrawler = 0;secondArrayCrawler < secondArray.size();secondArrayCrawler++){
			if(firstArray[firstArrayCrawler] == secondArray[secondArrayCrawler]){
				isElementFound = true;
				secondArray[secondArrayCrawler] = INT_MAX;
			}
		}
		if(!isElementFound){
			intersectionOfSortedArray.push_back(firstArray[firstArrayCrawler]);
		}
	}
	unionIntersectionArrays.push_back(unionOfSortedArray);
	unionIntersectionArrays.push_back(intersectionOfSortedArray);
	return unionIntersectionArrays;
}


#endif /* UNIONINTERSECTION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

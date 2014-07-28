/****************************************************************************************************************************************************
 *  File Name   		: findtripletforsum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\findtripletforsum.h
 *  Created on			: May 10, 2014 :: 10:35:38 AM
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

#ifndef FINDTRIPLETFORSUM_H_
#define FINDTRIPLETFORSUM_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findTripletForSumON2(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int key){
	if(firstPtr == null || secondPtr == null || thirdPtr == null){
		return null;
	}
	sillNode *firstSillCrawler = firstPtr,*secondSillCrawler,*thirdSillCrawler;
	int currentSum;
	sillutils *utils = new sillutils();
	utils->selectionSortSill(secondPtr);
	utils->selectionSortSill(thirdPtr,false);
	while(firstSillCrawler != null){
		secondSillCrawler = secondPtr;
		thirdSillCrawler = thirdPtr;
		while(secondSillCrawler != null && thirdSillCrawler != null){
			currentSum = firstSillCrawler->value + secondSillCrawler->value + thirdSillCrawler->value;
			if(currentSum == key){
				int *triplet = (int *)malloc(3*sizeof(int));
				triplet[0] = firstPtr->value;
				triplet[1] = secondPtr->value;
				triplet[2] = thirdPtr->value;
				return triplet;
			}
			if(currentSum > key){
				thirdSillCrawler = thirdSillCrawler->next;
			}else{
				secondSillCrawler = secondSillCrawler->next;
			}
		}

	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(N^3) Algorithm 																    */
/****************************************************************************************************************************************************/
int *findTripletForSumON3(sillNode *firstPtr,sillNode *secondPtr,sillNode *thirdPtr,int key){
	if(firstPtr == null || secondPtr == null || thirdPtr == null){
		return null;
	}
	sillNode *firstSillCrawler = firstPtr,*secondSillCrawler,*thirdSillCrawler;
	while(firstSillCrawler != null){
		secondSillCrawler = secondPtr;
		while(secondSillCrawler != null){
			thirdSillCrawler = thirdPtr;
			while(thirdSillCrawler != null){
				if(firstPtr->value + secondPtr->value + thirdPtr->value == key){
					int *triplet = (int *)malloc(3*sizeof(int));
					triplet[0] = firstPtr->value;
					triplet[1] = secondPtr->value;
					triplet[2] = thirdPtr->value;
					return triplet;
				}
				thirdSillCrawler = thirdSillCrawler->next;
			}
			secondSillCrawler = secondSillCrawler->next;
		}
		firstSillCrawler = firstSillCrawler->next;
	}
	return null;
}


#endif /* FINDTRIPLETFORSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/


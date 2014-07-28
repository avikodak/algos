/****************************************************************************************************************************************************
 *  File Name   		: intersectionoftwosorted.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\intersectionoftwosorted.h
 *  Created on			: May 1, 2014 :: 7:46:12 PM
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

#ifndef INTERSECTIONOFTWOSORTED_H_
#define INTERSECTIONOFTWOSORTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *getIntersectionOfTwoSortedSill(sillNode *firstSill,sillNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	sillNode *intersectionListHead = null,*intersectionListCrawler;
	while(firstSill != null && secondSill != null){
		if(firstSill->value == secondSill->value){
			if(intersectionListHead == null){
				intersectionListHead = new sillNode(firstSill->value);
				intersectionListCrawler = intersectionListHead;
			}else{
				intersectionListCrawler->next = new sillNode(firstSill->value);
				intersectionListCrawler = intersectionListCrawler->next;
			}
			firstSill = firstSill->next;
			secondSill = secondSill->next;
		}else{
			if(firstSill->value < secondSill->value){
				firstSill = firstSill->next;
			}else{
				secondSill = secondSill->next;
			}
		}
	}
	return intersectionListHead;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *getIntersctionOfTwoSortedSillON2(sillNode *firstSill,sillNode *secondSill){
	if(firstSill == null || secondSill == null){
		return null;
	}
	sillNode *firstSillCrawler = firstSill,*secondSillCrawler = secondSill;
	sillNode *intersectionListHead = null,*intersectionListCrawler;
	while(firstSillCrawler != null){
		while(secondSillCrawler != null && firstSillCrawler->value != secondSillCrawler->value){
			secondSillCrawler = secondSillCrawler->next;
		}
		if(secondSillCrawler != null){
			if(intersectionListHead == null){
				intersectionListHead = new sillNode(firstSillCrawler->value);
				intersectionListCrawler = intersectionListHead;
			}else{
				intersectionListCrawler->next = new sillNode(firstSillCrawler->value);
				intersectionListCrawler = intersectionListCrawler->next;
			}
			secondSillCrawler->value = INT_MAX;
		}
		firstSillCrawler = firstSillCrawler->next;
	}
	return intersectionListHead;
}

#endif /* INTERSECTIONOFTWOSORTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************
 *  File Name   		: leadersinarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\leadersinarray.h
 *  Created on			: May 1, 2014 :: 5:39:48 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/leaders-in-an-array/
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

#ifndef LEADERSINARRAY_H_
#define LEADERSINARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void setLeadersOfArray(vector<int> userInput,vector<int> &leaders,unsigned int currentIndex){
	if(userInput.size() == 0 || currentIndex >= userInput.size()){
		return;
	}
	static int maxTillNow = INT_MIN;
	setLeadersOfArray(userInput,leaders,currentIndex+1);
	if(maxTillNow < userInput[currentIndex]){
		leaders.push_back(userInput[currentIndex]);
		maxTillNow = userInput[currentIndex];
	}
}

//Tested
vector<int> getLeadersInArray(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	setLeadersOfArray(userInput,leaders,0);
	return leaders;
}

//Tested
vector<int> leadersInArrayIterative(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	leaders.push_back(userInput[userInput.size()-1]);
	int maxElementTillNow = userInput[userInput.size()-1];
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		if(userInput[counter] > maxElementTillNow){
			maxElementTillNow = userInput[counter];
			leaders.push_back(maxElementTillNow);
		}
	}
	return leaders;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
vector<int> leadersInArrayON2(vector<int> userInput){
	vector<int> leaders;
	if(userInput.size() == 0){
		return leaders;
	}
	unsigned int outerCrawler,innerCrawler;
	bool isLeader;
	for(outerCrawler = 0;outerCrawler<userInput.size();outerCrawler++){
		isLeader = true;
		for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[innerCrawler] > userInput[outerCrawler]){
				isLeader = false;
			}
		}
		if(isLeader){
			leaders.push_back(userInput[outerCrawler]);
		}
	}
	return leaders;
}

#endif /* LEADERSINARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

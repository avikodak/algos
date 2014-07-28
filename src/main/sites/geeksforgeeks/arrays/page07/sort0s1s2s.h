/****************************************************************************************************************************************************
 *  File Name   		: sort0s1s2s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\sort0s1s2s.h
 *  Created on			: May 1, 2014 :: 7:37:13 PM
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

#ifndef SORT0S1S2S_H_
#define SORT0S1S2S_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void sort0s1s2sBuckets(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	vector<unsigned int> frequency(0,3);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		switch(userInput[counter]){
		case 0:
			frequency[0] += 1;
			break;
		case 1:
			frequency[1] += 1;
			break;
		case 2:
			frequency[2] += 1;
			break;
		}
	}
	unsigned int fillCounter = 0;
	for(unsigned int counter = 0;counter < 3;counter++){
		while(frequency[counter]--){
			userInput[fillCounter++] = counter;
		}
	}
}

unsigned int sort0sQuickDivide(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < backCrawler){
		while(userInput[frontCrawler] == 0){
			frontCrawler++;
		}
		while(frontCrawler < backCrawler && userInput[backCrawler] != 0){
			backCrawler--;
		}
		if(frontCrawler < backCrawler){
			temp = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[backCrawler];
			userInput[backCrawler] = temp;
		}
	}
	return frontCrawler;
}

void sort1s2sQuickSort(vector<int> userInput,unsigned int startIndex){
	if(startIndex >= userInput.size()){
		return;
	}
	unsigned int frontCrawler = startIndex,backCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < backCrawler){
		while(userInput[frontCrawler] == 1){
			frontCrawler++;
		}
		while(frontCrawler < backCrawler && userInput[backCrawler] == 2){
			backCrawler--;
		}
		if(frontCrawler < backCrawler){
			temp = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[backCrawler];
			userInput[backCrawler] = temp;
		}
	}
}

void sort0s1s2sQuickSort(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int remainingIndex = sort0sQuickDivide(userInput);
	if(remainingIndex == UINT_MAX){
		return;
	}
	sort1s2sQuickSort(userInput,remainingIndex);
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
void sort0s1s2sONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	sort(userInput.begin(),userInput.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void sort0s1s2sON2(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int temp;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < userInput.size()-1;innerCounter++){
			if(userInput[innerCounter] > userInput[innerCounter+1]){
				temp = userInput[innerCounter];
				userInput[innerCounter] = userInput[innerCounter+1];
				userInput[innerCounter+1] = temp;
			}
		}
	}
}

#endif /* SORT0S1S2S_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

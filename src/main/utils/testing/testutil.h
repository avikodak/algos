/****************************************************************************************************************************************************
 *  File Name   		: testutil.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\testing\testutil.h
 *  Created on			: Apr 10, 2014 :: 4:08:52 AM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TESTUTIL_H_
#define TESTUTIL_H_

//Tested
vector<int> generateIVector(unsigned int requiredSizeOfVector,int lowerLimit = INT_MIN,int upperLimit = INT_MAX){
	vector<int> randomnumbers;
	srand(time(NULL));
	for(unsigned int counter = 0;counter < requiredSizeOfVector;counter++){
		randomnumbers.push_back(rand()%upperLimit + lowerLimit);
	}
	return randomnumbers;
}

#endif /* TESTUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

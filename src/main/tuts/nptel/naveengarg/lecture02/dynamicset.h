/****************************************************************************************************************************************************
 *  File Name   		: dynamicset.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture02\dynamicset.h
 *  Created on			: May 29, 2014 :: 1:28:39 AM
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


#ifndef DYNAMICSET_H_
#define DYNAMICSET_H_

/*Methods to be implemented
	New - Constructors
	Insert - Manipulation function
	Delete	- Manipulation function
	IsIn - Access function
 */
class dynamicset{
private:
	hash_map<int,bool> existenceMap;

public:
	bool isin(int userInput){
		hash_map<int,bool>::iterator itToExistenceMap;
		itToExistenceMap = this->existenceMap.find(userInput);
		return !(itToExistenceMap == this->existenceMap.end());
	}

	void insert(int userInput){
		if(isin(userInput)){
			printf("Already exists in dynamic set\n");
			return;
		}
		this->existenceMap.insert(pair<int,bool>(userInput,true));
	}

	void deletekey(int userInput){
		if(!isin(userInput)){
			printf("Key is not present in dynamic set");
			return;
		}
		this->existenceMap.erase(userInput);
	}
};


#endif /* DYNAMICSET_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

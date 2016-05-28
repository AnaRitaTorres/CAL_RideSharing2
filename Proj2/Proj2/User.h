/*
 * User.h
 *
 *  Created on: 21/04/2016
 *      Author: Sérgio
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>

using namespace std;

class User
{
	int user_id;
	string address;
	string dest;
	int departureh;
	int departurem;
	int arrivalh;
	int arrivalm;
	bool hasVehicle;
public:
	User(int id, string adr, string d, int deph, int depm, int arrh, int arrm, bool v);
	int getUserId();
	string getAddress();
	string getDest();
	int getArrivalH();
	int getArrivalM();
	int getDepartureH();
	int getDepartureM();
	bool getHasVehicle();

};




#endif /* USER_H_ */

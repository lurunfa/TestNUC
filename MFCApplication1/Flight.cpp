#include "pch.h"
#include "Flight.h"
#include "ConstantUtils.h"
#include <conio.h>

#define FILE_PATH ConstantUtils::FILE_PATH
#define MY_SELF ConstantUtils::MY_SELF
#define DRONE_NAME ConstantUtils::DRONE_NAME
#define FLIGHT_TYPE_NAME ConstantUtils::FLIGHT_TYPE_NAME
#define FLIGHT_NUMBER_NAME ConstantUtils::FLIGHT_NUMBER_NAME
#define FLIGHT_NAME ConstantUtils::FLIGHT_NAME
#define FLIGHT_ISMAIN_NAME ConstantUtils::FLIGHT_ISMAIN_NAME
#define FLIGHT_IP_NAME ConstantUtils::FLIGHT_IP_NAME
#define FLIGHT_PORT_NAME ConstantUtils::FLIGHT_PORT_NAME

Flight::Flight()
{
}


Flight::~Flight()
{
}

CString& Flight::getName()
{
	return name;
}

void Flight::setName(CString& name)
{
	this->name = name;
}

CArray<Flight, Flight&>& Flight::getArray()
{
	CArray<Flight, Flight&>* flightArray = new CArray<Flight, Flight&>();
	CFileFind finder;
	
	BOOL ifFind = finder.FindFile(FILE_PATH);
	//if (ifFind)
	//{
		//¶ÁÈ¡×Ô¼º±àºÅ
		CString name;
		CString type;
		CString ip;
		CString port;
		CString number;
		CString isMain;

		::GetPrivateProfileStringW(MY_SELF,FLIGHT_NAME , NULL, name.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		::GetPrivateProfileStringW(MY_SELF, FLIGHT_TYPE_NAME, NULL, type.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		::GetPrivateProfileStringW(MY_SELF, FLIGHT_IP_NAME, NULL, ip.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		::GetPrivateProfileStringW(MY_SELF, FLIGHT_PORT_NAME, NULL, port.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		::GetPrivateProfileStringW(MY_SELF, FLIGHT_ISMAIN_NAME, NULL, isMain.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		::GetPrivateProfileStringW(MY_SELF, FLIGHT_NUMBER_NAME, NULL, number.GetBuffer(MAX_PATH), MAX_PATH, FILE_PATH);
		name.ReleaseBuffer();
		type.ReleaseBuffer();
		ip.ReleaseBuffer();
		port.ReleaseBuffer();
		number.ReleaseBuffer();
		isMain.ReleaseBuffer();
		_cprintf("\n%S", type);
	//}
	return *flightArray;
}

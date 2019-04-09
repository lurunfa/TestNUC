#pragma once

class Flight
{
public:
	Flight();
	~Flight();
	CString& getName();
	void setName(CString& name);
	CArray<Flight,Flight&>& getArray();
	
private:
	CString name;
};


#pragma once

class Exceptions_from_tables
{
public:
	void except_throw(int nomber)
	{
		switch (nomber)
		{
		case 101:
			throw("Attempt to take string value that is out of range");
			break;
		case 102:
			throw("Attempt to create table with negative size");
			break;
		case 103:
			throw("Attempt to resize memory with less size");
			break;
		case 104:
			throw(/*"Attempt to get letter from tree with hight level"*/);
			break;
		case 105:
			throw(/*"Attempt to initialize tree with negative size"*/);
			break;
		case 106:
			throw(/*"Attempt to create text with too long start string"*/);
			break;
		default:
			throw("Unknown error");
			break;
		}
	}
};
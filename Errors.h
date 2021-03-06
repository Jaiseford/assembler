/*Jaise Vincent
Software Design
Professor Miller
Errors.h  */


//Class to manage errors

//All are static members and can be accessed anywhere


#ifndef _ERRORS_H
#define _ERRORS_H

#include "stdafx.h"

class Errors{

public:
    
    // Initializes error reports.
    static void InitErrorReporting();

    // Records an error message.
    static void RecordError(string a_emsg);

    // Displays the collected error message.
    static void DisplayErrors();

	// Create an error with a location attached to it
	static string CreateError(int a_loc, const string &a_errMsg);

	// Create an error without location
	static string CreateError(const string &a_errMsg);

	static bool IsEmpty() { return m_ErrorMsgs.size() == 0; }
private:

	// All the error messages
    static vector<string> m_ErrorMsgs;
};
#endif
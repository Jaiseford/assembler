#include "Errors.h"
#include "stdafx.h"

using namespace std;


vector<string> Errors::m_ErrorMsgs;



void Errors::InitErrorReporting() {
	m_ErrorMsgs.clear();
	return;
}
/*void Errors::InitErrorReporting()*/

/**/
/*
				Errors::RecordError() Errors::RecordError()

	NAME

			Errors::RecordError() - Records Error into vector

	SYNOPSIS

			Errors::RecordError(string &a_emsg);
			a_emsg - a string to record the error message

	DESCRIPTION

			If string exists, puts it into vector of error message
		
	RETURNS

			((void))

*/
void Errors::RecordError(string a_emsg) {
	if (a_emsg.size() == 0) {
		return;
	}
	m_ErrorMsgs.push_back(a_emsg);
}
/*void Errors::RecordError(string &a_emsg)*/


/**/
/*
				void Errors::OutputErrors() void Errors::OutputErrors()

		NAME
			
			void Errors::OutputErrors - output the errors in the vector

		SYNOPSIS
			
			void Errors::OutputErrors();

		DESCRIPTION

				Output one error at a time and pop it off the vector

		RETURNS

				((void))
*/
void Errors::DisplayErrors() {
	cout << "There were " << m_ErrorMsgs.size() << " errors" << endl;
	while (!m_ErrorMsgs.empty()) {
		cout << m_ErrorMsgs.back() << endl;
		m_ErrorMsgs.pop_back();
	}
}
/*void Errors::DisplayErrors()*/

/*
				string Errors::CreateError() string Errors::CreateError()

		NAME

			string Errors::CreateError - add an error to the vector

		SYNOPSIS

			string Errors::CreateError(int a_loc, const string &a_errmsg);

					a_loc --> loction of the error
					a_errmsg --> error message

		DESCRIPTION

			Creates an error and returns the message into the function that called it

		RETURNS

			string - the error message
*/
string Errors::CreateError(int a_loc, const string &a_errMsg) {
	string location = to_string(a_loc);

	return ("Error at location " + location + " :: " + a_errMsg + "\n");
}
/*string Errors::CreateError(int a_loc, const string &a_errMsg);*/


/*
				string Errors::CreateError() string Errors::CreateError()

		NAME

			string Errors::CreateError - add an error to the vector

		SYNOPSIS

			string Errors::CreateError(const string &a_errmsg);
						a_errmsg --> error message

		DESCRIPTION

			Creates an error and returns the message into the function that called it

		RETURNS
				string - the error message
*/
string Errors::CreateError(const string &a_errMsg) {
	return ("Error :: " + a_errMsg + "\n");
}
/*string Errors::CreateError(const string &a_errMsg);*/
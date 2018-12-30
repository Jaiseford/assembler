/*Jaise Vincent
Software Design
Professor Miller
FileAccess.h  */

//		File access to source file.

#ifndef _FILEACCESS_H 
#define _FILEACCESS_H 

#include <fstream>
#include <stdlib.h>
#include <string>

class FileAccess {

public:

    // Opens file.
    FileAccess(int argc, char *argv[]);

    // Get the next line from the source file.
    bool GetNextLine(string &a_buff);

    // Put the file pointer back to the beginning of the file.
    void Rewind();

private:

	// Source file object.
    ifstream m_sfile;		
};
#endif
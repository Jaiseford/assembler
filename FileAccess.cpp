/*Jaise Vincent
Software Design
Professor Miller
FileAccess.cpp  */



//  Implementation of file access class.

#include "stdafx.h"
#include "FileAccess.h"


/*
FileAccess::FileAccess() FileAccess()

NAME

	FileAccess::FileAccess - constructor for file access

SYNOPSIS

	FileAccess::FileAccess(int argc, char *argv[]);

	
		argc --> number of arguments - should be 2
		argv[] --> pointer to arguments - should be filename

DESCRIPTION

	If file is correct, opens file, if incorrect exits program

RETURNS

	Nothing, file is constructor
*/
FileAccess::FileAccess( int argc, char *argv[] )
{
    // Check that there is exactly one run time parameter.
    if( argc != 2 ) {
        cerr << "Usage: Assem <FileName>" << endl;
        exit( 1 );
    }
    // Open the file.  One might question if this is the best place to open the file.
    // One might also question whether we need a file access class.
    m_sfile.open( argv[1], ios::in );

    // If the open failed, report the error and terminate.
    if( ! m_sfile ) {
        cerr << "Source file could not be opened, assembler terminated."
            << endl;
        exit( 1 ); 
    }
}
/*FileAccess::FileAccess(int agrc, char *argv[]);*/

// Get the next line from the file.
/**/
/*
bool FileAccess::GetNextLine bool FileAccess::GetNextLine

NAME

	bool FileAccess::GetNextLine - get the next line in the file

SYNOPSIS

	bool FileAccess::GetNextLine(string &a_buff);

		a_buff --> string to read line of file into, passed by reference

DESCRIPTION

	This function checks if the file is at the end if it is it returns false
	if it is not the end it will put a line into the string and return true

RETURNS

	This function returns a BOOL, true if the function put the next line into the string,
	false if it is at the end 
*/
bool FileAccess::GetNextLine(string &a_buff)
{

    // If there is no more data, return false.
    if(m_sfile.eof()) {
    
        return false;
    }
    getline(m_sfile, a_buff);
    
    // Return indicating success.
    return true;
}
/*bool FileAccess::GetNextLine(string &a_buff)*/

/**/
/*
FileAccess::Rewind FileAccess::Rewind

NAME

	void FileAccess::rewind - bring the file to the beginning

SYNOPSIS

	void FileAccess::rewind();

DESCRIPTION

	This function rewinds the file to the beginning so it can be parsed again

RETURNS

	((void))
*/
void FileAccess::Rewind()
{
    // Clean all file flags and go back to the beginning of the file.
    m_sfile.clear();
    m_sfile.seekg(0, ios::beg);
}
/*void FileAccess::Rewind();*/
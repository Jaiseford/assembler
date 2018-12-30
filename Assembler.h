/*Jaise Vincent 
Software Design
Professor Miller
Assembler.h  */


//		Container for assembler class

#pragma once 

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Emulator.h"


class Assembler {

public:
    Assembler( int argc, char *argv[] );

    // Pass I - establish the locations of the symbols
    void PassI( );

    // Pass II - generate a translation
    void PassII( );

    // Display the symbols in the symbol table.
    void DisplaySymbolTable() { m_symtab.DisplaySymbolTable(); }
    
    // Run emulator on the translation.
    void RunEmulator();

	void PrintEm();
private:
	string GetLoc();

	// File Access object
    FileAccess m_facc;	  

	// Symbol table object
    SymbolTable m_symtab;

	// Instruction object
    Instruction m_inst;	

	// Emulator object
    emulator m_emul;        
};


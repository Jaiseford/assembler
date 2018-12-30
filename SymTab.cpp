/*Jaise Vincent
Software Design
Professor Miller
Symtab.cpp  */


// Implements Symbol table class
#include "stdafx.h"
#include "SymTab.h"
#include "Errors.h"

/**/
/*
void SymbolTable::AddSymbol() void SymbolTable::AddSymbol()

NAME

	AddSymbol - adds a new symbol to the symbol table.

SYNOPSIS

	void AddSymbol(string &a_symbol, int a_loc);

		a_symbol --> string which represents symbol name
		a_loc --> integer representing location

DESCRIPTION

	This function will place the symbol "a_symbol" and its location "a_loc"
	in the symbol table.

RETURNS

	((void))

/**/
void SymbolTable::AddSymbol(string &a_symbol, int a_loc)
{

    // If the symbol is already in the symbol table, record it as multiply defined.
    map<string, int>::iterator st;
    st = m_symbolTable.find( a_symbol );
    if(st != m_symbolTable.end()) {
        st->second = multiplyDefinedSymbol;
		Errors::RecordError(Errors::CreateError(a_loc, string("variable defined more than once")));
        return;
    }

    // Record a the  location in the symbol table.
    m_symbolTable[a_symbol] = a_loc;
}
/*void SymbolTable::AddSymbol(string &a_symbol, int a_loc);*/

/**/
/*
void SymbolTable::DisplaySymbolTable() void SymbolTable::DisplaySymbolTable()
		
NAME 

	Display Symbol Table - outputs the table

SYNOPSIS

	void DisplaySymbolTable();

DESCRIPTION

	This will print the table and its contents to the screen

RETURNS

	((void))


/**/
void SymbolTable::DisplaySymbolTable() {
	cout << "Symbol#\tSymbol\tLocation" << endl;
	count = 0;
	for (map<string, int>::iterator st = m_symbolTable.begin(); st != m_symbolTable.end(); st++) {
		cout << count << "\t" << st->first << "\t" << st->second << endl;
		count++;
	}
}
/*void SymbolTable::DisplaySymbolTable();*/


/**/
/*
SymbolTable::LookupSymbol SymbolTable::LookupSymbol

NAME

	bool SymbolTable::LookupSymbol - lookup a symbol

SYNOPSIS

	bool SymbolTable::LookupSymbol(string &a_s, int &a_loc);

		a_s --> a string which will be compared to the content of the map
		a_loc --> a location which will be recorded if the symbol exists

RETURNS

	Returns a BOOL, true if the symbol already exists in the map, false if not

/**/
bool SymbolTable::LookupSymbol(string &a_s, int &a_loc) {

	// iterate through map and check for symbol
	for (map<string, int>::iterator st = m_symbolTable.begin(); st != m_symbolTable.end(); st++) {
		if (st->first.compare(a_s) == 0) {
			a_loc = st->second;
			return true;
		}
	}
	return false;
}
/*bool SymbolTable::LookupSymbol(string &a_s, int &a_loc);*/
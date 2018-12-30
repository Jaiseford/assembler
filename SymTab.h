/*Jaise Vincent
Software Design
Professor Miller
SymTab.h  */

//		Symbol table class.

#pragma once



// This class is our symbol table.
class SymbolTable {

public:
    // Get rid of constructor and destructor if you don't need them.
    SymbolTable( ) {};
    ~SymbolTable( ) {};
    
    const int multiplyDefinedSymbol = -999;

    // Add a new symbol to the symbol table.
    void AddSymbol( string &a_symbol, int a_loc );

    // Display the symbol table.
    void DisplaySymbolTable( );

    // Lookup a symbol in the symbol table.
    bool LookupSymbol( string &a_symbol, int &a_loc );

private:

    //  The symbol table. 
    map<string, int> m_symbolTable;
	int count;
};

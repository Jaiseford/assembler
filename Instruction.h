/*Jaise Vincent
Software Design
Professor Miller
Instruction.h  */


//Provides and parses information about classes

#pragma once
#include "Errors.h"
// The elements of an instruction.
class Instruction {

public:

    Instruction( ) { };
    ~Instruction( ) { };

    // Codes to indicate the type of instruction we are processing.  
    enum InstructionType {
        ST_MachineLanguage, // A machine language instruction.
        ST_AssemblerInstr,  // Assembler Language instruction.
        ST_Comment,          // Comment or blank line
        ST_End                    // end instruction.
    };
    // Parse the Instruction.
    InstructionType ParseInstruction( string &a_buff );

    // Compute the location of the next instruction.
    int LocationNextInstruction( int a_loc );

    // Used to access the label
    inline string &GetLabel( ) {

        return m_Label;
    };
    // Determines if a label is blank.
    inline bool isLabel( ) {

        return ! m_Label.empty();
    };

	string GetOperand() {
		return m_Operand;
	}

	string GetOpcode() {
		return m_OpCode;
	}
	// Translate the Assembly command into a number
	int Translate();

private:
	map<string, int> commands = {
		{"ADD",1},
		{"SUB",2},
		{"MULT",3},
		{"DIV",4},
		{"LOAD",5},
		{"STORE",6},
		{"READ",7},
		{"WRITE",8},
		{"B",9},
		{"BM",10},
		{"BZ",11},
		{"BP",12},
		{"HALT",13},
		{"ORG",00},
		{"DS",00},
		{"DC",00},
		{"END",00}
	};
    // The elemements of a instruction
    string m_Label;        // The label.
    string m_OpCode;       // The symbolic op code.
    string m_Operand;      // The operand.


    string m_instruction;    // The original instruction.

    // Derived values.
    int m_NumOpCode;     // The numerical value of the op code.
    InstructionType m_type; // The type of instruction.

    bool m_IsNumericOperand;// == true if the operand is numeric.
    int m_OperandValue;   // The value of the operand if it is numeric.
};



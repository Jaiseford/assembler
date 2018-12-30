/*Jaise Vincent
Software Design
Professor Miller
Emulator.h  */



//		Emulator class - supports the emulation of VC3600 programs

#ifndef _EMULATOR_H     
#define _EMULATOR_H

class emulator {

public:

    const static int MEMSZ = 10000;	// The size of the memory of the VC3600.  
    emulator() { 
		for (int i = 0; i < MEMSZ;i++) {
			m_memory[i] = 0;
		}
		acceumulator = 0;
    }
    // Records data and instructions in memory of VC3600.
    bool InsertMemory( int a_location, int a_contents );
    
    // Runs Program and saves it in memory
    bool RunProgram( );


	void Read(int a_location);
private:
	
	// The memory of the VC3600.
    int m_memory[MEMSZ];       

	// The accumulator for the VC3600
    int acceumulator;			
};

#endif


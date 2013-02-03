// Solution to problem 10033
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Instruction
{
    int opType, secondDigit, thirdDigit;
};

class P10033
{
    static Instruction ConstructInstruction(int i)
    {
        Instruction inst;
        inst.thirdDigit = i % 10; i /= 10;
        inst.secondDigit = i % 10; i /= 10;
        inst.opType = i % 10;

        return inst;
    }

    static int Execute(int registers[10], int ram[1000], int programCount)
    {        
        int numInstructionsRan = 0;

        while(true) {
            if(!ProcessInstruction(registers, ram, ConstructInstruction(ram[programCount]), programCount, numInstructionsRan))
                return numInstructionsRan;
        }
    }

    static bool ProcessInstruction(int registers[10], int ram[1000], Instruction inst, int& programCount, int& totalInstructionsRan)
    {
        totalInstructionsRan++;

        if(inst.opType == 1) {
            programCount++;
            return false;
        }
        else if(inst.opType == 2) {
            registers[inst.secondDigit] = inst.thirdDigit;
            programCount++;
        }
        else if(inst.opType == 3) {
            registers[inst.secondDigit] = (registers[inst.secondDigit] + inst.thirdDigit) % 1000;
            programCount++;
        }
        else if(inst.opType == 4) {
            registers[inst.secondDigit] = (registers[inst.secondDigit] * inst.thirdDigit) % 1000;
            programCount++;
        }
        else if(inst.opType == 5) {
            registers[inst.secondDigit] = registers[inst.thirdDigit]; 
            programCount++;           
        }
        else if(inst.opType == 6) {
            registers[inst.secondDigit] = (registers[inst.secondDigit] + registers[inst.thirdDigit]) % 1000;
            programCount++;
        }
        else if(inst.opType == 7) {            
            registers[inst.secondDigit] = (registers[inst.secondDigit] * registers[inst.thirdDigit]) % 1000;
            programCount++;
        }
        else if(inst.opType == 8) {
            registers[inst.secondDigit] = ram[registers[inst.thirdDigit]];
            programCount++;
        }
        else if(inst.opType == 9) {
            ram[registers[inst.thirdDigit]] = registers[inst.secondDigit];    
            programCount++;        
        }
        else if(inst.opType == 0) {
            if(registers[inst.thirdDigit] > 0) {
                programCount = registers[inst.secondDigit];
            }
            else
                programCount++;
        }

        return true;
    }

public:
    static void Solve()
    {	
        int numCases;
        string number, line;
        int instruction;
        bool endOfProgram = false;

        while(cin >> numCases) {
            int ram[1000];
            int registers[10];

            for(int i = 0; i < numCases; i++) {
                int numInstructionsRan = 0;
                memset(registers, 0, sizeof(int)*10);
                memset(ram, 0, sizeof(int)*1000);
            
                if(i == 0) {
                    getline(cin, line);
                    getline(cin, line);
                }

                int idx = 0;
                while(getline(cin, line)) {
                    if(line == "") {
                        endOfProgram = true;
                        break;
                    }

                    instruction = atoi(line.c_str());
                    ram[idx] = instruction;

                    idx++;
                }
                
                numInstructionsRan = Execute(registers, ram, 0);
                    
                cout << numInstructionsRan << endl;

                if(i < numCases - 1)
                    cout << endl;
            }
        }
    }
};

int main()
{
    P10033::Solve();
}
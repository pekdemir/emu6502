#include "cpu.h"

void CPU::reset() {
        regs.a = regs.x = regs.y = regs.sp = regs.flags = 0;
        regs.pc = 0xFFFC;
    }

uint8_t CPU::read(uint8_t addr) {
    // sleep
    return ram[addr];
}

void CPU::write(uint8_t addr, uint8_t data) {
    // sleep
    ram[addr] = data;
}

uint8_t CPU::read_indirect(uint8_t addr) {
    uint16_t indirect_addr = read(addr) | (read(addr + 1) << 8);
    return read(indirect_addr);
}

void CPU::decode()
{
    uint8_t opcode = read(regs.pc++);
    uint8_t highnibble = opcode >> 4;
    uint8_t lownibble = opcode & 0x0F;

    if (lownibble == 8){
    // SB1 Logic
    } else if (lownibble == 0xA && highnibble > 7){
    // SB2 Logic
    } else {
        uint8_t aaa = (opcode & 0xE0) >> 5;
        uint8_t bbb = (opcode & 0x1C) >> 2;
        uint8_t cc  = opcode & 0x03;

        switch(cc){
            case 1:
                // G1 address decoding and opcode logic
                break;
            case 2:
                // G2 address decoding and opcode logic
                break;
            case 3:
                if (bbb == 4){
                    // Conditional Branching logic
                } else if (bbb == 0 && !(aaa & 0x4)){
                    // I/S Logic
                } else {
                    // G3 address decoding and opcode logic
                }
            break;
        }
    }
}
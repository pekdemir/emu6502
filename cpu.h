#include <cstdint>
#include <array>

class CPU {
    struct Regs {
        uint8_t a, x, y, sp, flags;
        uint16_t pc;
    } regs;

    std::array<uint8_t, 0x10000> ram; // 64KB of RAM (0x0000 - 0xFFFF)

    void reset();

    uint8_t read(uint8_t addr);

    void write(uint8_t addr, uint8_t data);

    uint8_t read_indirect(uint8_t addr);

    void decode();

    // group 1
    void ORA(uint8_t addr);
    void AND(uint8_t addr);
    void EOR(uint8_t addr);
    void ADC(uint8_t addr);
    void STA(uint8_t addr);
    void LDA(uint8_t addr);
    void CMP(uint8_t addr);
    void SBC(uint8_t addr);

    // group 2
    void ASL(uint8_t addr);
    void ROL(uint8_t addr);
    void LSR(uint8_t addr);
    void ROR(uint8_t addr);
    void STX(uint8_t addr);
    void LDX(uint8_t addr);
    void DEC(uint8_t addr);
    void INC(uint8_t addr);

    // group 3
    void BIT(uint8_t addr);
    void JMP(uint8_t addr);
    void JMPI(uint8_t addr);
    void STY(uint8_t addr);
    void LDY(uint8_t addr);
    void CPY(uint8_t addr);
    void CPX(uint8_t addr);

};
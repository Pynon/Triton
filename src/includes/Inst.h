#ifndef _INST_H_
#define _INST_H_

#include <list>
#include <string>
#include <tuple>
#include <vector>

#include "IRBuilderOperand.h"
#include "SymbolicElement.h"

class Inst {

  private:
    uint64_t                          threadId;
    uint64_t                          address;
    std::string                       disassembly;
    std::list<SymbolicElement*>       symbolicElements;
    uint32_t                          opcode;
    std::vector< std::tuple<IRBuilderOperand::operand_t, uint64_t, uint32_t> > operands;

  public:
    const std::list<SymbolicElement*> &getSymbolicElements(void);
    const std::string                 &getDisassembly(void);
    const std::vector< std::tuple<IRBuilderOperand::operand_t, uint64_t, uint32_t> > &getOperands(void);
    size_t                            numberOfElements(void);
    uint32_t                          getOpcode(void);
    uint64_t                          getAddress(void);
    uint64_t                          getThreadId(void);
    void                              addElement(SymbolicElement *se);
    void                              setOpcode(uint32_t op);
    void                              setOperands(const std::vector< std::tuple<IRBuilderOperand::operand_t, uint64_t, uint32_t> > &operands);

    Inst(uint64_t threadId,uint64_t address, const std::string &insDis);
    ~Inst();
};

#endif /* ! _INST_H_ */

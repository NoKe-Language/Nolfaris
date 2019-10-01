
// Generated from src/antlr/noke.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "nokeListener.h"


/**
 * This class provides an empty implementation of nokeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  nokeBaseListener : public nokeListener {
public:

  virtual void enterFile(nokeParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(nokeParser::FileContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


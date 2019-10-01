
// Generated from src/antlr/noke.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "nokeParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by nokeParser.
 */
class  nokeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(nokeParser::FileContext *ctx) = 0;
  virtual void exitFile(nokeParser::FileContext *ctx) = 0;


};


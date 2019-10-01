
// Generated from src/antlr/noke.g4 by ANTLR 4.7.2


#include "nokeListener.h"

#include "nokeParser.h"


using namespace antlrcpp;
using namespace antlr4;

nokeParser::nokeParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

nokeParser::~nokeParser() {
  delete _interpreter;
}

std::string nokeParser::getGrammarFileName() const {
  return "noke.g4";
}

const std::vector<std::string>& nokeParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& nokeParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

nokeParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* nokeParser::FileContext::EOF() {
  return getToken(nokeParser::EOF, 0);
}


size_t nokeParser::FileContext::getRuleIndex() const {
  return nokeParser::RuleFile;
}

void nokeParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<nokeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void nokeParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<nokeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

nokeParser::FileContext* nokeParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, nokeParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(5);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(2);
        matchWildcard(); 
      }
      setState(7);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(8);
    match(nokeParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> nokeParser::_decisionToDFA;
atn::PredictionContextCache nokeParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN nokeParser::_atn;
std::vector<uint16_t> nokeParser::_serializedATN;

std::vector<std::string> nokeParser::_ruleNames = {
  "file"
};

std::vector<std::string> nokeParser::_literalNames = {
};

std::vector<std::string> nokeParser::_symbolicNames = {
};

dfa::Vocabulary nokeParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> nokeParser::_tokenNames;

nokeParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2, 0xd, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x7, 0x2, 0x6, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x9, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x7, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0xc, 0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x6, 0xb, 0x2, 0x2, 0x2, 0x5, 0x4, 0x3, 0x2, 0x2, 0x2, 0x6, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x7, 0x8, 0x3, 0x2, 0x2, 0x2, 0x7, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xa, 0x3, 0x2, 0x2, 0x2, 0x9, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xb, 0x7, 0x2, 0x2, 0x3, 0xb, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3, 0x7, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

nokeParser::Initializer nokeParser::_init;

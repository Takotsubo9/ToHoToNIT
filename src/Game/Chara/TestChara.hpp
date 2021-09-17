#ifndef _TESTCHARA_H_
#define _TESTCHARA_H_

#include "Character.hpp"

class TestChara : public Character
{
public:
  TestChara( void );
  virtual ~TestChara();
  void spellCard( void );
};

#endif /* _TESTCHARA_H_ */
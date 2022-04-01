#ifndef _SATSUKIHANA_H_
#define _SATSUKIHANA_H_

#include "Character.hpp"

class SatsukiHana : public Character
{
public:
  SatsukiHana( void );
  virtual ~SatsukiHana();
  void spellCard( void );
};

#endif /* _SATSUKIHANA_H_ */
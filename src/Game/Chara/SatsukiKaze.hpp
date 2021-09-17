#ifndef _SATSUKIKAZE_H_
#define _SATSUKIKAZE_H_

#include "Character.hpp"

class SatsukiKaze : public Character
{
public:
  SatsukiKaze( void );
  virtual ~SatsukiKaze();
  void spellCard( void );
};

#endif /* _SATSUKIKAZE_H_ */
#ifndef _MARISAKOI_H_
#define _MARISAKOI_H_

#include "Character.hpp"

class MarisaKoi : public Character
{
public:
  MarisaKoi( void );
  virtual ~MarisaKoi();
  void spellCard( void );
};

#endif /* _MARISAKOI_H_ */
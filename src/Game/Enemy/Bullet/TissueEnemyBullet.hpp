#ifndef _TISSUEENEMYBULLET_H_
#define _TISSUEENEMYBULLET_H_

#include"EnemyBullet.hpp"

class TissueEnemyBullet : public EnemyBullet
{
public:
    TissueEnemyBullet( void );
    TissueEnemyBullet( float x, float y, float angle );
    TissueEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~TissueEnemyBullet();
};

#endif /* _TISSUEENEMYBULLET_H_ */
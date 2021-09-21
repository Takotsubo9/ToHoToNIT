#ifndef _MEDIUMENEMYBULLET_H_
#define _MEDIUMENEMYBULLET_H_

#include"EnemyBullet.hpp"

class MediumEnemyBullet : public EnemyBullet
{
public:
    MediumEnemyBullet( void );
    MediumEnemyBullet( float x, float y, float angle );
    MediumEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~MediumEnemyBullet();
};

#endif /* _MEDIUMENEMYBULLET_H_ */
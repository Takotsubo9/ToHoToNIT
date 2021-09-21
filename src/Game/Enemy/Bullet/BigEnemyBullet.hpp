#ifndef _BIGENEMYBULLET_H_
#define _BIGENEMYBULLET_H_

#include"EnemyBullet.hpp"

class BigEnemyBullet : public EnemyBullet
{
public:
    BigEnemyBullet( void );
    BigEnemyBullet( float x, float y, float angle );
    BigEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~BigEnemyBullet();
};

#endif /* _BIGENEMYBULLET_H_ */
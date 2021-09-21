#ifndef _GRAINENEMYBULLET_H_
#define _GRAINENEMYBULLET_H_

#include"EnemyBullet.hpp"

class GrainEnemyBullet : EnemyBullet 
{
public:
    GrainEnemyBullet( void );
    GrainEnemyBullet( float x, float y, float angle );
    GrainEnemyBullet( int enemyBulletID, float x, float y, float angle );
    ~GrainEnemyBullet();
};

#endif /* _GRAINENEMYBULLET_H_ */
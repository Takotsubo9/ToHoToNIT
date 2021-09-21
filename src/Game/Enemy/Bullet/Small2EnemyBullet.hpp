#ifndef _SMALL2ENEMYBULLET_H_
#define _SMALL2ENEMYBULLET_H_

#include"EnemyBullet.hpp"

class Small2EnemyBullet : public EnemyBullet
{
public:
    Small2EnemyBullet( void );
    Small2EnemyBullet( float x, float y, float angle );
    Small2EnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~Small2EnemyBullet();
};

#endif /* _SMALL2ENEMYBULLET_H_ */
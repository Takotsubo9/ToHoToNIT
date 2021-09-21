#ifndef _SMALL1ENEMYBULLET_H_
#define _SMALL1ENEMYBULLET_H_

#include"EnemyBullet.hpp"

class Small1EnemyBullet : public EnemyBullet
{
public:
    Small1EnemyBullet( void );
    Small1EnemyBullet( float x, float y, float angle );
    Small1EnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~Small1EnemyBullet();
};

#endif /* _SMALL1ENEMYBULLET_H_ */
#ifndef _TESTENEMYBULLET_H_
#define _TESTENEMYBULLET_H_

#include"EnemyBullet.hpp"

class TestEnemyBullet : public EnemyBullet
{
public:
    TestEnemyBullet( void );
    TestEnemyBullet( float x, float y, float angle );
    TestEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~TestEnemyBullet();
};

#endif /* _TESTENEMYBULLET_H_ */
#ifndef _KNIFEENEMYBULLET_H_
#define _KNIFEENEMYBULLET_H_

#include"EnemyBullet.hpp"

class KnifeEnemyBullet : public EnemyBullet
{
public:
    KnifeEnemyBullet( void );
    KnifeEnemyBullet( float x, float y, float angle );
    KnifeEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~KnifeEnemyBullet();
};

#endif /* _KNIFEENEMYBULLET_H_ */
#ifndef _KUNAIENEMYBULLET_H_
#define _KUNAIENEMYBULLET_H_

#include"EnemyBullet.hpp"

class KunaiEnemyBullet : public EnemyBullet
{
public:
    KunaiEnemyBullet( void );
    KunaiEnemyBullet( float x, float y, float angle );
    KunaiEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~KunaiEnemyBullet();
};

#endif /* _KUNAIENEMYBULLET_H_ */
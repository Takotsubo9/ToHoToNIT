#ifndef _ELLIPSE1ENEMYBULLET_H_
#define _ELLIPSE1ENEMYBULLET_H_

#include"EnemyBullet.hpp"

class Ellipse1EnemyBullet : public EnemyBullet
{
public:
    Ellipse1EnemyBullet( void );
    Ellipse1EnemyBullet( float x, float y, float angle );
    Ellipse1EnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~Ellipse1EnemyBullet();
};

#endif /* _ELLIPSE1ENEMYBULLET_H_ */
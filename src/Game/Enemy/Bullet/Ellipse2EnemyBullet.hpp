#ifndef _ELLIPSE2ENEMYBULLET_H_
#define _ELLIPSE2ENEMYBULLET_H_

#include"EnemyBullet.hpp"

class Ellipse2EnemyBullet : public EnemyBullet
{
public:
    Ellipse2EnemyBullet( void );
    Ellipse2EnemyBullet( float x, float y, float angle );
    Ellipse2EnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~Ellipse2EnemyBullet();
};

#endif /* _ELLIPSE2ENEMYBULLET_H_ */
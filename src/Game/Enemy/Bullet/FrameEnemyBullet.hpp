#ifndef _FRAMEENEMYBULLET_H_
#define _FRAMEENEMYBULLET_H_

#include"EnemyBullet.hpp"

class FrameEnemyBullet : public EnemyBullet
{
public:
    FrameEnemyBullet( void );
    FrameEnemyBullet( float x, float y, float angle );
    FrameEnemyBullet( int enemyBulletID, float x, float y, float angle );
    virtual ~FrameEnemyBullet();
};

#endif /* _FRAMEENEMYBULLET_H_ */
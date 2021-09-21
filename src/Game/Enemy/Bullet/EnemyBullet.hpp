#ifndef _ENEMYBULLET_H_
#define _ENEMYBULLET_H_

#include"../../../Const/ImageID.hpp"

class EnemyBullet
{
private:
    int enemyBulletID;
    float x;
    float y;
    float angle;    //右方向から時計回りに回した時の角度(度数法)
    int bulletHitBoxRadius;    //弾の当たり判定半径
protected:
    void setBulletHitBoxRadius(int bulletHitBoxRadius) { this->bulletHitBoxRadius = bulletHitBoxRadius; }
public:
    EnemyBullet(void);
    EnemyBullet(float x, float y, float angle);
    EnemyBullet(int enemyBulletID, float x, float y, float angle);
    virtual ~EnemyBullet();

    void setEnemyBulletID(int enemyBulletID) { this->enemyBulletID = enemyBulletID; }
    int getEnemyBulletID(void) { return enemyBulletID; }
    void setX(float x) { this->x = x; }
    float getX(void) { return x; }
    void setY(float y) { this->y = y; }
    float getY(void) { return y; }
    void setAngle(float angle) { this->angle = angle; }
    float getAngle(void) { return angle; }
    int getBulletHitBoxRadius(void) { return bulletHitBoxRadius; }

    void updatePlace(float dx, float dy, float dAngle);
    void updatePlaceWithVector(float displacement, float dAngle);
};

#endif /* _ENEMYBULLET_H_ */
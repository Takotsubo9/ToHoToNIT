#ifndef _PLAYERBULLET_H_
#define _PLAYERBULLET_H_

#include "../../../Const/ImageID.hpp"

class PlayerBullet
{
private:
    int playerBulletID;
    float x;
    float y;
    float angle;    //右方向から時計回りに回した時の角度(度数法)
    int bulletHitBoxRadius;    //弾の当たり判定半径
    int attackPower;
protected:
    void setBulletHitBoxRadius(int bulletHitBoxRadius) { this->bulletHitBoxRadius = bulletHitBoxRadius; }
    void setAttackPower( int attackPower ){ this->attackPower = attackPower; }
public:
    PlayerBullet(void);
    PlayerBullet(float x, float y, float angle);
    PlayerBullet(int enemyBulletID, float x, float y, float angle);
    virtual ~PlayerBullet();

    void setPlayerBulletID(int playerBulletID) { this->playerBulletID = playerBulletID; }
    int getPlayerBulletID(void) { return playerBulletID; }
    void setX(float x) { this->x = x; }
    float getX(void) { return x; }
    void setY(float y) { this->y = y; }
    float getY(void) { return y; }
    void setAngle(float angle) { this->angle = angle; }
    float getAngle(void) { return angle; }
    int getBulletHitBoxRadius(void) { return bulletHitBoxRadius; }
    int getAttackPower( void ){ return attackPower; }

    void updatePlace(float dx, float dy, float dAngle);
    void updatePlaceWithVector(float displacement, float dAngle);
};

#endif /* _PLAYERBULLET_H_ */
#include <cmath>
#include"EnemyBullet.hpp"
const double PI = 3.141593;

EnemyBullet::EnemyBullet(void)
{

}

EnemyBullet::EnemyBullet(float x, float y, float angle)
{
    setX(x);
    setY(y);
    setAngle(angle);
}

EnemyBullet::EnemyBullet(int enemyBulletID, float x, float y, float angle)
{
    setEnemyBulletID(enemyBulletID);
    setX(x);
    setY(y);
    setAngle(angle);
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::updatePlace(float dx, float dy, float dAngle)
{
    setX(getX() + dx);
    setY(getY() + dy);
    setAngle(getAngle() + dAngle);
}

void EnemyBullet::updatePlaceWithVector(float displacement, float dAngle)
{
    setAngle(getAngle() + dAngle);
    setX(getX() - displacement * std::sin((360 - getAngle()) * PI / 180.0));
    setY(getY() - displacement * std::cos((360 - getAngle()) * PI / 180.0));
}
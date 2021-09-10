#include <cmath>
#include"PlayerBullet.hpp"
const double PI = 3.141593;

PlayerBullet::PlayerBullet(void)
{

}

PlayerBullet::PlayerBullet(float x, float y, float angle)
{
    setX(x);
    setY(y);
    setAngle(angle);
}

PlayerBullet::PlayerBullet(int elayerBulletID, float x, float y, float angle)
{
    setPlayerBulletID(elayerBulletID);
    setX(x);
    setY(y);
    setAngle(angle);
}

PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::updatePlace(float dx, float dy, float dAngle)
{
    setX(getX() + dx);
    setY(getY() + dy);
    setAngle(getAngle() + dAngle);
}

void PlayerBullet::updatePlaceWithVector(float displacement, float dAngle)
{
    setAngle(getAngle() + dAngle);
    setX(getX() - displacement * std::sin((360 - getAngle()) * PI / 180.0));
    setY(getY() - displacement * std::cos((360 - getAngle()) * PI / 180.0));
}
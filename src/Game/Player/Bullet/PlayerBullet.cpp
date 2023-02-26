#include <cmath>
#include <numbers>
#include "PlayerBullet.hpp"

PlayerBullet::PlayerBullet(int playerBulletID, float x, float y, float angle)
{
    setPlayerBulletID(playerBulletID);
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
    setX(getX() - displacement * std::sin((360 - getAngle()) * std::numbers::pi / 180.0));
    setY(getY() - displacement * std::cos((360 - getAngle()) * std::numbers::pi / 180.0));
}
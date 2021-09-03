#include"EnemyBullet.hpp"

EnemyBullet::EnemyBullet( void )
{

}

EnemyBullet::EnemyBullet( float x, float y, float angle )
{
    setX( x );
    setY( y );
    setAngle( angle );
}

EnemyBullet::EnemyBullet( int enemyBulletID, float x, float y, float angle )
{
    setEnemyBulletID( enemyBulletID );
    setX( x );
    setY( y );
    setAngle( angle );
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::updatePlace( float dx, float dy, float dAngle )
{
    setX( getX() + dx );
    setY( getY() + dy );
    setAngle( getAngle() + dAngle );
}
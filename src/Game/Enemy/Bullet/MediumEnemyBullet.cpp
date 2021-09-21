#include"MediumEnemyBullet.hpp"

MediumEnemyBullet::MediumEnemyBullet( void )
{

}

MediumEnemyBullet::MediumEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

MediumEnemyBullet::MediumEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

MediumEnemyBullet::~MediumEnemyBullet()
{

}
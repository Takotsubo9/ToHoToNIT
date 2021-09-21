#include"FrameEnemyBullet.hpp"

FrameEnemyBullet::FrameEnemyBullet( void )
{

}

FrameEnemyBullet::FrameEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

FrameEnemyBullet::FrameEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

FrameEnemyBullet::~FrameEnemyBullet()
{

}
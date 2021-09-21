#include"Small1EnemyBullet.hpp"

Small1EnemyBullet::Small1EnemyBullet( void )
{

}

Small1EnemyBullet::Small1EnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Small1EnemyBullet::Small1EnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Small1EnemyBullet::~Small1EnemyBullet()
{

}
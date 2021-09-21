#include"BigEnemyBullet.hpp"

BigEnemyBullet::BigEnemyBullet( void )
{

}

BigEnemyBullet::BigEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

BigEnemyBullet::BigEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

BigEnemyBullet::~BigEnemyBullet()
{

}
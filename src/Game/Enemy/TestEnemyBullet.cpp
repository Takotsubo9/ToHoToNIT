#include"TestEnemyBullet.hpp"

TestEnemyBullet::TestEnemyBullet( void )
{

}

TestEnemyBullet::TestEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

TestEnemyBullet::TestEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

TestEnemyBullet::~TestEnemyBullet()
{

}
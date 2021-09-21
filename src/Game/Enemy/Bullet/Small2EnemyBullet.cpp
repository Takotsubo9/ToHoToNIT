#include"Small2EnemyBullet.hpp"

Small2EnemyBullet::Small2EnemyBullet( void )
{

}

Small2EnemyBullet::Small2EnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Small2EnemyBullet::Small2EnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Small2EnemyBullet::~Small2EnemyBullet()
{

}
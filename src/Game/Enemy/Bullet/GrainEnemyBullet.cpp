#include"GrainEnemyBullet.hpp"

GrainEnemyBullet::GrainEnemyBullet( void )
{
    setBulletHitBoxRadius( 5 );
}

GrainEnemyBullet::GrainEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

GrainEnemyBullet::GrainEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

GrainEnemyBullet::~GrainEnemyBullet()
{

}
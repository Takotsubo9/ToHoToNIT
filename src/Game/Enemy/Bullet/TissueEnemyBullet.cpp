#include"TissueEnemyBullet.hpp"

TissueEnemyBullet::TissueEnemyBullet( void )
{

}

TissueEnemyBullet::TissueEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

TissueEnemyBullet::TissueEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

TissueEnemyBullet::~TissueEnemyBullet()
{

}
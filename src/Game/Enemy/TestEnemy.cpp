#include"TestEnemy.hpp"
#include"Barrage/TestBarrage.hpp"

TestEnemy::TestEnemy( void )
{
    
}

TestEnemy::TestEnemy( int enemyID ) : Enemy( enemyID )
{
    
}

TestEnemy::TestEnemy( int enemyID, float x, float y ) : Enemy( enemyID, x, y )
{
    
}

TestEnemy::~TestEnemy()
{

}
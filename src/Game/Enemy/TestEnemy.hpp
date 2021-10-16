#ifndef _TESTENEMY_H_
#define _TESTENEMY_H_

#include"Enemy.hpp"

class TestEnemy : public Enemy
{
public:
    TestEnemy( void );
    TestEnemy( int enemyID );
    TestEnemy( int enemyID, float x, float y );    //使うんだったら使って
    virtual ~TestEnemy();
};

#endif /* _TESTENEMY_H_ */
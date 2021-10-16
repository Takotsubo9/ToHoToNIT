#ifndef _TESTBARRAGE_H_
#define _TESTBARRAGE_H_

#include"EnemyBarrage.hpp"

class TestBarrage : public EnemyBarrage
{
public:
    TestBarrage( void );
    ~TestBarrage();
    
    void apperBullet( int quantity );
    void straightToPlayerBullet( void );
};

#endif /* _TESTBARRAGE_H_ */
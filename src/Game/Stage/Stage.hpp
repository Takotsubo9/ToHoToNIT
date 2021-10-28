#ifndef _STAGE_H_
#define _STAGE_H_

#include "../Player/dPlayer.hpp"
#include "../../GameWindow.hpp"

class Stage {
protected:
    dPlayer dplayer;
public:
    Stage(Player * player) {
        dplayer.setPlayer(player);
    }
    virtual ~Stage() {
        
    }
    virtual void Draw(GameWindow * game_window) = 0;
};

#endif /* _STAGE_H_ */
#ifndef _STAGE_H_
#define _STAGE_H_

#include "../Player/dPlayer.hpp"
#include "../Item/Item.hpp"
#include "../../GameWindow.hpp"
#include <vector>

class Stage {
protected:
    dPlayer dplayer;
    std::vector<Item> item_list;
public:
    Stage(Player * player);
    virtual ~Stage() {
        
    }
    //Update->Judge->Drawの順で呼ぶ
    //場所のアップデート
    virtual void Update(GameWindow * game_window) = 0;
    //当たり判定
    void Judge(GameWindow* game_window);
    //描画
    virtual void Draw(GameWindow * game_window) = 0;
};

#endif /* _STAGE_H_ */
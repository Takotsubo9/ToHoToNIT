#ifndef _ITEM_H_
#define _ITEM_H_

#include "../../Const/ItemID.hpp"
#include "../Player/dPlayer.hpp"

class GameWindow;

class Item {
private:
    ItemID item_id;
    float x;
    float y;
    float target_x;
    float target_y;
    float inclease;
    bool to_target;
    float speed;
public:
    Item(ItemID item_id, float x, float y, float target_x, float target_y, float inclease, float speed);
    virtual ~Item();
    int getX() { return x; }
    int getY() { return y; }
    void Update();
    void Draw(GameWindow* game_window);
    void Effect(dPlayer* dplayer);
};

#endif /* ITEM_H_ */
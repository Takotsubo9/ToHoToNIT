#include "TouchManager.hpp"

void TouchManager::Polling(SDL_Event e) {
    switch(e.type) {
        case SDL_FINGERDOWN: {
            //タッチ開始
            //指のIDを増やし、最初の場所を記録
            this->fingerid_list.push_back(e.tfinger.fingerId);
            Point p(e.tfinger.x, e.tfinger.y);
            this->touched.push_back(p);
            this->touching[e.tfinger.fingerId] = p;
            this->first[e.tfinger.fingerId] = p;
            break;
        }
        case SDL_FINGERMOTION: {
            //動かされた際
            //タッチ場所の更新
            Point p(e.tfinger.x, e.tfinger.y);
            this->touching[e.tfinger.fingerId] = p;
            break;
        }
        case SDL_FINGERUP: {
            //タッチ終了
            //指のIDを消す
            this->touching.erase(e.tfinger.fingerId);
            for(std::vector<SDL_FingerID>::iterator it = this->fingerid_list.begin(); it != this->fingerid_list.end(); it++) {
                if(*it == e.tfinger.fingerId) {
                    this->fingerid_list.erase(it);
                    break;
                }
            }
            break;
        }
    }
}

void TouchManager::ClearKeyEvent() {
    this->touched.clear();
}
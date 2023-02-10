# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## 依存ライブラリ
* SDL 2.26.3
* SDL_image 2.6.3
* SDL_mixer 2.6.3

## HowToBuild
### 環境構築
* Windows環境  
    + MinGW  
    + Git for Windows

    をインストールしてください。
    
    SDL関係については、

    * [SDL](https://github.com/libsdl-org/SDL)
    * [SDL_image](https://github.com/libsdl-org/SDL_image)
    * [SDL_mixer](https://github.com/libsdl-org/SDL_mixer)

    からインストールしてください。
* macOS環境  
    Homebrewなどを用い
    + g++
    + git
    + sdl2
    + sdl2_image
    + sdl2_mixer

    をインストールしてください。

* Linux環境  
    + g++
    + git

    をインストールしてください。

    SDL関係については、各ディストリビューションのインストール方法に従ってください。


### ビルド
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git
cd ToHoToNIT
mkdir build && cd build
cmake -DSDL2_INCLUDE_DIR=<SDL2のヘッダのディレクトリ> -DSDL2_LIBRARY_DIR=<SDL2のライブラリのディレクトリ> ..
cmake --build .
```
上記を実行した場合、build/binフォルダに実行ファイルが作成されているはずです。
<>内は適切なパスに置き換えてください。

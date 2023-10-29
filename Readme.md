# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## HowToBuild
### 環境構築
+ C++20に対応したコンパイラ群
+ Git
+ CMake
+ SDL2 2.28.4
+ SDL2_image 2.6.3
+ SDL2_mixer 2.6.3

をインストールしてください。

### ビルド
#### デスクトップ
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git
cd ToHoToNIT
cmake -B build -DSDL2_INCLUDE_DIR=<SDL2のヘッダのディレクトリ> -DSDL2_LIBRARY_DIR=<SDL2のライブラリのディレクトリ> .
cmake --build build
```
上記を実行した場合、build/binフォルダに実行ファイルが作成されているはずです。
<>内は適切なパスに置き換えてください。

#### Android
工事中
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git --depth 1
git clone https://github.com/libsdl-org/SDL.git -b release-2.28.4 --depth 1
git clone https://github.com/libsdl-org/SDL_image.git -b release-2.6.3 --recursive --depth 1
git clone https://github.com/libsdl-org/SDL_mixer.git -b release-2.6.3 --recursive --depth 1
mv SDL/android-project .
mv SDL android-project/app/jni
mv SDL_image android-project/app/jni
mv SDL_mixer android-project/app/jni
mv ToHoToNIT/assets android-project/app/src/main
rm -rf android-project/app/jni/src
mkdir android-project/app/src/main/assets
cp -r ToHoToNIT/bin/* android-project/app/src/main/assets
mv ToHoToNIT android-project/app/jni/src

# 以下、CMakeLists.txt
# add_subdirectoryの所のコメントアウトを解除
# armeabi-v7aに関する所のコメントアウト削除

# 以下、build.gradle
# minSdkVersion 24 に
# ndkBuildの所をコメントアウト
# cmakeの所をコメントアウト解除
# android.externalNativeBuild.cmake.version "3.22.1"の追記
# cmakeのargumentsのとこを "-DANDROID_APP_PLATFORM=android-24", "-DANDROID_STL=c++_static", "-DOP_DISABLE_EXAMPLES=ON", "-DSDL2MIXER_VENDORED=ON", "-DSDL2IMAGE_VENDORED=ON", "-DSDL2MIXER_INSTALL=OFF", "-DSDL2IMAGE_INSTALL=OFF", "-DSDL2IMAGE_SAMPLES=OFF", "-DSDL2MIXER_SAMPLES=OFF", "-DWITH_ASM=OFF"
# abiFiltersはすべて有効にする

cd android-project
./gradlew build
```

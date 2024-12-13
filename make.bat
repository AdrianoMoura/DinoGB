mkdir build\objects

:: Compiling each file into a .o
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/main.o ./src/src/main.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/dino.o ./src/src/dino.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/obstacle.o ./src/src/obstacle.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/cactus.o ./src/src/cactus.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/bird.o ./src/src/bird.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/sound.o ./src/src/sound.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/parallax.o ./src/src/parallax.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/game.o ./src/src/game.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/BackgroundTileMapDay.o ./src/assets/BackgroundTileMapDay.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/BackgroundTileMapNight.o ./src/assets/BackgroundTileMapNight.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/BackgroundTileSet.o ./src/assets/BackgroundTileSet.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/DinoTileSet.o ./src/assets/DinoTileSet.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/CactusTileSet.o ./src/assets/CactusTileSet.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/BirdTileSet.o ./src/assets/BirdTileSet.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -c -o ./build/objects/CharacterTileSet.o ./src/assets/CharacterTileSet.c

:: Linker of the .o files into .gb
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFT_FOR_REG -o ./build/dino.gb ./build/objects/main.o ./build/objects/dino.o ./build/objects/obstacle.o ./build/objects/cactus.o ./build/objects/bird.o ./build/objects/sound.o ./build/objects/parallax.o ./build/objects/game.o ./build/objects/BackgroundTileMapNight.o ./build/objects/BackgroundTileMapDay.o ./build/objects/BackgroundTileSet.o ./build/objects/DinoTileSet.o ./build/objects/CactusTileSet.o ./build/objects/BirdTileSet.o ./build/objects/CharacterTileSet.o

copy .\build\dino.gb .\ /Y
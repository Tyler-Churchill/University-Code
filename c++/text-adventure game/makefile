BBTARGET   = game
CC       = g++
CFLAGS   = -Wall -g -std=c++11
LINKER   = g++ -o
LFLAGS   = -Wall -I -l

SRCDIR = src
BINDIR = bin
OBJDIR = obj

rm = rm -f

GAMESOURCE :=  src/MainGame.cc src/Game.cc  src/Map.cc src/RoomStandard.cc src/RoomBoss.cc src/RoomJail.cc src/RoomHall.cc src/RoomArmory.cc src/EntityFactory.cc  src/EntityBat.cc src/EntityPlayer.cc src/EntitySpider.cc src/EntityTroll.cc src/EntitySkeleton.cc src/ItemFactory.cc src/Weapon.cc src/Potion.cc src/Armor.cc
GAMEINCLUDE := src/Game.h src/Room.h src/Map.h src/RoomStandard.h src/RoomBoss.h src/RoomJail.h src/RoomHall.h src/RoomArmory.h src/EntityFactory.h src/Entity.h src/Attributes.h src/EntityBat.h src/EntityPlayer.h src/EntitySpider.h src/EntityTroll.h src/EntitySkeleton.h src/ItemFactory.h src/Weapon.h src/Potion.h src/Armor.cc
GAMEOBJECTS := obj/MainGame.o obj/Game.o obj/Map.o obj/RoomStandard.o obj/RoomBoss.o obj/RoomJail.o obj/RoomHall.o obj/RoomArmory.o obj/EntityFactory.o  obj/EntityBat.o obj/EntityPlayer.o obj/EntitySpider.o obj/EntityTroll.o obj/EntitySkeleton.o obj/ItemFactory.o obj/Potion.o obj/Weapon.o obj/Armor.o 

TESTSOURCE := src/Test.cc src/MapTest.cc $(GAMESOURCE)
TESTINCLUDE := src/MapTest.h src/Map.h 
TESTOBJECTS := obj/Test.o obj/MapTest.o $(GAMEOBJECTS)

all: bin/game bin/test

game: clean bin/game

test: bin/test

bin/game: $(GAMEOBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(GAMEOBJECTS)
	@echo "game.exe created in bin/"

$(GAMEOBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	@$(CC) $(CFLAGS) -c $< -o $@	

bin/test: $(TESTOBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(TESTOBJECTS)
	@echo "test.exe created in bin/"

$(TESTOBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@$(rm) $(GAMEOBJECTS)
	@$(rm) bin/test
	@$(rm) bin/game

a:
	@$(rm) $(TESTOBJECTS)
	@$(rm) bin/test

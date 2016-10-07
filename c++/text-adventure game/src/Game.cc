#include <iostream>
#include <string>
#include "Game.h"
#include "EntityFactory.h"
#include "sys/time.h"
#include <cstdlib>


Game::~Game()
{
   //delete this;
}

void Game::start()
{
   clear();
   setDebug(true);
   
   // display title screen
   std::cout << std::endl << "\t\t DUNGEON GAME" << std::endl << std::endl;
   std::cout << "\t\t1. Start Game" << std::endl;
   std::cout << "\t\t2. Quit Game" << std::endl;
   std::cout << std::endl << std::endl;
   srand(time(NULL));
   int o;
   std::cout << "Enter Option: ";
   std::cin >> o;
   // ask for users input
   if(o == 1)
   {
      isRunning = true;
      mainLoop();
   } else {
      exit();
   }
}
void Game::mainLoop()
{      
   clear();
   std::string name;
   int diff = 0;
   clear();
   std::cout << "\t\t Choose difficulty\n\n";
   std::cout << "\t\t1. Easy" << std::endl;
   std::cout << "\t\t2. Medium" << std::endl;
   std::cout << "\t\t3. Hard" << std::endl;
   std::cout << "\n\nEnter Option: ";
   std::cin >> diff;
   clear();
   std::cout << "\t\t Name your character\n\n\n\n\n";
   createCharacter();
   // add try statement catch any errors
   map = new Map(diff, player);
   if(map->generate()) 
   {
      while(isRunning)
      {
	 clear();
	 map->displayDescription();
	 roomOption();
	 
      }
	 
   }
  
   
   
   exit();
}
void Game::roomOption()
{
   std::cout << "\n\n\n";
   std::cout<<"Current X: "<<map->getX()<<"  Current Y: "<<map->getY()<<std::endl;
   int op=getOption();
   bool north = map->getOpVec().at(0);
   bool south = map->getOpVec().at(1);
   bool east = map->getOpVec().at(2);
   bool west = map->getOpVec().at(3);
   bool attack = map->getOpVec().at(4);
   int dirSum=(map->getOpVec().at(0)+map->getOpVec().at(1)+map->getOpVec().at(2)+map->getOpVec().at(3));
   //all
   if(op-1>map->getOpVec().at(7))
   {
     op=getOption();
   }
   switch(op)
   {
      case 1:
      {
	 //set north
	 if (north)
	 {
	    map->movePlayer(map->getCurRoom()->getNorth());
	    std::cout<<"north1";
	    break;
	 }
	 //no north set south
	 if (!north && south)
	 {
	    map->movePlayer(map->getCurRoom()->getSouth());
	    std::cout<<"south1";
	    break;
	 }
	 //no north no sout set east
	 if (!north && !south && east)
	 {
	    map->movePlayer(map->getCurRoom()->getEast());
	    std::cout<<"east1";
	    break;
	 }
	 //no north no south no east set west
	 if (!north && !south && !east && west )
	 {
	    map->movePlayer(map->getCurRoom()->getWest());
	    std::cout<<"west1";
	    break;
	 }
	 break;
      }
      case 2:
      {
	 //north and south set south
	 if (north && south)
	 {
	    map->movePlayer(map->getCurRoom()->getSouth());
	    std::cout<<"south2";
	    break;
	 }
	 //only north or south and east set east 
	 if ((north ^ south) && east )
	 {
	    map->movePlayer(map->getCurRoom()->getEast());
	    std::cout<<"east2";
	    break;
	 }
	 //one dirrection and west set west
	 if ((north ^ south ^ east)&& west)
	 {
	    map->movePlayer(map->getCurRoom()->getWest());
	    std::cout<<"west2";
	    break;
	 }
	 //only on dir set attack
	 if ((north ^ south ^ east ^ west) && attack)
	 {
	    combat(map->getCurRoom());
	    break;
	 }
	 //only one direction or attack
	 if ((north ^ south ^ east ^ west) && !attack)
	 {
	    inventory();
	    break;
	 }
	 break;
      }
      case 3:
      {
	 if (north && south && east)
	 {
	    map->movePlayer(map->getCurRoom()->getEast());
	    std::cout<<"east3";
	    break;
	 }
	 //2 dir and west set west
	 if (west &&(((north^south)&&east)^(north&&south)))
	 {
	    map->movePlayer(map->getCurRoom()->getWest());
	    std::cout<<"west3";
	    break;
	 }
	 //2 dir with attack set attack
	 if ((dirSum==2) && attack)
	 {
	    combat(map->getCurRoom());
	    break;
	 }
	 //2 dir no attack set IN
	 if ((dirSum==2)&& !attack)
	 {
	    inventory();
	    break;
	 }
		  
	 //1 dir 1 attack set in 
	 if ((dirSum==1) && attack)
	 {
	    inventory();
	    break;
	 }
	 //1 dir no attack
	 if ((dirSum==1)&& !attack)
	 {
	    std::cout<<"quit3";
	    exit();
	    break;
	 }
	 break;
      }
      case 4:
      {
	 //4 dir set west
	 if (north && south && east && west)
	 {
	    map->movePlayer(map->getCurRoom()->getWest());
	    std::cout<<"west4";
	    break;
	 }
	 //3 dir 1 attack set attack
	 if ((dirSum==3) && attack)
	 {
	    combat(map->getCurRoom());
	    break;
	 }
	 //3 doors no atack set INV
	 if ((dirSum==3) && !attack)
	 {
	    inventory();
	    break;
	 }
	 //two dir and 1 attack set INV 
	 if ( (dirSum==2)&& attack )
	 {
	    inventory();
	    break;
	 }
	 //1 dir 1 attack 1 in setquit
	 if ((dirSum==1)&&attack)
	 {
	    std::cout<<"exit 4";
	    exit();
	    break;
	 }
	 break;
      }
      case 5:
      {
	 //4 dir and attack
	 if ((dirSum==4) && attack)
	 {
	    combat(map->getCurRoom());
	    break;
	 }
	 //4 dir no attack set INV
	 if ((dirSum==4) && !attack)
	 {
	    inventory();
	    break;
	 }
	 //3 doors and attack set inventory
	 if((dirSum==3) && attack)
	 {
	    inventory();
	    break;
	 }
	 //3 doors no attack set quit 
	 if((dirSum==3) && !attack)
	 {
	    std::cout<<"quit 5 no attack";
	    exit();
	    break;
	 }
	 //2 doors and attack  set quit
	 if((dirSum==2)&& attack)
	 {
	    std::cout<<"quit 5 ATTACK";
	    exit();        	     
	    break;
	 }
	 break;
      }
      case 6:
      {
	 //4 doors && attack set in
	 if((dirSum==4) && attack)
	 {
	    inventory();
	    break;
	 }
	 if((dirSum==4) && !attack)
	 {
	    std::cout<<"exit6 No attack";
	    exit();
	    break;
	 }
	 //3 doorrs and attack
	 if((dirSum==3)&&attack)
	 {
	    std::cout<<"quit  6 Attack";
	    exit();
	    break;
	 }
	 break;
      }
      case 7:
      {
	 if((dirSum==4) && attack)
	 {
	    std::cout<<"quit 7 ATTACK";
	    exit();
	    break;
	 }
      }
   }
}

void Game::inventory() {

   clear();

   std::cout << player->getName() << " stats\n\n\n";
   std::cout << "Health: " << player->getAttributes().getHealthPoints() << std::endl;
   std::cout << "Damage: " << player->getAttributes().getDamage() << std::endl;
   std::cout << "Vitality: " << player->getAttributes().getVitality() << std::endl;
   std::cout << "Strength: " << player->getAttributes().getStrength() << std::endl;
   std::cout << "Agility: " << player->getAttributes().getAgility() << std::endl;
   std::cout << "Armor: " << player->getAttributes().getArmor() << std::endl;
   

   std::cout << "\n\n\n\n\n" << player->getName() << "'s Inventory\n\n\n\n\n";
   int option = 0;
   for(auto *i : player->getInventory())
   {
      std::cout << option << ". \t" << i->getName() << " - " << i->getDescription() << std::endl;
    
      std::cout << "\t\tDamage: " << player->getInventory().at(option)->getStats().getDamage() << std::endl;
      std::cout << "\t\tVitality: " << player->getInventory().at(option)->getStats().getVitality() << std::endl;
      std::cout << "\t\tStrength: " << player->getInventory().at(option)->getStats().getStrength() << std::endl;
      std::cout << "\t\tAgility: " << player->getInventory().at(option)->getStats().getAgility() << std::endl;
      std::cout << "\t\tArmor: " << player->getInventory().at(option)->getStats().getArmor() << std::endl;
      
      option++;
   }

   int choice = 0;
   std::cout << "\n\n\n\n\nSelect item or " << option << " to quit: ";
   std::cin >> choice;

   if (choice==option)
      return;
   if(player->getInventory()[choice] != nullptr)
   {
      if(player->getInventory()[choice]->isArmor())
      {
	 std::cout << "tried to equip armor" << std::endl;
	 player->equipArmor(player->getInventory()[choice]);
      }

      if(player->getInventory()[choice]->isWeapon())
      {
	 std::cout << "tried to equip weap" << std::endl;
	 player->equipWeapon(player->getInventory()[choice]);
      }
      if(player->getInventory()[choice]->isPotion())
      {
	 std::cout << "tried to equip pot" << std::endl;
	 player->usePotion(player->getInventory()[choice], choice);
	 //delete player->getInventory()[choice];
      }
   } 
}

void Game::combat(Room *room)   
{
   
   int enemyHealth = room->getEntity()->getAttributes().getHealthPoints();
   int playerHealth = player->getAttributes().getHealthPoints();
   int fullHealth = enemyHealth;
   int fullPlayerHealth = (player->getAttributes().getVitality())*10;
   bool dead = false;
   while(!dead)
   {
      clear();
      enemyHealth = room->getEntity()->getAttributes().getHealthPoints();
      playerHealth = player->getAttributes().getHealthPoints();
      std::cout<< "\t\t\t\t\t\t\t\t\t\t" << room->getEntity()->getName()<<std::endl;
      std::cout<<"\t\t\t\t\t\t\t\t   Health: ";
      if(enemyHealth==fullHealth)
	 std::cout<<"||||||||||"<<std::endl;
      if((enemyHealth<fullHealth) && (enemyHealth>=(.9*fullHealth)))
	 std::cout<<"|||||||||"<<std::endl;
      if((enemyHealth<(fullHealth*.9)) && (enemyHealth>=(.8*fullHealth)))
	 std::cout<<"||||||||"<<std::endl;
      if((enemyHealth<(fullHealth*.8)) && (enemyHealth>=(.7*fullHealth)))
	 std::cout<<"|||||||"<<std::endl;
      if((enemyHealth<(fullHealth*.7)) && (enemyHealth>=(.6*fullHealth)))
	 std::cout<<"||||||"<<std::endl;
      if((enemyHealth<(fullHealth*.6)) && (enemyHealth>=(.5*fullHealth)))
	 std::cout<<"|||||"<<std::endl;
      if((enemyHealth<(fullHealth*.5)) && (enemyHealth>=(.4*fullHealth)))
	 std::cout<<"||||"<<std::endl;
      if((enemyHealth<(fullHealth*.4)) && (enemyHealth>=(.3*fullHealth)))
	 std::cout<<"|||"<<std::endl;
      if((enemyHealth<(fullHealth*.3)) && (enemyHealth>=(.2*fullHealth)))
	 std::cout<<"||"<<std::endl;
      if((enemyHealth<(fullHealth*.2)) && (enemyHealth>(0)))
	 std::cout<<"|"<<std::endl;
      std::cout<<"\n \n \n \n \n";

      
      if(enemyHealth<=0)
      {
	 dead=true;
	 std::cout<<"Enemy Defeated!!!!" <<std::endl;
      }
      if(playerHealth<=0)
      {
	 dead=true;
	 std::cout<<"Enemy Defeated you!!!!" <<std::endl;
	 exit();
      }
      //WHAT HAPPENED
 
      //YOUR STATS
      
      std::cout<<player->getName()<<std::endl<<"Health: ";
      if(playerHealth==fullPlayerHealth)
	 std::cout<<"||||||||||"<<std::endl;
      if((playerHealth<fullPlayerHealth) && (playerHealth>=(.9*fullPlayerHealth)))
	 std::cout<<"|||||||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.9)) && (playerHealth>=(.8*fullPlayerHealth)))
	 std::cout<<"||||||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.8)) && (playerHealth>=(.7*fullPlayerHealth)))
	 std::cout<<"|||||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.7)) && (playerHealth>=(.6*fullPlayerHealth)))
	 std::cout<<"||||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.6)) && (playerHealth>=(.5*fullPlayerHealth)))
	 std::cout<<"|||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.5)) && (playerHealth>=(.4*fullPlayerHealth)))
	 std::cout<<"||||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.4)) && (playerHealth>=(.3*fullPlayerHealth)))
	 std::cout<<"|||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.3)) && (playerHealth>=(.2*fullPlayerHealth)))
	 std::cout<<"||"<<std::endl;
      if((playerHealth<(fullPlayerHealth*.2)) && (playerHealth>(0)))
	 std::cout<<"|"<<std::endl;
      
      std::cout<<"\n \n \n \n \n";
      
      int attack;
      size_t potionLOC;
      if(!dead)
      {
	 std::cout<<"1. Attack"<<std::endl;
	 for (size_t i = 0; i!=room->getEntity()->getInventory().size();i++)
	 {
	    if ((room->getEntity()->getInventory().at(i)->isPotion()))
	    {
	       potionLOC = i;
	       std::cout<<"2. Use Potion"<<std::endl;
	       break;
	    }
		
	 }
	 std::cout << "\n\n\nEnter option: ";
	 std::cin >> attack;

	 if ((attack==2)&&(room->getEntity()->getInventory().at(potionLOC)->isPotion()))
	 {
	    if (attack==2)
	       player->usePotion(player->getInventory()[potionLOC], potionLOC);
	 }
	 if(attack==1 && ((room->getEntity()->isAlive())&&player->isAlive()))
	 {
	    std::cout<<"me"<<std::endl;
	    player->attack(*(room->getEntity()));
	    std::cout<<"enemy"<<std::endl;
	    if(enemyHealth!=0)
	    {
	       room->getEntity()->attack(*player);
	       if(playerHealth<=0)
		  exit();
	    }
	 }
	 attack=0;
      }
   }
}
void Game::createCharacter()
{
   int strength;
   int vitality;
   int agility;
   int total=0;
   std::string name="";
   std::cout << "What is your name? ";
   std::cin >> name;
   while(total<30)
   {
      clear();
      total=0;
      strength=0;   
      vitality=0;
      agility=0;
      std::cout << std::endl<< "\t\t\tEnter your Stats (30 point total)\n\n\n\n\n\n"<<std::endl;
      while(strength==0)
      {
	 std::cout<<"Strength: ";
	 std::cin >> strength;
	 if(strength<=0)
	    strength=0;
      }
      while(vitality==0)
      {
	 std::cout<<"Vitality: ";
	 std::cin >> vitality;
	 if(vitality<=0)
	    vitality=0;
      }

      while(agility==0)
      {
	 std::cout<<"Agility: ";
	 std::cin >> agility;
	 if(agility<=0)
	    agility=0;
      }
      total = strength+vitality+agility;
      if(total>=31)
	 total=0;
   }
   player = new EntityPlayer();
   player->setName(name);
   player->getAttributes().setStrength(strength);
   //std::cout<<player->getAttributes().getStrength()<<std::endl;
   
   player->getAttributes().setVitality(vitality);
   //std::cout<<player->getAttributes().getVitality()<<std::endl;
   player->getAttributes().setAgility(agility);
   //std::cout<<player->getAttributes().getAgility()<<std::endl;
   
   player->getAttributes().setHealthPoints(10*vitality);
   //std::cout<<player->getAttributes().getHealthPoints()<<std::endl;
   
   player->getAttributes().setDamage((difficulty*strength)*.5);
   //std::cout<<player->getAttributes().getDamage();
}

bool Game::generateMap()
{

   return true;
}

void Game::exit()
{
   isRunning = false;
}

void Game::log(std::string message)
{
   if(debug)
      std::cout << "[DEBUG] " << message << std::endl;
}

void Game::setDebug(bool d)
{
   debug = d;
}

bool Game::getDebug() const
{
   return debug;
}

int Game::getOption()
{
   int a;
   std::cout << "Enter option: ";
   std::cin >> a;

   return a;
}

void Game::clear()
{
   std::cout << std::string(100, '\n' );
}

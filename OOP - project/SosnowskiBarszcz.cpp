#include "SosnowkiBarszcz.h"
#include "World.h"

SosnowskiBarszcz::SosnowskiBarszcz(World& ourWorld, int posX, int posY)
	:Plant{ ourWorld, 10,posX,posY,'O',3,"Barszcz sosnoswkiego"}
{

}

void SosnowskiBarszcz::action()
{
	Organism* nearbyArea[8];
	nearbyArea[0] = ourWorld.getFromPostion(Coordinates{ getX(),getY() - 1 });
	nearbyArea[1] = ourWorld.getFromPostion(Coordinates{ getX(),getY() + 1 });
	nearbyArea[2] = ourWorld.getFromPostion(Coordinates{ getX() - 1,getY()});
	nearbyArea[3] = ourWorld.getFromPostion(Coordinates{ getX() + 1,getY() });
	nearbyArea[4] = ourWorld.getFromPostion(Coordinates{ getX() + 1,getY() + 1 });
	nearbyArea[5] = ourWorld.getFromPostion(Coordinates{ getX() + 1,getY() - 1 });
	nearbyArea[6] = ourWorld.getFromPostion(Coordinates{ getX() - 1,getY() + 1 });
	nearbyArea[7] = ourWorld.getFromPostion(Coordinates{ getX() - 1,getY() - 1 });

	for (int i = 0; i < 8; i++)
	{
		if (nearbyArea[i] != nullptr)
		{
			ourWorld.addToKillList(*nearbyArea[i]);
		}
	}
	
}
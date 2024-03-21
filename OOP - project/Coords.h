#pragma once
struct Coordinates
{
 int	x = 0;
 int	y = 0;
 Coordinates(int x, int y):x{x},y{y}
 {}
 Coordinates() {};

 bool operator==(const Coordinates& compared)
 {
	 if (compared.x == this->x and compared.y == this->y)
		 return true;

	 return false;
 }
};
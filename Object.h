#pragma once
enum SIGN {
	T = 0,
	E = 1,
	S = 2,
	C = 3,
	O = 4,
	BLUE = 5,
	NOTHING = -1
};
class Object
{
private:
double M1;
double M7;
long m00;
int maxX;
int maxY;
int minY;
int minX;
int centerY;
int centerX;
SIGN sign; 
public:
	Object(SIGN sig = NOTHING);
	~Object(void);
	void setM1(double m1) { M1 = m1; }
	void setM7(double m7) { M7 = m7; }
	void setXY(int minx, int maxx, int miny, int maxy) {
		minX = minx;
		maxX = maxx;
		minY = miny;
		maxY = maxy;
	}
	void setM00 (double m0) { m0 = m00; }
	void setCenter(int x, int y) {
		centerX = x;
		centerY = y;
	}
	long getM00() { return m00; }
	int getMaxX() { return maxX; }
	int getMaxY() { return maxY; }
	int getMinX() { return minX; }
	int getMinY() { return minY; }
	int getMiddleX() { return (int)((maxX + minX)/2);}
	int getMiddleY() { return (int)((maxY + minY)/2);}
	int getHeight() { return maxY - minY;}
	int getWidth() {return maxX - minX; }
	int getCenterX() const { return centerX;}
	int getCenterY() const { return centerY; }
};


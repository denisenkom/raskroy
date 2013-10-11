struct FileHeader
{
	char idLen;
	char id[12]; // *BAZIS*LDW*\0

// offset 0xa6
	double scale;

// offset 0xc6
	double left; // viewport
	double bottom;
};

struct LayerInfo
{
	short flags; // 1 - current, 2 - invisible
	char r;
	char g;
	char b;
	char unknown;
	unsigned char nameLen;
	char name[];
};

struct Line
{
	short type; // 1
	short unknown; // 51
	short lineType; // 1,2,3,...
	int unknown2; // 0
	double unknown3; // -1.0
	unsigned char r; // color
	unsigned char g;
	unsigned char b;
	short unknown4; // 1 use layer color, 0 use custom color
	double somedouble; // 3.75
	double x1;
	double y1;
	double x2;
	double y2;
};

struct Circle
{
	short type; // 2
	char unknown[16+1];
	double x;
	double y;
	double radius;
};
#include <math.h>

#include "coor.h"

static const double a = 6378137.0;
static const double f = 1.0 / 298.257223565;
static const double b = a * (1 - f);
static const double e2 = 1 - b * b / a / a;

struct coor blh2xyz(struct coor blh)
{
	double B = blh.x;
	double L = blh.y;
	double H = blh.z;
	double N = a / sqrt(1 - e2 * sin(B) * sin(B));
	struct coor xyz;
	xyz.x = (N + H) * cos(B) * cos(L);
	xyz.y = (N + H) * cos(B) * sin(L);
	xyz.z = (N * (1 - e2) + H) * sin(B);
	return (xyz);
}

struct coor blh2enu(struct coor blh1, struct coor blh2)
{
	struct coor xyz1 = blh2xyz(blh1);
	struct coor xyz2 = blh2xyz(blh2);
	double dx = xyz2.x - xyz1.x;
	double dy = xyz2.y - xyz1.y;
	double dz = xyz2.z - xyz1.z;
	double B = blh1.x;
	double L = blh1.y;
	struct coor enu;
	enu.x = -sin(L) * dx + cos(L) * dy;
	enu.y = -sin(B) * cos(L) * dx - sin(B) * sin(L) * dy + cos(B) * dz;
	enu.z = cos(B) * cos(L) * dx + cos(B) * sin(L) * dy + sin(B) * dz;
	return (enu);
}

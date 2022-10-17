#include "PlotSettings.h"
#include <cmath>

PlotSettings::PlotSettings()
{
	minX = 0.0;
	maxX = 10.0;
	numXTicks = 5;

	minY = 0.0;
	maxY = 10.0;
	numYTicks = 5;
}

void PlotSettings::scroll(int dx, int dy)
{
	double stepX = spanX() / numXTicks;
	minX += dx * stepX;
	maxX += dx * stepX;

	double stepY = spanY() / numYTicks;
	minY += dy * stepY;
	maxY += dy * stepY;
}

void PlotSettings::adjust()
{
	adjustAxis(minX, maxX, numXTicks);
	adjustAxis(minY, maxY, numYTicks);
}

void PlotSettings::adjustAxis(double& min, double& max, int& numTicks)
{
	const int MinTicks = 4;
	double grossStep = (max - min) / MinTicks;//总步长
	double step = std::pow(10.0, std::floor(std::log10(grossStep)));//搜寻小于或等于总步长其形式为10^n对应值,并进行以10为基数的对数运算，再取整；再以10为底、以前面取整所得整数为指数

	if(5*step<grossStep)
	{
		step *= 5;
	}
	else if(2*step<grossStep)
	{
		step *= 2;
	}

	numTicks = int(std::ceil(max / step) - std::floor(min / step));
	if(numTicks<MinTicks)
	{
		numTicks = MinTicks;
	}
	min = std::floor(min / step) * step;
	max = std::ceil(max / step) * step;
}

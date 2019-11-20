#include "FIgure_Rect.h"

Figure_Rect::Figure_Rect(int x, int y, int width, int height, string _figure, objectType _type)
	: Y(x), X(y), width(width), height(height), Figure(_figure), type(_type)
{}

bool Figure_Rect::isOverlap(const Figure_Rect rc1, const Figure_Rect rc2)
{
	if (rc1.X + rc1.width > rc2.X&&
		rc2.X + rc2.width > rc1.X&&
		rc1.Y + rc1.height > rc2.Y&&
		rc2.Y + rc2.height > rc1.Y
		)
		return true;
	else
		return false;
}

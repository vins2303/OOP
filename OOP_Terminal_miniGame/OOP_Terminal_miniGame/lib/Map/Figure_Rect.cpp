#include "../../include/Map/FIgure_Rect.h"

bool Figure_Rect::isOverlap(Map_object rc1, Map_object rc2)
{
	if (rc1.getX() + rc1.getWidth() > rc2.getX() &&
		rc2.getX() + rc2.getWidth() > rc1.getX() &&
		rc1.getY() + rc1.getHeigh() > rc2.getY() &&
		rc2.getY() + rc2.getHeigh() > rc1.getY()
		)
		return true;
	else
		return false;
}

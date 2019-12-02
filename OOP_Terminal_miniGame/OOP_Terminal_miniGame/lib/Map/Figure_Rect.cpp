#include "../../include/Map/FIgure_Rect.h"

bool Figure_Rect::isOverlap(Map_object rc1, Map_object rc2)
{
	if (rc1.get_seat_X() + rc1.getWidth() > rc2.get_seat_X() &&
		rc2.get_seat_X() + rc2.getWidth() > rc1.get_seat_X() &&
		rc1.get_seat_Y() + rc1.getHeigh() > rc2.get_seat_Y() &&
		rc2.get_seat_Y() + rc2.getHeigh() > rc1.get_seat_Y()
		)
		return true;
	else
		return false;
}

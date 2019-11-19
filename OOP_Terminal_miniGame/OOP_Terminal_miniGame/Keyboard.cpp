#include "keyboard.h"



int keyboard::check_kcy() {
	static HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);//�����o�򥻿�JHandle;
	static DWORD cnt;//�x�s�X�J
	static DWORD mode;//Console Mode
	static INPUT_RECORD input;
	GetConsoleMode(handle, &mode);//�o��򥻿�J��Mode
	SetConsoleMode(handle, mode & ~ENABLE_LINE_INPUT);//�]�w�򥻿�J�Ҧ��A�䤤~ENABLE_LINE_INPUT�N���Ϋ��UEnter�]�i�ʧ@

	ReadConsoleInput(handle, &input, 1, &cnt);
	if (input.EventType == KEY_EVENT)
		if (input.Event.KeyEvent.bKeyDown == TRUE)
			return input.Event.KeyEvent.wVirtualKeyCode;
	return input.EventType;
}


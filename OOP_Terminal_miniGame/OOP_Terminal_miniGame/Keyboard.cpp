#include "keyboard.h"



int keyboard::check_kcy() {
	static HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);//先取得基本輸入Handle;
	static DWORD cnt;//儲存出入
	static DWORD mode;//Console Mode
	static INPUT_RECORD input;
	GetConsoleMode(handle, &mode);//得到基本輸入的Mode
	SetConsoleMode(handle, mode & ~ENABLE_LINE_INPUT);//設定基本輸入模式，其中~ENABLE_LINE_INPUT代表不用按下Enter也可動作

	ReadConsoleInput(handle, &input, 1, &cnt);
	if (input.EventType == KEY_EVENT)
		if (input.Event.KeyEvent.bKeyDown == TRUE)
			return input.Event.KeyEvent.wVirtualKeyCode;
	return input.EventType;
}


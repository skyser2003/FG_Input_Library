#include "stdafx.h"
#include "KeyboardInput.h"

namespace FG
{
KeyboardInput::KeyboardInput()
{
}

KeyboardInput::~KeyboardInput()
{
}

void KeyboardInput::Initialize()
{
	for(int i=0; i<sizeof(keys) / sizeof(keys[0]); ++i)
	{
		keys[i] = KEY_NONE;
	}

	downKeys.clear();
	upKeys.clear();
}
void KeyboardInput::Destroy()
{
	for(int i=0; i<sizeof(keys) / sizeof(keys[0]); ++i)
	{
		keys[i] = KEY_NONE;
	}

	downKeys.clear();
	upKeys.clear();
}

void KeyboardInput::Start()
{

}
void KeyboardInput::End()
{
	for(auto keyCode : downKeys)
	{
		keys[keyCode] = KEY_PRESSING;
	}

	for(auto keyCode : upKeys)
	{
		keys[keyCode] = KEY_NONE;
	}

	downKeys.clear();
	upKeys.clear();
}

void KeyboardInput::OnMsg(UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_KEYDOWN:
		{
			SetKeyState(GetKeyCode(wParam, lParam), KEY_DOWN);
		}
		break;
	case WM_KEYUP:
		{
			SetKeyState(GetKeyCode(wParam, lParam), KEY_UP);
		}
		break;
	}
}

void KeyboardInput::SetKeyState(int keyCode, KEY_STATE state)
{
	keys[keyCode] = state;

	switch(state)
	{
	case KEY_DOWN:
		{
			downKeys.push_back(keyCode);
		}
		break;
	case KEY_UP:
		{
			upKeys.push_back(keyCode);
		}
		break;
	}
}
KeyboardInput::KEY_STATE KeyboardInput::GetKeyState(int keyCode) const
{
	if(keyCode < 0 || keyCode > sizeof(keys) / sizeof(keys[0]))
		return KEY_NONE;

	return keys[keyCode];
}

int KeyboardInput::GetKeyCode(WPARAM wParam, LPARAM lParam) const
{
	return static_cast<int>(wParam);
}

const std::list<int>& KeyboardInput::GetDownKeys() const
{
	return downKeys;
}
const std::list<int>& KeyboardInput::GetUpKeys() const
{
	return upKeys;
}

} // namespace FG
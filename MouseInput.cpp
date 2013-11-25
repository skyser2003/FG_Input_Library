#include "stdafx.h"
#include "MouseInput.h"

namespace FG
{

void MouseInput::Initialize()
{
	lButtonState = BUTTON_NONE;
	rButtonState = BUTTON_NONE;
	wheel = 0.0f;
}
void MouseInput::Destroy()
{
	lButtonState = BUTTON_NONE;
	rButtonState = BUTTON_NONE;
	wheel = 0.0f;
}

void MouseInput::Start()
{

}
void MouseInput::End()
{
	if(lButtonState == BUTTON_UP)
		SetLButtonState(BUTTON_NONE);

	if(rButtonState == BUTTON_UP)
		SetRButtonState(BUTTON_NONE);

	if(moveState == MOVE_MOVING)
		SetMoveState(MOVE_NONE);
}

void MouseInput::OnMsg(UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			lButtonState = BUTTON_DOWN;
			SetXY(lParam);
		}
		break;
	case WM_LBUTTONUP:
		{
			lButtonState = BUTTON_UP;
			SetXY(lParam);
		}
		break;
	case WM_LBUTTONDBLCLK:
		{
			lButtonState = BUTTON_DOUBLECLICK;
			SetXY(lParam);
		}
		break;
	case WM_RBUTTONDOWN:
		{
			rButtonState = BUTTON_DOWN;
			SetXY(lParam);
		}
		break;
	case WM_RBUTTONUP:
		{
			rButtonState = BUTTON_UP;
			SetXY(lParam);
		}
		break;
	case WM_RBUTTONDBLCLK:
		{
			rButtonState = BUTTON_DOUBLECLICK;
			SetXY(lParam);
		}
	case WM_MOUSEMOVE:
		{
			SetXY(lParam);
			SetMoveState(MOVE_MOVING);
		}
		break;
	}
}

void MouseInput::SetLButtonState(BUTTON_STATE state)
{
	lButtonState = state;
}
void MouseInput::SetRButtonState(BUTTON_STATE state)
{
	rButtonState = state;
}
void MouseInput::SetMoveState(MOVE_STATE state)
{
	moveState = state;
}
void MouseInput::SetWheelValue(float value)
{
	wheel = value;
}
void MouseInput::SetX(float x)
{
	this->x = x;
}
void MouseInput::SetY(float y)
{
	this->y = y;
}
void MouseInput::SetXY(float x, float y)
{
	SetX(x);
	SetY(y);
}

MouseInput::BUTTON_STATE MouseInput::GetLButtonState() const
{
	return lButtonState;
}
MouseInput::BUTTON_STATE MouseInput::GetRButtonState() const
{
	return rButtonState;
}
MouseInput::MOVE_STATE MouseInput::GetMoveState() const
{
	return moveState;
}
float MouseInput::GetWheelValue() const
{
	return wheel;
}
float MouseInput::GetX() const
{
	return x;
}
float MouseInput::GetY() const
{
	return y;
}

void MouseInput::SetXY(LPARAM lParam)
{
	x = LOWORD(lParam);
	y = HIWORD(lParam);
}

} // namespace FG
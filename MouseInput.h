#pragma once

#include "Input.h"

namespace FG
{
	class MouseInput : public Input
	{
	public:
		enum BUTTON_STATE
		{
			BUTTON_NONE,
			BUTTON_DOWN,
			BUTTON_UP,
			BUTTON_DOUBLECLICK,
			BUTTON_DRAG
		};

		enum MOVE_STATE
		{
			MOVE_NONE,
			MOVE_MOVING
		};

		virtual void Initialize() override;
		virtual void Destroy() override;

		virtual void Start() override;
		virtual void End() override;

		virtual void OnMsg(UINT msg, WPARAM wParam, LPARAM lParam) override;

		void SetScreenSize(int width, int height);

		void SetLButtonState(BUTTON_STATE state);
		void SetRButtonState(BUTTON_STATE state);
		void SetMoveState(MOVE_STATE state);
		void SetWheelValue(float value);
		void SetX(WORD x);
		void SetY(WORD y);
		void SetXY(WORD x, WORD y);

		BUTTON_STATE GetLButtonState() const;
		BUTTON_STATE GetRButtonState() const;
		MOVE_STATE GetMoveState() const;
		float GetWheelValue() const;
		WORD GetX() const;
		WORD GetY() const;
	private:
		void SetXY(LPARAM lParam);

		BUTTON_STATE lButtonState;
		BUTTON_STATE rButtonState;
		MOVE_STATE moveState;

		float wheel;
		WORD x,y;
		WORD mScreenWidth, mScreenHeight;
	};
}
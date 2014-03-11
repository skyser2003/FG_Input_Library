#pragma once

namespace FG
{
	class Input
	{
	public:
		virtual ~Input() {}

		virtual void Initialize() = 0;
		virtual void Destroy() = 0;

		virtual void Start() = 0;
		virtual void End() = 0;

		virtual void OnMsg(UINT msg, WPARAM wParam, LPARAM lParam) = 0;
	};
}
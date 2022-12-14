#pragma once

namespace myclass
{
	class Figures
	{
	public:
		float v_x = 1;
		float v_y = 2;
		int x0;
		int y0;
		int A;
		int B;
		int R;
		sf::Color color;
		float xn;
		float yn;
		float h;
		float w;
		int flag;

		void SetRect(float sv_x, float sv_y, int start_x, int start_y, sf::Color sColor, int length1, int length2)
		{
			v_x = sv_x;
			v_y = sv_y;
			x0 = start_x;
			y0 = start_y;
			color = sColor;
			A = length1;
			B = length2;
			flag = 0;
		}
		void SetCircle(float sv_x, float sv_y, int start_x, int start_y, sf::Color sColor, int radius)
		{
			v_x = sv_x;
			v_y = sv_y;
			x0 = start_x;
			y0 = start_y;
			color = sColor;
			R = radius;
			flag = 0;
		}
		void SetCoords(int Width)
		{
			xn = x0 + v_x;
			yn = y0 + v_y;
		}
		void RectFlag(int Width,int Height)
		{
			// втыкается в правый верхний угол
			if ((xn >= Width - B) && (yn <= 0))
			{
				flag = 3;
			}
			// втыкается вправо
			else if (xn >= Width - B)
			{
				flag = 1;
			}
			// втыкается вверх
			else if (yn <= 0)
			{
				flag = 2;
			}
		}
		void CircleFlag(int Width, int Height)
		{
			// втыкается в правый верхний угол
			if ((xn >= Width - 2*R) && (yn <= 0))
			{
				flag = 3;
			}
			// втыкается вправо
			else if (xn >= Width - 2*R)
			{
				flag = 1;
			}
			// втыкается вверх
			else if (yn <= 0)
			{
				flag = 2;
			}
		}
	};
}
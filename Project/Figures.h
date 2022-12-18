#pragma once

namespace myclass
{
	class Figures
	{
	private:
		int v_x;
		int v_y;
		int x0;
		int y0;
		int RectW;
		int RectH;
		int Pose = 0;
		bool launch = false;

	public:
		void SetHero(int start_x, int start_y, int lengthW, int lengthH)
		{
			x0 = start_x;
			y0 = start_y;
			RectW = lengthW;
			RectH = lengthH;
		}

		int GetX0()
		{
			return x0;
		}

		void SetX0(int start_x)
		{
			x0 = start_x;
		}

		int GetY0()
		{
			return y0;
		}

		void SetY0(int start_y)
		{
			y0 = start_y;
		}

		int GetVX()
		{
			return v_x;
		}

		int GetVY()
		{
			return v_y;
		}

		int GetRectW()
		{
			return RectW;
		}

		int GetRectH()
		{
			return RectH;
		}

		int GetLaunch()
		{
			return launch;
		}

		int GetPose()
		{
			return Pose;
		}

		void SetLaunch(bool setLaunch)
		{
			launch = setLaunch;
		}

		void SetHeroAnimation()
		{
			if ((launch == true))
			{
				Pose += 1;
				if (Pose > 4)
				{
					Pose = 0;
				}
			}
			else if ((launch == false) && Pose < 11)
			{
				Pose += 1;
				if (Pose == 11)
				{
					launch = true;
					v_y = (rand() % 9 - 5);
				}
			}
			else
				Pose = 0;
		}

		void SetFireball(int start_x, int start_y, int lengthW, int lengthH, int vx, int vy)
		{
			x0 = start_x;
			y0 = start_y;
			RectW = lengthW;
			RectH = lengthH;
			v_x = vx;
			v_y = vy;
		}
	};
}
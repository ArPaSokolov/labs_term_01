#pragma once

	class Animation
	{
	private:
		int v_x; //скорость по Х
		int v_y; //скорость по Y
		int x0; //координата по Х
		int y0; //координата по Y
		int RectW; //ширина тайла
		int RectH; //высота тайла
		int Pose = 0; //поза персонажа == тайл
		bool launch = false; //запуск файербола

	public:
		// сеттеры
		void SetX0(int start_x)
		{
			x0 = start_x;
		}

		void SetY0(int start_y)
		{
			y0 = start_y;
		}

		void SetHero(int start_x, int start_y, int lengthW, int lengthH)
		{
			x0 = start_x; //координата героя по X
			y0 = start_y; //координата героя по Y
			RectW = lengthW; // ширина тайла
			RectH = lengthH; // высота тайла
		}

		void SetHeroAnimation()
		{
			if ((launch == true)) // если файербол запущен
			{
				Pose += 1; //меняем позы по тайлам с 0 до 4
				if (Pose > 4) //если поза 4 была, анимируй по новой
				{
					Pose = 0;
				}
			}
			else if ((launch == false) && Pose < 11) // если файербол не запущен, и поза к запуску не готова
			{
				Pose += 1; //анимируем позы по тайлам с текущей до 11 (герой готов запустить)
				if (Pose == 11) // если герой готов запустить файербол
				{
					launch = true; // запускаем
					v_y = (rand() % 9 - 5); //разброс файербола == скорость по Y
				}
			}
			else
				Pose = 0; //иначе тайл 0
		}

		void SetLaunch(bool setLaunch)
		{
			launch = setLaunch; //герой готов запускать, шар готов лететь
		}

		void SetFireball(int start_x, int start_y, int lengthW, int lengthH, int vx, int vy)
		{
			x0 = start_x; //координата шара по Х
			y0 = start_y; //координата шара по Y
			RectW = lengthW; //ширина тайла
			RectH = lengthH; //высота тайла
			v_x = vx; //скорость по Х
			v_y = vy; //скорость по Y
		}
		
		//геттеры
		int GetX0()
		{
			return x0;
		}

		int GetY0()
		{
			return y0;
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
	};
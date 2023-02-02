#pragma once

	class Animation
	{
	private:
		int v_x; //�������� �� �
		int v_y; //�������� �� Y
		int x0; //���������� �� �
		int y0; //���������� �� Y
		int RectW; //������ �����
		int RectH; //������ �����
		int Pose = 0; //���� ��������� == ����
		bool launch = false; //������ ���������

	public:
		// �������
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
			x0 = start_x; //���������� ����� �� X
			y0 = start_y; //���������� ����� �� Y
			RectW = lengthW; // ������ �����
			RectH = lengthH; // ������ �����
		}

		void SetHeroAnimation()
		{
			if ((launch == true)) // ���� �������� �������
			{
				Pose += 1; //������ ���� �� ������ � 0 �� 4
				if (Pose > 4) //���� ���� 4 ����, �������� �� �����
				{
					Pose = 0;
				}
			}
			else if ((launch == false) && Pose < 11) // ���� �������� �� �������, � ���� � ������� �� ������
			{
				Pose += 1; //��������� ���� �� ������ � ������� �� 11 (����� ����� ���������)
				if (Pose == 11) // ���� ����� ����� ��������� ��������
				{
					launch = true; // ���������
					v_y = (rand() % 9 - 5); //������� ��������� == �������� �� Y
				}
			}
			else
				Pose = 0; //����� ���� 0
		}

		void SetLaunch(bool setLaunch)
		{
			launch = setLaunch; //����� ����� ���������, ��� ����� ������
		}

		void SetFireball(int start_x, int start_y, int lengthW, int lengthH, int vx, int vy)
		{
			x0 = start_x; //���������� ���� �� �
			y0 = start_y; //���������� ���� �� Y
			RectW = lengthW; //������ �����
			RectH = lengthH; //������ �����
			v_x = vx; //�������� �� �
			v_y = vy; //�������� �� Y
		}
		
		//�������
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
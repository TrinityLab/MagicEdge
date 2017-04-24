
//
//#include <iostream.h>
//#include <stdio.h>
//#include <io.h>
//#include "list"
//
//#define MEN 2
//#define LF 10
//#define SPACE 32
//#define ORIGINAL_MAZE 0
//#define MAZE_WITH_PATH 1
//
//struct Point
//{
//	int x;
//	int y;
//} exit;
//
//int** maze;
//int sizex = 0, sizey = 0;
//
//int load_maze()
//{
//	int i, j, filesize = 0, x = 0, y = 0;
//	char* cc;
//	FILE *F;
//	//�������� ������� ��������� ���� ��� ������:
//	F = fopen("maze.txt", "rt");
//	if (F == NULL)
//		return 0;
//	//������� ������, � ������� �������� ����� �� �����:
//	filesize = filelength(fileno(F));
//	cc = new char[filesize];
//	//��������� � ������ ����� �� �����:
//	for (i = 0;i != filesize;i++)
//		cc[i] = getc(F);
//	fclose(F);
//	//������������ ������� ������� ���������:
//	i = 0;
//	while (cc[i] != LF)
//	{
//		if (cc[i] != SPACE)
//			sizex++;
//		i++;
//	}
//	sizey = filesize / (sizex * 2);
//	//������ ������ ��������� ��������, �������������� �������:
//	maze = new int*[sizey];
//	while (y != sizey)
//		maze[y++] = new int[sizex];
//	//��������� ������� ��������� ������� �� �����
//	i = 0;
//	for (y = 0;y != sizey;y++)
//	{
//		for (j = 0;j != sizex;j++)
//		{
//			maze[y][x] = cc[i] - 48;
//			x++;
//			i += 2;
//		}
//		x = 0;
//	}
//	return 1;
//}
//
//int temp = MEN;
//
//int check(int x, int y)
//{
//	int cnt = 0;
//	if (x != 0 && maze[y][x - 1] == 0)
//	{
//		maze[y][x - 1] = temp + 1;
//		cnt++;
//	}
//	if (x != sizex - 1 && maze[y][x + 1] == 0)
//	{
//		maze[y][x + 1] = temp + 1;
//		cnt++;
//	}
//	if (y != 0 && maze[y - 1][x] == 0)
//	{
//		maze[y - 1][x] = temp + 1;
//		cnt++;
//	}
//	if (y != sizey - 1 && maze[y + 1][x] == 0)
//	{
//		maze[y + 1][x] = temp + 1;
//		cnt++;
//	}
//	return cnt;
//}
//
//int search_exit()
//{
//	int x, y;
//	exit.x = 0;
//	exit.y = 0;
//	y = 0;
//	for (x = 0; x != sizex; x++)
//		if (maze[y][x] == 0)
//		{
//			exit.x = x;
//			exit.y = y;
//			return 1;
//		}
//	y = sizey - 1;
//	for (x = 0; x != sizex; x++)
//		if (maze[y][x] == 0)
//		{
//			exit.x = x;
//			exit.y = y;
//			return 1;
//		}
//	x = 0;
//	for (y = 0; y != sizey; y++)
//		if (maze[y][x] == 0)
//		{
//			exit.x = x;
//			exit.y = y;
//			return 1;
//		}
//	x = sizex - 1;
//	for (y = 0; y != sizey; y++)
//		if (maze[y][x] == 0)
//		{
//			exit.x = x;
//			exit.y = y;
//			return 1;
//		}
//	return 0;
//}
//
//void print_maze(char mode)
//{
//	int x, y;
//	for (y = 0; y != sizey; y++)
//	{
//		for (x = 0; x != sizex; x++)
//		{
//			if (maze[y][x] == MEN)
//				cout << "M" << "";
//			else
//				if (mode == 1 && maze[y][x] == 0)
//					cout << "*" << "";
//				else
//					if (maze[y][x] > MEN)
//						cout << "0" << "";
//					else
//						cout << maze[y][x] << "";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	int x, y, paths = 0, i = 1, steps, cnt = 0;
//	if (load_maze() == 0)
//	{
//		cout << "File maze.txt not found." << endl;
//		return 0;
//	}
//	//����� ������� ��������� � �������:
//	cout << "Labirint:\r\n" << "(" << sizex << "x" << sizey << ")\r\n" << endl;
//	print_maze(ORIGINAL_MAZE);
//	//�������:
//	cout << "\r\nM - Chelovek\r\n1 - Stena\r\n0 - Prohod" << endl;
//	//���� ��� ���������� ��������, ������� ����, �� ������ �� ��������� ���
//	if (search_exit() == 0)
//	{
//		cout << "\r\nVuhoda iz labirinta net." << endl;
//		return 0;
//	}
//	cout << "\r\nKoordinatu Vuhoda:\r\nX = " << exit.x << "; Y = " << exit.y << "\r\n" << endl;
//	//���� ���������� ���� � ������ �� ���������:
//	while (true)
//	{
//		//�������� �� ������� ��� �������� ������� � ������� �������� �������� ��� ���������, ������� ����� temp
//		for (y = 0; y != sizey; y++)
//		{
//			for (x = 0; x != sizex; x++)
//			{
//				if (maze[y][x] == temp)
//					paths += check(x, y); //������� ������� �������� y,x
//			}
//		}
//		//paths ����� ���� ������ ���� ����� ������� �������� �� ��������� temp ��� �� ������
//		//�������� �� ��������� 0 => ������� ���������, ��������� ����� ����.
//		if (paths == 0)
//		{
//			cout << "\r\nVuhoda iz labirinta net." << endl;
//			return 0;
//		}
//
//		paths = 0;
//		if (maze[exit.y][exit.x] == 0)
//			temp++;
//		else
//			break;
//	}
//	//���� � ������ ������ steps:
//	steps = maze[exit.y][exit.x];
//	maze[exit.y][exit.x] = 0;
//	x = exit.x;
//	y = exit.y;
//	//�������� ������ ���������� ����:
//	while (true)
//	{
//		if (x != 0 && maze[y][x - 1] == steps - i)
//		{
//			if (maze[y][x - 1] == 2)
//				break;
//			maze[y][x - 1] = 0;
//			x--;
//		}
//		if (x != sizex - 1 && maze[y][x + 1] == steps - i)
//		{
//			if (maze[y][x + 1] == 2)
//				break;
//			maze[y][x + 1] = 0;
//			x++;
//		}
//		if (y != 0 && maze[y - 1][x] == steps - i)
//		{
//			if (maze[y - 1][x] == 2)
//				break;
//			maze[y - 1][x] = 0;
//			y--;
//		}
//		if (y != sizey - 1 && maze[y + 1][x] == steps - i)
//		{
//			if (maze[y + 1][x] == 2)
//				break;
//			maze[y + 1][x] = 0;
//			y++;
//		}
//		i++;
//	}
//
//	print_maze(MAZE_WITH_PATH);
//	
//	return 1;
//}
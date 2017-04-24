
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
//	//Пытаемся открыть текстовой файл для чтения:
//	F = fopen("maze.txt", "rt");
//	if (F == NULL)
//		return 0;
//	//Создаем массив, в который поместим байты из файлы:
//	filesize = filelength(fileno(F));
//	cc = new char[filesize];
//	//Загружаем в массив байты из файла:
//	for (i = 0;i != filesize;i++)
//		cc[i] = getc(F);
//	fclose(F);
//	//Рассчитываем размеры матрицы лабиринта:
//	i = 0;
//	while (cc[i] != LF)
//	{
//		if (cc[i] != SPACE)
//			sizex++;
//		i++;
//	}
//	sizey = filesize / (sizex * 2);
//	//Теперь размер лабиринта известен, инициализируем матрицу:
//	maze = new int*[sizey];
//	while (y != sizey)
//		maze[y++] = new int[sizex];
//	//Заполняем матрицу лабиринта данными из файла
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
//	//Вывод матрицы лабиринта в консоль:
//	cout << "Labirint:\r\n" << "(" << sizex << "x" << sizey << ")\r\n" << endl;
//	print_maze(ORIGINAL_MAZE);
//	//Легенда:
//	cout << "\r\nM - Chelovek\r\n1 - Stena\r\n0 - Prohod" << endl;
//	//Если нет граничного элемента, равного нулю, то выхода из лабиринта нет
//	if (search_exit() == 0)
//	{
//		cout << "\r\nVuhoda iz labirinta net." << endl;
//		return 0;
//	}
//	cout << "\r\nKoordinatu Vuhoda:\r\nX = " << exit.x << "; Y = " << exit.y << "\r\n" << endl;
//	//Ищем кратчайший путь к выходу из лабиринта:
//	while (true)
//	{
//		//Проходим по очереди все элементы матрицы и смотрим соседние элементы тех элементов, которые равны temp
//		for (y = 0; y != sizey; y++)
//		{
//			for (x = 0; x != sizex; x++)
//			{
//				if (maze[y][x] == temp)
//					paths += check(x, y); //Смотрим соседей элемента y,x
//			}
//		}
//		//paths равна нулю только если среди соседей элемента со значением temp нет ни одного
//		//элемента со значением 0 => человек замурован, завершить поиск пути.
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
//	//Путь к выходу длиной steps:
//	steps = maze[exit.y][exit.x];
//	maze[exit.y][exit.x] = 0;
//	x = exit.x;
//	y = exit.y;
//	//Выделяем нулями пройденный путь:
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
#include "Functions.h"

int isvalid(int a, int b) {
	if (((a > N - 1) || (a < 0)) || ((b > N - 1) || (b < 0)))
	{
		cout << "������! ���������� � ����� �������� �� ����������.\n";
		_getch();
		return -1;
	}
	else if (a == b)
	{
		cout << "������! ��������� �� ����� ���� ������� ��� � ����.\n";
		_getch();
		return -2;
	}
	return 0;
}

void shapka(void)
{
	cout << "|------------------------------------------------------------------------------|\n";
	cout << "|----------------------������� ������ ��������� ��������-----------------------|\n";
	cout << "|------------------------------------------------------------------------------|\n";
	cout << "|  ���  |   ������� ������������  | ������� ������� (�)| ������� ������� (���) |\n";
	cout << "|-------|-------------------------|--------------------|-----------------------|\n";
}

void linebuild(void) {
	cout << "|-------|-------------------------|--------------------|-----------------------|\n";
}
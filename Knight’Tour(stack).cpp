#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 9;

template <typename T>
class stack
{
public:
	friend ostream& operator<< (ostream& os, const stack<T> &s);

	stack();
	stack(long value);
	~stack();

	bool push(const T& pushvalue);
	bool pop(T& popvalue);
	bool peek(T& peekvalue) const;

	bool isempty() const;
	bool isfull()const;

private:
	T* elements;
	long size;
	long top;

	void setsize(long _size);
	long getsize();

	void allocatememory();
	const static long default_stack_size = 256;
};
template <class T>
stack<T>::stack()
{
	size = default_stack_size;
	allocatememory();
	top = -1;
}
template <typename T>
stack<T>::stack(long value)
{
	if (val < 0)
		value *= -1;
	else if (val == 0)
		value = defult_stack_size;

	size = value;
	allocatememory();
	top = -1;
}
template <typename T>
stack<T>::~stack()
{
	delete[] elements;
}

template <typename T>
bool stack<T>::push(const T& pushvalue)
{
	if (!isfull())
	{
		elements[++top] = pushvalue;
		return true;
	}
	else
		false;
}

template <typename T>
bool stack<T>::pop(T& popvalue)
{
	if (!isempty())
	{
		popvalue = elements[top--];
		return true;
	}
	else
		false;
}

template <typename T>
bool stack<T>::peek(T& peekvalue) const
{
	if (!isempty())
	{
		peekvalue = elements[top];
		return true;
	}
	else
		false;
}


template <typename T>
bool stack<T>::isempty() const
{
	return top < 0;
}
template <typename T>
bool stack<T>::isfull()const
{
	return top + 1 >= size;
}

template <typename T>
long stack<T>::getsize()
{
	return size;
}
template <typename T>
void stack<T>::setsize(long _size)
{
	size = _size;
}
template <typename T>
void stack<T>::allocatememory()
{
	elements = new T[size];

	if (elements == NULL)
	{
		cout << "stack memory allocation error" << endl;
		exit(1);
	}
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T> &s)
{
	cout << "contents of stack: ";

	int t = s.top;
	while (t > -1)
		cout << s.elements[t--] << " ";
	cout << endl;

	return os;
}

class knighttour
{
public:
	knighttour();
	knighttour(int srow, int scol);

	bool buildknighttour(int startrow, int startcol);
	void printboard();

private:
	typedef int boardtype[MAX_SIZE][MAX_SIZE];

	bool recurknighttour(int startrow, int startcol, int move);
	bool isvalidmove(int row, int col);

	int sizerow, sizecol;
	boardtype board;
};

class position
{
public:
	position(int x = 0, int y = 0)	{ row = x;	col = y; }
	int getrow() const	{ return row; }
	int getcol() const	{ return col; }
	int getdir() const	{ return dir; }
	void setpos(int r, int c)	{ row = r;	col = c; }
	void setpos(position& p)	{ row = p.row;	col = p.col; }
	void setdir(int d)	{ dir = d; }

private:
	int row;
	int col;
	int dir;
};

static int direction[8][2] = { { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 } };

knighttour::knighttour()	{ sizerow = sizecol = 8; }
knighttour::knighttour(int srow, int scol)
{
	if (srow >= 2 && srow <= MAX_SIZE)
		sizerow = srow;
	else
		sizerow = 8;

	if (scol >= 2 && scol <= MAX_SIZE)
		sizecol = scol;
	else
		sizecol = 8;
}

bool knighttour::buildknighttour(int startrow, int startcol)
{
	for (int r = 0; r < sizerow; r++)
	{
		for (int c = 0; c < sizecol; c++)
			board[r][c] = 0;
	}
	if (startrow <= 0 || startrow > sizerow)
		startrow = 0;
	if (startcol <= 0 || startcol > sizecol)
		startcol = 0;

	board[startrow - 1][startcol - 1] = 1;

	return recurknighttour(startrow - 1, startcol - 1, 1);
}
void knighttour::printboard()
{
	for (int r = 0; r < sizerow; r++)
	{
		for (int c = 0; c < sizecol; c++)
			cout << board[r][c] << " ";
		cout << endl;

	}
}

bool knighttour::recurknighttour(int startrow, int startcol, int move)
{
	stack<position> s;
	position pos, nextpos;
	int dir;

	pos.setpos(startrow, startcol);
	nextpos.setdir(0);
	s.push(pos);
	while (move < sizerow*sizecol)
	{
		for (dir = nextpos.getdir(); dir < 8; dir++)
		{
			nextpos.setpos(pos.getrow() + direction[dir][0], pos.getcol() + direction[dir][1]);

			if (isvalidmove(nextpos.getrow(), nextpos.getcol()))
			{
				move++;
				pos.setpos(nextpos);
				pos.setdir(dir);
				s.push(pos);
				nextpos.setdir(0);
				board[nextpos.getrow()][nextpos.getcol()] = move;
				break;
			}
		}
		if (dir == 8)
		{
			move--;
			if (move == 0)
				return false;
			board[pos.getrow()][pos.getcol()] = 0;
			s.pop(pos);
			s.peek(nextpos);
			pos.setpos(nextpos);
			nextpos.setdir(pos.getdir() + 1);
		}
	}
	return true;
}
bool knighttour::isvalidmove(int row, int col)
{
	if (row >= sizerow || row < 0)
		return false;
	if (col >= sizecol || col < 0)
		return false;
	if (board[row][col] != 0)
		return false;
	else
		return true;
}

void main()
{
	ifstream inStream;
	int cases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed\n";
		exit(1);
	}

	inStream >> cases;

	for (int i = 0; i < cases; i++)
	{
		int sizerow, sizecol;
		int startrow, startcol;

		inStream >> sizerow >> sizecol;
		inStream >> startrow >> startcol;

		knighttour ktour(sizerow, sizecol);

		if (ktour.buildknighttour(startrow, startcol))
		{
			cout << 1 << endl;
			ktour.printboard();
		}
		else
			cout << 0 << endl;
	}
	inStream.close();
}
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int row, col, level;
	Pos(int row, int col) :row(row), col(col){}
	Pos(int row, int col, int level) :row(row), col(col), level(level){}
};

int N = 5, M = 5;
int wall[21][21] = {
	{ 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 1, 0 },
	{ 1, 0, 0, 0, 1, 0 },
	{ 1, 0, 0, 1, 1, 0 }
};
bool isLeft(Pos p) {
	return p.col > 1;
}
bool isRight(Pos p) {
	return p.col < M;
}
bool isUp(Pos p) {
	return p.row < N;
}
bool isDown(Pos p) {
	return p.row > 1;
}

bool isLeftWall(Pos p) {
	return wall[p.row][p.col - 1] == 1;
}
bool isRightWall(Pos p) {
	return wall[p.row][p.col + 1] == 1;
}
bool isUpWall(Pos p) {
	return wall[p.row + 1][p.col] == 1;
}
bool isDownWall(Pos p) {
	return wall[p.row - 1][p.col] == 1;
}
int main()
{
	// N:세로, M:가로
	cin >> N >> M;
	cin.ignore();

	queue<Pos> Q;
	char input[21][21];

	int chk[21][21] = {};
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			wall[i][j] = 1;

	for (int i = N; i >= 1; i--) {
		cin.getline(input[i] + 1, 20);
		for (int j = 1; j <= M; j++)
			wall[i][j] = input[i][j] - '0';
	}

	Pos start(1, 1, 1);
	Pos end(N, N);

	int result = -1;
	int min = 21 * 21;
	Q.push(start);
	while (!Q.empty())
	{
		Pos pick = Q.front();
		Q.pop();
		if (chk[pick.row][pick.col])
			continue;
		chk[pick.row][pick.col] = true;

		bool go = true;

		if (isRight(pick) && !isRightWall(pick) && !chk[pick.row][pick.col + 1]) {
			Q.push(Pos(pick.row, pick.col + 1, pick.level + 1));
			go = true;
		}
		if (isUp(pick) && !isUpWall(pick) && !chk[pick.row + 1][pick.col]) {
			Q.push(Pos(pick.row + 1, pick.col, pick.level + 1));
			go = true;
		}
		if (isLeft(pick) && !isLeftWall(pick) && !chk[pick.row][pick.col - 1]) {
			Q.push(Pos(pick.row, pick.col - 1, pick.level + 1));
			go = true;
		}
		if (isDown(pick) && !isDownWall(pick) && !chk[pick.row - 1][pick.col]) {
			Q.push(Pos(pick.row - 1, pick.col, pick.level + 1));
			go = true;
		}

		if (pick.row == end.row && pick.col == end.col) {
			min = (min > pick.level) ? pick.level : min;
		}
	}

	cout << min << endl;

	return 0;
}
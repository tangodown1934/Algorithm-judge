#include <iostream>

using namespace std;

class To {
public:
	int row, column;
	int val;
	To() {}
	To(int x, int y, int val) : row(x), column(y), val(val) {}
};

const int MAX_SIZE = 100000;
class Queue {
	int front, rear;
	To arr[MAX_SIZE];

public:
	Queue() {
		front = 0; rear = 0;
	}

	To pop()
	{
		if (empty())
			return To(0, 0, 0);

		To val = arr[front++];
		front = front % MAX_SIZE;
		return val;
	}

	void push(To val)
	{
		if (front - rear == 1 || front - rear == -(MAX_SIZE - 1))
			return;

		arr[rear++] = val;
		rear = rear % MAX_SIZE;
	}

	bool empty()
	{
		return front == rear;
	}
};

int main()
{

	int n, k, start_row, start_column;
	int arr[1001][1001] = {};
	int ma_arr[1001][1001] = {};

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1)
				arr[i][j] = -1;
	cin >> start_row >> start_column;
	arr[start_row][start_column] = -1;
	// 나이트
	Queue kn;
	kn.push(To(start_row, start_column, 0));
	while (!kn.empty())
	{
		To current = kn.pop();

		if (current.row >= 1 && current.row <= n)
		{
			if (current.row + 2 <= n)
			{
				int row = current.row + 2;
				if (current.column + 1 <= n) {
					int column = current.column + 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
				if (current.column - 1 >= 1) {
					int column = current.column - 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
			}
			if (current.row - 2 >= 1)
			{
				int row = current.row - 2;
				if (current.column + 1 <= n) {
					int column = current.column + 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
				if (current.column - 1 >= 1) {
					int column = current.column - 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
			}
		}
		if (current.column >= 1 && current.column <= n)
		{
			if (current.column + 2 <= n)
			{
				int column = current.column + 2;
				if (current.row + 1 <= n) {
					int row = current.row + 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
				if (current.row - 1 >= 1) {
					int row = current.row - 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
			}
			if (current.column - 2 >= 1)
			{
				int column = current.column - 2;
				if (current.row + 1 <= n) {
					int row = current.row + 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
				if (current.row - 1 >= 1) {
					int row = current.row - 1;

					if (arr[row][column] == 0) {
						arr[row][column] = current.val + 1;
						kn.push(To(row, column, current.val + 1));
					}
				}
			}
		}

	} // 나이트 while end

	// 마
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == -1)
				ma_arr[i][j] = -1;
	ma_arr[start_row][start_column] = 0;

	Queue ma;
	ma.push(To(start_row, start_column, 0));

	while (!ma.empty())
	{
		To current = ma.pop();

		if (current.row >= 1 && current.row <= n)
		{
			if (ma_arr[current.row + 1][current.column] != -1 && current.row + 2 <= n)
			{
				int row = current.row + 2;
				if (current.column + 1 <= n) {
					int column = current.column + 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
				if (current.column - 1 >= 1) {
					int column = current.column - 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
			}
			if (ma_arr[current.row - 1][current.column] != -1 && current.row - 2 >= 1)
			{
				int row = current.row - 2;
				if (current.column + 1 <= n) {
					int column = current.column + 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
				if (current.column - 1 >= 1) {
					int column = current.column - 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
			}
		}
		if (current.column >= 1 && current.column <= n)
		{
			if (ma_arr[current.row][current.column + 1] != -1 && current.column + 2 <= n)
			{
				int column = current.column + 2;
				if (current.row + 1 <= n) {
					int row = current.row + 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
				if (current.row - 1 >= 1) {
					int row = current.row - 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
			}
			if (ma_arr[current.row][current.column - 1] != -1 && current.column - 2 >= 1)
			{
				int column = current.column - 2;
				if (current.row + 1 <= n) {
					int row = current.row + 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
				if (current.row - 1 >= 1) {
					int row = current.row - 1;

					if (ma_arr[row][column] == 0 && !(row == start_row && column == start_column)) {
						ma_arr[row][column] = current.val + 1;
						ma.push(To(row, column, current.val + 1));
					}
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == -1 || arr[i][j] == 0)
				continue;

			if (arr[i][j] < ma_arr[i][j])
				result++;
			else if (ma_arr[i][j] == 0 || ma_arr[i][j] == -1)
				result++;
		}

	cout << result << endl;

	return 0;
}
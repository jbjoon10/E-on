#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	for (int a = 0; a < commands.size(); a++)
	{
		vector<int> tmp;
		for (int i = 0; i < array.size(); i++) tmp.push_back(array[i]);

		int i = commands[a][0];
		int j = commands[a][1];
		int k = commands[a][2];

		sort(tmp.begin() + i - 1, tmp.begin() + j);
		for (int i = 0; i < tmp.size(); i++) printf("%d ", tmp[i]);
		printf("\n");
		answer.push_back(tmp[i + k - 2]);
	}
	return answer;
}

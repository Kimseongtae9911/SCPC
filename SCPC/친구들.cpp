#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <memory>

using namespace std;

int Answer;

int main()
{
	int T, test_case;
	int N;
	unordered_set<int> uos;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> N;

		uos.clear();
		uos.reserve(N);
		unique_ptr<int[]> p{ new int[N] };

		for (int i = 0; i < N; ++i) {
			cin >> p[i];
		}

		for (int i = 0; i < N; ++i) {
			if (uos.contains(i))
				continue;
			int j = i;
			while ((j + 1) + p[j] <= N) {
				uos.insert(j);
				j += p[j];
			}
			if (uos.contains(j))
				continue;
			uos.insert(j);
			++Answer;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
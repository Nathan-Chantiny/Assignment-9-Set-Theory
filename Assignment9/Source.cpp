#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> V = { 1,2,3,4,5,6,7,8,9,10 };

vector<int> alterV(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == i + 1) {}
		else {
			vec.insert(vec.begin() + i, 0);
		}
	}

	while (vec.size() < 10) {
		vec.push_back(0);
	}

	return vec;
}

void outputV(vector<int> result, int option) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < result.size(); j++) {
			if (result[j] == 0) {
				result.erase(result.begin() + j);
			}
		}
	}

	if (result.empty()) {
		cout << "   result: Empty";
	}
	else if (result.size() == 1) {
		cout << "result: { " << result[0] << " }";
	}
	else {
		if (option == 1) {
			cout << "   result: {" << result[0] << ", ";
			for (int i = 1; i < result.size() - 1; i++) {
				cout << result[i] << ", ";
			}
			cout << result[result.size() - 1] << "}";
		}
		else if (option == 0) {
			cout << "magnitude: " << result.size();
		}
	}
	cout << "\n\n";
}

vector<int> uni0nV(vector<int> one, vector<int> two) {
	vector<int> result;

	for (int i = 0; i < 10; i++) {
		if (one[i] != 0 && two[i] != 0) {
			result.push_back((one[i] + two[i]) / 2);
		}
		else if (one[i] == 0 && two[i] != 0) {
			result.push_back(two[i]);
		}
		else if (one[i] != 0 && two[i] == 0) {
			result.push_back(one[i]);
		}
	}

	result = alterV(result);

	return result;
}

vector<int> intersectV(vector<int> one, vector<int> two) {
	vector<int> result;

	for (int i = 0; i < 10; i++) {
		if (one[i] != 0 && two[i] != 0) {
			if (one[i] == two[i]) {
				result.push_back(one[i]);
			}
		}
	}

	result = alterV(result);

	return result;
}

vector<int> removeV(vector<int> one, vector<int> two) {
	vector<int> result;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < one.size(); j++) {
			if (one[j] == two[i]) {
				one.erase(one.begin() + j);
			}
		}
	}

	result = alterV(one);

	return result;
}

vector<int> inverseV(vector<int> one) {
	vector<int> result;

	for (int i = 0; i < 10; i++) {
		if (one[i] != V[i]) {
			if (one[i] > 0) {
				result.push_back(one[i]);
			}
			else if (V[i] > 0) {
				result.push_back(V[i]);
			}
		}
	}

	result = alterV(result);

	return result;
}

int main() {
	vector<int> A = alterV(V);

	vector<int> B = { 2,4,6,8,10 };
	B = alterV(B);

	vector<int> C = { 1,3,5,7,9 };
	C = alterV(C);

	vector<int> D = { 1,2,3,5,7 };
	D = alterV(D);

	cout << "problem 1: A n D" << "\n";
	outputV(intersectV(A, D), 1);

	cout << "problem 2: (B U C) n A" << "\n";
	outputV(intersectV(uni0nV(B, C), A), 1);

	cout << "problem 3: (!C U C) n A" << "\n";
	outputV(intersectV(uni0nV(inverseV(C), C), A), 1);

	cout << "problem 4: A - D" << "\n";
	outputV(removeV(A, D), 1);

	cout << "problem 5: N(!A U (C U D))" << "\n";
	outputV(uni0nV(inverseV(A), uni0nV(C, D)), 0);

	cout << "problem 6: D n C" << "\n";
	outputV(intersectV(D, C), 1);

	cout << "problem 7: N(B n C)" << "\n";
	outputV(intersectV(B, C), 0);

	cout << "problem 8: A U B U C U D" << "\n";
	outputV(uni0nV(A, uni0nV(B, uni0nV(C, D))), 1);
}
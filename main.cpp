#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "Enter 2 arguments!";
		return 0;
	}
	std::string in = argv[1];
	std::string out = argv[2];

	std::unordered_map<std::string, int> hashTable;
	std::vector<std::pair<int, std::string>> result;

	std::ifstream infile(in, std::ios::binary);
	if (!infile) {
		std::cout << "File not open!";
		return 0;
	}

	infile.seekg(0, std::ios::end);
	size_t size = infile.tellg();
	std::string data;
	data.resize(size);
	infile.seekg(0, std::ios::beg);
	infile.read(&data[0], size);

	std::string tmp;

	for (char ch : data) {
		if (ch >= 'a' && ch <= 'z') {
			tmp += ch;
			continue;
		}
		if (ch >= 'A' && ch <= 'Z') {
			tmp += tolower(ch);
			continue;
		}
		if (tmp.size() != 0) {
			++hashTable[tmp];
			tmp.clear();
		}
	}

	result.reserve(hashTable.size());

	for (const auto& pair : hashTable) {
		result.emplace_back(pair.second, pair.first);
	}

	std::sort(result.begin(), result.end(), [](const auto& lhs, const auto& rhs) {
		if (lhs.first != rhs.first) {
			return lhs.first > rhs.first;
		}
		return lhs.second < rhs.second;
	});

	std::ofstream fout(out);
	for (const auto& pair : result) {
		fout << pair.first << ' ' << pair.second << '\n';
	}

	return 0;
}


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

bool writeFile(
	const std::string& filename,
	const std::vector<std::vector<std::string>>& data,
	bool append = true
);

std::vector<std::vector<std::string>> readFile(const std::string& filename, int colNumber = -1, const std::string& colValue = "");

bool updateFile(
	const std::string& filename,
	size_t matchColumnIndex,
	const std::string& matchValue,
	const std::vector<std::string>& newRow
);

bool deleteRowFile(
	const std::string& filename,
	size_t matchColumnIndex,
	const std::string& matchValue
);

void printTable(const std::vector<std::vector<std::string>>& data);

#endif
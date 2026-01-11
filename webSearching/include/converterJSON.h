#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../include/json.hpp"
#include <algorithm>

class ConverterJSON
{
public:
	ConverterJSON::ConverterJSON() {
		ifstream file("../jsonFiles/config.json");
		if (!file.is_open())
			throw runtime_error("config file is missing");
		file >> _config;
		file.close();
	}

	std::vector<std::string> getTextDocuments() const;

	int getResponsesLimit() const;

	std::vector<std::string> getRequests() const;

	void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);

private:
	nlohmann::json _config;
};
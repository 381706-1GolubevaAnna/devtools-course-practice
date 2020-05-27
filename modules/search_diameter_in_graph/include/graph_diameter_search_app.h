// Copyright 2020 Golubeva Anna

#ifndef MODULES_SALARY_INCLUDE_GRAPH_DIAMETER_SEARCH_APP_H_
#define MODULES_SALARY_INCLUDE_GRAPH_DIAMETER_SEARCH_APP_H_

#include <string>
#include <iostream>
#include "include/graph_diameter_search.h"

class GraphApp {
 public:
    GraphApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
	int parseValue(const std::string& data);
	std::string message_;
	Graph graph;
};

#endif  // MODULES_SALARY_INCLUDE_GRAPH_DIAMETER_SEARCH_APP_H_

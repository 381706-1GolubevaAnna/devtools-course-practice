// Copyright 2020 Golubeva Anna

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "include/graph_diameter_search_app.h"

int GraphApp::ParseValue(const char* data) {
 int number = 0;
 try {
        number = std::stoi(data);
    }
    catch(...) {
        throw std::string("Wrong format");
    }
	
  return number;
}

std::string GraphApp::operator()(int argc, const char** argv) {
  if (!validateNumOfArgs(argc, argv)) {
    return message_;
    }
  
  std::ostringstream stream;
  try {
	  int n = ParseValue(argv[1]);
	  Graph graph = graph(n);
	  int edges = argc - 2;
	  for (int i = 2; i < edges; i++) {
      graph.addEdge(ParseValue(argv[i], ParseValue(argv[i+1]));
	  }
	  stream << graph.diameterSearch();
    } 
    catch(std::string& str) {
        return str;
    }
  message_ = stream.str();

  return message_;
}

void GraphApp::help(const char* appname, const char* message) {
  message_=
	  std::string(message) +
	  "This is a graph diameter search application.\n\n"+
	  "Please provide arguments in the following format:\n\n"+
	  "  $ " + appname + " <number of vertices> " + "<first vertex of edge>" +
	  "<second vertex of edge>" + "..." +"\n\n" +
	  "Where <number of vertices> is a natural number\n" +
	  "<first vertex of edge> <first vertex of edge>, ... are natural numbers "+
	  "which set the edges of the graph\n.";
}

bool GraphApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } 
  int count = parseValue(argv[1]);
  if (argc > count*(count-1) + 2 || count <= 0 || (argc - 2)%2 != 0) {
    help(argv[0], "Wrong number of arguments.\n\n");
    return false;
  }
  return true;
}
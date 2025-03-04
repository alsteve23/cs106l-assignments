
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include<sstream>

std::string kYourName = "Steve Tene"; 




std::unordered_set<std::string> get_applicants(std::string filename) {
  std::string name;
  std::unordered_set<std::string> names_set;
  names_set.reserve(1000);
  std::ifstream file(filename);
  while(std::getline(file,name,'\n')){
    names_set.insert(name);
    
  };
  file.close();
  return names_set;
};

std::pair<std::string,std::string> split(std::string nombre){
  std::pair<std::string, std::string> separate_name;
  std::istringstream iss(nombre);
  iss >> separate_name.first >> separate_name.second;
  return separate_name;
};

std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  std::pair<std::string, std::string>aux= split(name);
  std::queue<const std::string*> result;
  for (auto i= students.begin();i!=students.end(); ++i) {
    std::pair<std::string, std::string> compr = split(*i);
    if(!compr.first.empty() && !compr.second.empty()){
      if(compr.first[0]==aux.first[0] && compr.second[0]==aux.second[0]){
        result.push(&(*i));  
      };
    };
  };

  return result;
};


std::string get_match(std::queue<const std::string*>& matches) {
  std::string res_2;
  int matchesLength=matches.size();
  std::string best_match=*matches.front();
  int div=2;

  if(!matches.empty()){
      int half= matchesLength/div;
      for(int i; i<half; ++i){  
        matches.pop();
        std::string best_match = *matches.front();
      };  
    std::cout<<best_match;
    return best_match;
    }else{
    return "NO MATCHES FOUND";
  };
};


#include "autograder/utils.hpp"

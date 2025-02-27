
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";


struct Course {
  std::string title;
  std::string  number_of_units;
  std::string quarter;
};


/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ifstream file(filename);
  std::string line;
  Course aux;
  std::getline(file,line);
  while(std::getline(file,line)){
    std::vector<std::string> row = split(line, ',');
    aux.title= row[0];
    aux.number_of_units=row[1];
    aux.quarter=row[2];
    courses.push_back(aux);
  };
};


/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream ofs(COURSES_OFFERED_PATH);
  if (ofs.is_open()){
    ofs<<"Title,Number of Units,Quarter"<<'\n';  
  };
  std::vector<Course> erasable_courses;
  for (Course& new_lines: all_courses){ 
    if (new_lines.quarter!="null"){
      ofs<< new_lines.title<<','<<new_lines.number_of_units<<','<<new_lines.quarter<<'\n';
      erasable_courses.push_back(new_lines);
    };
  };
  ofs.close();
  for(const Course& course: erasable_courses){
  delete_elem_from_vector(all_courses,course);
  };
}; 




/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream file_2(COURSES_NOT_OFFERED_PATH);
  file_2<<"Title,Number of Units,Quarter"<<'\n';
  for (const Course& sss: unlisted_courses){
    file_2<< sss.title<<','<<sss.number_of_units<<','<<sss.quarter<<'\n';
  };
  file_2.close();
};

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}

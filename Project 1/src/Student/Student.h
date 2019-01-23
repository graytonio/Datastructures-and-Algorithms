#include "../Person/Person.h"
#include "../Course/Course.h"

class Student : public Person {
private:
  uint32_t totalCreditHours;
  uint32_t numberOfCourses;
  uint32_t uid;
  double gpa;
  vector<Course> courses;
public:
  uint32_t getTotalCreditHours();
  void setTotalCreditHours(uint32_t totalCreditHours);

  uint32_t getNumberOfCourses();
  void setNumberOfCourses(uint32_t numberOfCourses);

  uint32_t getUID();
  void setUID(uint32_t uid);

  double getGPA();
  void setGPA(double gpa);

  vector<Course> getCourses();
  void setCourses(vector<Course> courses);

  void addCourse(Course newCourse);
  void deleteCourse(uint8_t index);
}

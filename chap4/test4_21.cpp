#include <iostream>
  #include <vector>

  using std::cin;
  using std::cout;
  using std::endl;
  using std::vector;
  using std::string;

  int main()
  {
      int grade = 0;
      string final_grade = " ";
      cin >> grade;
      // 只使用条件运算符
      //final_grade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass":"fail";

      if(grade >= 90 )
      {
          final_grade = "high pass";
      }
      else if (grade >= 75 )
      {
          final_grade = "pass";
      }
      else if (grade >= 60)
      {
          final_grade = "low pass";
      }
      else
      {
          final_grade = "fail";
      }
      cout << final_grade << endl;

      return 0;

    }

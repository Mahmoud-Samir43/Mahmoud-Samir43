#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

struct hospital {
  std::string name;
  int status;
};
const int spec{21},q{6};
hospital arr[spec][q];

int menu() {
  int i;
  while (true) {
    std::cout << "enter the choice number" << std::endl;
    std::cout << "1) add patient" << std::endl;
    std::cout << "2) print all patients in a specialization" << std::endl;
    std::cout << "3) get next patient" << std::endl;
    std::cout << "4) exit" << std::endl;

    std::cin >> i;
    if (std::cin.fail()) {
      std::cout << "enter numbers only" << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    if (i <= 0 || i >= 5) {
      std::cout << "Please enter a valid number" << std::endl;
      continue;
    }
    if (i < 5 && i > 0) {
      break;
    }

    return i;
  }
  
}

void add_patients() {
  static int c{0};
  int s;
  std::cout << "enter a patient's specialization, name and status" << std::endl;
  std::cin >> s;
  if (std::cin.fail()) {
    std::cout << "enter numbers only" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    add_patients();
  }
  if (s >= 21 || s <= 0) {
    std::cout << "choose a valid specialization next time" << std::endl;
    return;
  }
  if (arr[s][5].name != "") {
    std::cout << "can't take anymore patients" << std::endl;
    return;
  }
  if (arr[s][c].name != "") {
    c++;
    if (c > 5) {
      c = 0;
    }
  }

  do {
    std::cin >> arr[s][c].name >> arr[s][c].status;
    if (arr[s][c].status != 0 && arr[s][c].status != 1) {
      std::cout << "please enter a valid status either 0 normal or 1 emergency"
                << std::endl;
    }
  } while (arr[s][c].status != 0 && arr[s][c].status != 1);
}

void print() {
  int i;
  std::cout << "choose specialization" << std::endl;
  std::cin >> i;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    print();
  }
  for (int c = 0; c < 6; c++) {
    if (arr[i][c].name != "") {
      std::cout << " patient's name --> " << arr[i][c].name << " status --> "
                << arr[i][c].status << std::endl;
    }
  }
}

void get_patient() {
  int i;
  std::cout << "what specialization " << std::endl;
  std::cin >> i;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    get_patient();
  }
  std::cout<<"patient "<<arr[i][0].name<<" go see the doctor "<<std::endl;
  for (int d = 0;d < 6; d++) {
    arr[i][d].name = arr[i][d+1].name;
    arr[i][d].status = arr[i][d+1].status;
  }

}


void system() {
  while (true) {
    int z = menu();
    if (z == 1) {
      add_patients();
    }
    if (z == 2) {
      print();
    }
    if (z == 3) {
        get_patient();
    }
    if (z == 4) {
      break;
    }
  }
}
